// WiFi
#define WIFI_SSID     "wifi_name" // Add wifi name
#define WIFI_PASSWORD "wifi_password" // Add wifi passowrd

#define ID "sourdough" // Add unique name for this sensor
#define INTERVAL 60

#define DHTPIN 32    // Which pin is DHT 11 connected to
#define DHTTYPE DHT11 // Type DHT 11

#define ULTRASONIC_PIN_TRIG 4 // Which pin is HC-SR04's trig connected to
#define ULTRASONIC_PIN_ECHO 5 // Which pin is HC-SR04's echo connected to

#define INFLUX_HOST "127.0.0.1" // Influx host
#define INFLUX_PORT 8086 // Influx port
#define INFLUX_DB "arduino" // Influx database that we set up for this host
