/**
 * Main loop and callbacks for the holonomic drive
 */

#include <Arduino.h>
#include <Wire.h>
#include "holonomic.h"

#include "Commands.h"
#include "Platform3.h"
#include "Tests.h"

Platform3 platform;
// Platform4 platform;

namespace
{
  void i2cRequest()
  {
    Serial.println("i2c request ignored");
  }

  void i2cReceive(int numBytes)
  {
    while (Wire.available())
    {
      int nextByte = Wire.read();
      Commands::commandQueue.push(nextByte);
    }
  }
}

void setup()
{
  // Wait 2 seconds to give Arduino IDE time to upload new sketches
  // before we open the serial port.
  delay(5000);

  Serial.println("INITIALIZING");

  pinMode(LED_BUILTIN, OUTPUT);

  platform.init();

  Wire.begin(I2C_ADDR);
  Wire.onRequest(i2cRequest);
  Wire.onReceive(i2cReceive);

  Serial.println("INIT COMPLETE");
}

void loop()
{
  Commands::process();
  platform.update();
}
