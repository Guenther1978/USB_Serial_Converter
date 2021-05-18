#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial externalDevice(2, 3);

void setup()
{
  Serial.begin(9600);
  while(!Serial);
  externalDevice.begin(9600);
}

void loop()
{
  while (externalDevice.available())
  {
    Serial.write(externalDevice.read());
  }
  while (Serial.available())
  {
    externalDevice.print(Serial.read());
  }
}
