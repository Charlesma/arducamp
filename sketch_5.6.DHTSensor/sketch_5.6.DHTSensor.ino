#include <DHT.h>
 
#define DHTTYPE DHT11 // DHT11 or DHT22 or DHT21
 
int HUMITTEMP_IN = 2;
 
DHT dht(HUMITTEMP_IN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
 
  dht.begin();
}
 
void loop() {
  delay(2000);
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Fail to read from DHT sensor!");
  }
  else {
    Serial.print(", humidity:");
    Serial.print(h);
    Serial.print("temperature:");
    Serial.print(t);
    Serial.println();
  }
}
