// WiFi
#define WIFI_SSID     "your_wifi_name" // Add wifi name
#define WIFI_PASSWORD "your_wifi_password" // Add wifi passowrd

#define ID "sourdough" // Add unique name for this sensor
#define INTERVAL 60

#define DHTPIN 32    // Which pin is DHT 11 connected to
#define DHTTYPE DHT11 // Type DHT 11

#define ULTRASONIC_PIN_TRIG 4 // Which pin is HC-SR04's trig connected to
#define ULTRASONIC_PIN_ECHO 5 // Which pin is HC-SR04's echo connected to

#define INFLUX_HOST "your_influx_host" // Influx host (e.g. eu-central-1-1.aws.cloud2.influxdata.com)
#define INFLUX_ORG_ID "your_influx_org_id" // Org id
#define INFLUX_TOKEN "Token your_token" // Influx token
#define INFLUX_BUCKET "your_sourdough_bucket" // Influx bucket that we set up for this host


// How to get the Root CA cert:
// https://techtutorialsx.com/2017/11/18/esp32-arduino-https-get-request/

#define ROOT_CA "-----BEGIN CERTIFICATE-----" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexampleexampleexampleexampleexampleexampleexampleexamplee" \
"exampleexample" \
"-----END CERTIFICATE-----"
