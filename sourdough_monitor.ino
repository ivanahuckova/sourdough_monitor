#include <Arduino.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <HTTPClient.h>

#include <DHT.h>
#include <HCSR04.h>

#include "config.h"

// NTP Client
WiFiUDP ntpUDP;
NTPClient ntpClient(ntpUDP);

// DHT Sensor
DHT dht(DHTPIN, DHTTYPE);

// Ultrasonic Sensor
UltraSonicDistanceSensor distanceSensor(ULTRASONIC_PIN_TRIG, ULTRASONIC_PIN_ECHO);  // Initialize sensor that uses digital pins 4 and 5

// Influx Client
HTTPClient httpInflux;

// Function to set up the connection to the WiFi AP
void setupWiFi() {
  Serial.print("Connecting to '");
  Serial.print(WIFI_SSID);
  Serial.print("' ...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("connected");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  randomSeed(micros());
}

// Function to submit metrics to locally run Influx
void submitHostedInflux(unsigned long ts, float cels, float hum, float hic, long dist) {
  
  // Build body
  String body = String("temperature value=") + cels + " " + ts + "\n" +
    "humidity value=" + hum + " " + ts + "\n" +
    "index value=" + hic + " " + ts + "\n" +
    "distance value=" + dist + " " + ts;

  // Submit POST request via HTTP
  httpInflux.begin(String("https://") + INFLUX_HOST + "/api/v2/write?org=" + INFLUX_ORG_ID + "&bucket=" + INFLUX_DB + "&precision=s", ROOT_CA);
  httpInflux.addHeader("Authorization", INFLUX_TOKEN);

  int httpCode = httpInflux.POST(body);
  if (httpCode > 0) {
    Serial.printf("Influx [HTTPS] POST...  Code: %d  Response: ", httpCode);
   Serial.println();
  } else {
    Serial.printf("Influx [HTTPS] POST... Error: %s\n", httpInflux.errorToString(httpCode).c_str());
  }

  httpInflux.end();
}


//  Function called at boot to initialize the system
void setup() {
  // Start the serial output at 115,200 baud
  Serial.begin(115200);

  // Connect to WiFi
  setupWiFi();

  // Initialize a NTPClient to get time
  ntpClient.begin();

  // Start the DHT sensor
  dht.begin();
}


// Function called in a loop to read temp/humidity and submit them to hosted metrics
void loop() {
  // Reconnect to WiFi if required
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.disconnect();
    yield();
    setupWiFi();
  }

  // Update time via NTP if required
  while(!ntpClient.update()) {
    yield();
    ntpClient.forceUpdate();
  }

  // Get current timestamp
  unsigned long ts = ntpClient.getEpochTime();

  // Read humidity
  float hum = dht.readHumidity();
  yield();

  // Read temperature as Celsius (the default)
  float cels = dht.readTemperature();
  yield();

  double dist = distanceSensor.measureDistanceCm();

  // Check if any reads failed and exit early (to try again).
  if (isnan(hum) || isnan(cels) || isnan(dist) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(cels, hum, false);

  yield();
  submitHostedInflux(ts, cels, hum, hic, dist);
  

  // wait 60s, then do it again
  delay(60 * 1000);
}
