#ifndef __CATPOO_PLATFORM_H__
#define __CATPOO_PLATFORM_H__

#include <AccelStepper.h>
#include <MultiStepper.h>

#include "Motor.h"

class Platform
{
public:
  /**
   * Max speed the platform can move in a particular direction.
   * The individual motors may need to go above this to match
   * speed while rotating.
   */
  static const int MAX_SPEED = 200;
  static const int NUM_MOTORS = 0;

private:
  float _lastBearing;
  float _lastVX;
  float _lastVY;

protected:
  /**
   * X velocity (positive = right)
   */
  int _vX;

  /**
   * Y velocity (positive = forwards)
   */
  int _vY;

  /**
   * Z-axis Rotation speed (negative turns right, positive turns left)
   */
  int _rot;

  /**
   * 0 = do not decay. 1 = immediately stop after the next tick.
   */
  float _decayRate;

  /**
   * Update all the motor speeds based on the desired velocity
   */
  void updateMotorSpeeds();

  void updateMotorSpeed(Motor &motor, const int angle);

  /**
   * @return The bearing angle of the X and Y velocities. 0 = right,
   * π/2 = forward, π = left, 3π/2 = backwards
   */
  float calculateBearing();

public:
  Platform();
  ~Platform();

  /**
   * Call once to initialize the output pins properly
   */
  void init();

  /**
   * Call this function once per main loop.
   */
  void update();

  void setDecayRate(float decayRate);
  float getDecayRate();

  /**
   * @param xSpeed   Speed the platform should move laterally. Postive values
   * move right. Negative values move left.
   * @param ySpeed   Speed the platform should move forward for positive values,
   * and backwards for negative values.
   * @param rotation Speed the platform should rotate around the Z axis.
   * Positive values turn left, and negative values turn the platform right.
   */
  void setVelocity(const int xSpeed, const int ySpeed, const int rotation);

  //
  // Simple command shortcuts
  //
  void forward(const int speed);
  void backward(const int speed);
  void left(const int speed);
  void right(const int speed);
  void turn(const int speed);
  void stop();

};

#endif
