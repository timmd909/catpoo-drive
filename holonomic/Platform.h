#ifndef __CATPOO_PLATFORM_H__
#define __CATPOO_PLATFORM_H__

#include <AccelStepper.h>
#include <MultiStepper.h>

#include "LifeCycle.h"
#include "Motor.h"

class Platform : public LifeCycle
{
public:
  static const int NUM_MOTORS = 3;

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
   * @return The bearing angle of the X and Y velocities. 0 = right,
   * π/2 = forward, π = left, 3π/2 = backwards
   */
  float calculateBearing();

public:
  Platform();

  /**
   * Call once per main loop iteration to update the platform
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

  void stop();

};

#endif
