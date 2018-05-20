#ifndef __CATPOO_MOTORS_H__
#define __CATPOO_MOTORS_H__

#include <AccelStepper.h>
#include <MultiStepper.h>

#define PULSE_MIN_WIDTH 5
#define STEPS_PER_REVOLUTION 200
#define MAX_SPEED 250
#define MAX_ACCELERATION 250
#define MAX_DISTANCE 10000

namespace Motors
{
  extern MultiStepper steppers;
  extern AccelStepper flStepper;
  extern AccelStepper frStepper;
  extern AccelStepper brStepper;
  extern AccelStepper blStepper;

  void init();

  /**
   * Reset the internal position
   */
  void reset();

  void loop();

  /**
   * Commit to letting the motors run until they reach their
   * destination, no matter how far away that could be.
   *
   * Use sparingly.
   */
  void commit();

  void setSpeed(int speed);
  void setMaxSpeed(int speed);
  void setAcceleration(int accel);

  // /**
  //  * Begin moving in a particular direction. Speed is indicated by the
  //  * @param xDistance Positive values => right. Negative values => left.
  //  * @param yDistance Positive values => forward. Negative values => backwards,
  //  */
  // void move(long x, long y);
  //
  // /**
  //  * Rotate at a particular speed
  //  */
  // void turn(long speed);

  /**
   * How many units to move along the x and y axis
   * @param xDistance Positive values => right. Negative values => left.
   * @param yDistance Positive values => forward. Negative values => backwards,
   */
  void translate(long xDistance, long yDistance);

  /**
   * Number of units to rotate.
   *
   * Note: Currently this doesn't take into account the wheels diameter or
   * distance apart. It's how many steps to take instead... for now.
   *
   * @param distance Positive => counterclockwise. Negative => clockwise.
   */
  void rotate(long distance);
}

#endif
