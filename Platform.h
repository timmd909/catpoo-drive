#ifndef __DRIVE_PLATFORM_H_
#define __DRIVE_PLATFORM_H_

#include <AccelStepper.h>

/**
 * Abstract base platform class.
 *
 * This is intended to allow reusing the same API for holonimc platforms
 * having 3 or more motors.
 */
class Platform
{
protected:
  AccelStepper *_motors;

public:
  /**
   * Number of motors.
   */
  const int NUM_MOTORS = -1;

  Platform();
  ~Platform();

  /**
   * Step all motors that have steps due.
   *
   * Call this function as often as possible, and at least once
   * per step-time interval.
   */
  void run();

  /**
   * Stop all motors
   */
  void stop();

};

#endif
