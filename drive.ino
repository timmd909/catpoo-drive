//
// DRIVE!
//
// My universal robot handling library
//

#include <Arduino.h>
#include "config.h"

void setup()
{
  // Wait a short bit to give Arduino IDE time to upload new sketches
  // before we open the serial port.
  delay(5000);

  Serial.println("INIT COMPLETE");
}


void loop()
{
  delay(1000);
  Serial.println("loop");
}
