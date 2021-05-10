#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial externalDevice(2, 3);

void setup()
{
  Serial.begin(9600);
  externalDevice.begin(9600);
}

void loop()
{
  if (externalDevice.available())
  {
    Serial.write(externalDevice.read());
  }
  if (Serial.available())
  {
    externalDevice.print(Serial.read());
  }
}