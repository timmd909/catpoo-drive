#include "config.h"

#include <Arduino.h>
#include <Wire.h>

namespace I2C
{
  void i2cRequest(int howMany)
  {
    char byte;

    Serial.print("RECEIVED INFO FROM I2C ");
    Serial.println(howMany);

    while (Wire.available()) {
      byte = Wire.read();
      Serial.print("Received: ");
      String str = String(byte);
      Serial.println(str);
    }
  }

  void init()
  {
    Serial.println("Initializing I2C");
    Wire.begin(I2C_ADDRESS);
    Wire.onRequest(i2cRequest);
  }
}
