/**
 * Main loop and callbacks for the holonomic drive
 */

#include <AccelStepper.h>
#include "Comms.h"
#include "Motors.h"
#include "Tests.h"
#include "pins.h"

int stepCount = 0;
int destination = Motors::STEPS_PER_REVOLUTION;

void setup()
{
	// Wait 5 seconds to give Arduino IDE time to upload new sketches
	// before we open the serial port.
	delay(5000);

  Comms::init();
  Motors::init();

  Serial.println("ME: HOW ARE YOU NOW?");
}


void loop()
{
	Comms::loop();
	Motors::loop();

  delay(1);
}
