#include "DHT.h"
#define DHTTYPE DHT11
#define dht_pin D1
DHT dht(dht_pin,DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if(isnan(t)){
    Serial.println("Sensor tidak terbaca");
    return;
    }
  Serial.print("Suhu : ");
  Serial.print(t);
  Serial.print(" - Kelembapan : ");
  Serial.println(h);
  delay(1000);
}
