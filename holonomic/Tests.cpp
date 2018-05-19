#include <HardwareSerial.h>
#include "Motors.h"
#include "Tests.h"

extern Serial_ Serial;

namespace Tests
{
  // Spin the left, front, right, and back wheels 1 revolution in order
  // clockwise 1 revolution, then 1 revolution counterclockwise.
  void wheel()
  {
    Motors::reset();

    int distance = Motors::STEPS_PER_REVOLUTION;

    Motors::flStepper.runToNewPosition(distance);
    Motors::flStepper.runToNewPosition(0);

    Motors::frStepper.runToNewPosition(distance);
    Motors::frStepper.runToNewPosition(0);

    Motors::brStepper.runToNewPosition(distance);
    Motors::brStepper.runToNewPosition(0);

    Motors::blStepper.runToNewPosition(distance);
    Motors::blStepper.runToNewPosition(0);

  }

  void dance()
  {
    long distance = Motors::STEPS_PER_REVOLUTION / 4;

    //
    // rotate a bit
    //
    Motors::rotate(distance * -1); Motors::commit();
    Motors::rotate(distance *  1); Motors::commit();

    //
    // straight directions
    //
    Motors::move(0, distance);      Motors::commit();
    Motors::move(0, -distance * 2); Motors::commit();
    Motors::move(0, distance);      Motors::commit();

    Motors::move(distance, 0);      Motors::commit();
    Motors::move(-distance * 2, 0);     Motors::commit();
    Motors::move(distance, 0);      Motors::commit();

    //
    // circle 
    //
    int angle, xdistance, ydistance;
    double angle_in_radians;
    for (angle = 0; angle < 360; angle += 10) {
      angle_in_radians= angle * M_PI / 180.0;
      xdistance = (int)(cos(angle_in_radians) * 20.0f);
      ydistance = (int)(sin(angle_in_radians) * 20.0f);
      Motors::move(xdistance, ydistance); Motors::commit();  
    }

    //
    // square 
    // 
    Motors::move(distance, 0); Motors::commit();
    
    Motors::move(0, distance); Motors::commit();
    Motors::move(-2 * distance, 0); Motors::commit();
    Motors::move(0, -2 * distance); Motors::commit();
    Motors::move(distance * 2, 0); Motors::commit();
    Motors::move(0, distance); Motors::commit();

    Motors::move(-1 * distance, 0); Motors::commit();

    //
    // angled movements
    //
    Motors::move(-distance, distance);  Motors::commit();
    Motors::move(distance, -distance);  Motors::commit();

    Motors::move(distance, distance);   Motors::commit();
    Motors::move(-distance, -distance); Motors::commit();

    Motors::move(distance, -distance);  Motors::commit();
    Motors::move(-distance, distance);  Motors::commit();

    Motors::move(-distance, -distance); Motors::commit();
    Motors::move(distance, distance);   Motors::commit();
  }


}

