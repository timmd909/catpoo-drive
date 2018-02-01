#include <HardwareSerial.h>
#include "Motors.h"
#include "tests.h"

extern Serial_ Serial;

namespace Tests
{
  // Spin the left, front, right, and back wheels 1 revolution in order
  // clockwise 1 revolution, then 1 revolution counterclockwise.
  void wheel()
  {
    Serial.println("TEST: WHEEL");

    Motors::reset();

    int distance = Motors::STEPS_PER_REVOLUTION / 4;

    Motors::leftStepper.runToNewPosition(distance);
    Motors::leftStepper.runToNewPosition(0);

    Motors::frontStepper.runToNewPosition(distance);
    Motors::frontStepper.runToNewPosition(0);

    Motors::rightStepper.runToNewPosition(distance);
    Motors::rightStepper.runToNewPosition(0);

    Motors::backStepper.runToNewPosition(distance);
    Motors::backStepper.runToNewPosition(0);
  }

  void dance()
  {
    Serial.println("TEST: DANCE");

    long distance = Motors::STEPS_PER_REVOLUTION / 8;

    Motors::rotate(distance * -2);
    Motors::rotate(distance *  2);

    //
    // straight directions
    //
    Motors::move(0, distance);
    Motors::move(0, -distance * 2);
    Motors::move(0, distance);

    //
    // angled movements
    //
    Motors::move(-distance, distance);
    Motors::move(distance, -distance);

    Motors::move(distance, distance);
    Motors::move(-distance, -distance);

    Motors::move(distance, -distance);
    Motors::move(-distance, distance);

    Motors::move(-distance, -distance);
    Motors::move(distance, distance);
  }

}
