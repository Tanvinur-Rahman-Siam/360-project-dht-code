#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  
  Serial.println("DHT Final");
 
  dht.begin();
}
void loop() {
  // Wait a few seconds between measurements.
  delay(500);

  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hif = dht.computeHeatIndex(f, h);

  float hih = dht.computeHeatIndex(f, h, false);

  Serial.println (h);

  Serial.println (t);
}
