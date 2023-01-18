#include <Wire.h>
#include <AHT10.h>


// Connect Vin to 3-5VDC
// Connect GND to ground
// Connect SCL to I2C clock pin (A5 on UNO)
// Connect SDA to I2C data pin (A4 on UNO)

AHT10 myAHT10(0x38);


void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("AHT10 test");

  if (!myAHT10.begin()) {
    Serial.println("Couldn't find sensor!");
    while (1);
  }
}

void loop() {
    float temp = myAHT10.readTemperature();
    float rel_hum = myAHT10.readHumidity();
    Serial.print("Temp: "); Serial.print(temp); Serial.print(" C");
    Serial.print("\t\t");
    Serial.print("Humidity: "); Serial.print(rel_hum); Serial.println(" \%");
    delay(500);
}
