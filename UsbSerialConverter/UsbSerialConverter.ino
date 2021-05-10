#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial externalDevice(2, 3);
byte incomingByte;

void setup()
{
  Serial.begin(9600);
  externalDevice.begin(9600);
}

void loop()
{
  if (externalDevice.available())
  {
    incomingByte = externalDevice.read();
    Serial.write(incomingByte);
  }
  if (Serial.available())
  {
    incomingByte = Serial.read();
    externalDevice.print(incomingByte);
  }
}