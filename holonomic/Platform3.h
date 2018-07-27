#ifndef __CATPOO_PLATFORM3_H__
#define __CATPOO_PLATFORM3_H__

#include "Platform.h"
#include "pins.h"

/**
 * 3 Wheel Platform with wheels offset 120° of each other.
 */
class Platform3 : public Platform
{
public:
  static const int NUM_MOTORS = 3;

  static const float MOTOR_0_ANGLE = 180.0f * (M_PI/180.0f);
  static const float MOTOR_1_ANGLE = 300.0f * (M_PI/180.0f);
  static const float MOTOR_2_ANGLE = 60.0f * (M_PI/180.0f);

protected:
  Motor _motors[NUM_MOTORS];
  void updateMotorSpeeds();

public:
  void init();
};

#endif
