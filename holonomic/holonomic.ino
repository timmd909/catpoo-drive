/**
 * Main loop and callbacks for the holonomic drive
 */

//#include <AccelStepper.h>
#include "Comms.h"
#include "Motors.h"
#include "Tests.h"
#include "pins.h"

void setup()
{
  // Wait 2 seconds to give Arduino IDE time to upload new sketches
  // before we open the serial port.
  delay(5000);

  Serial.println("INITIALIZING");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);

  Comms::init();
  Motors::init();

  Serial.println("INIT COMPLETE");
}


int count = 0;

void printValue(char *description, int value)
{
  int lowRes = value >> 7;
//  Serial.print(lowRes);
  int i;
  Serial.print("[");
  Serial.print(description);
  Serial.print(" ");
  for (i=0; i < lowRes; i++) {
    Serial.print("=");
  }
  for (; i < 8; i++) {
    Serial.print(" ");
  }
  Serial.print("]");
}

void loop()
{
  Motors::loop();
  Comms::loop();
}
