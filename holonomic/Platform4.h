#ifndef __CATPOO_PLATFORM3_H__
#define __CATPOO_PLATFORM3_H__

#include "Platform.h"
#include "pins.h"

/**
 * 3 Wheel Platform with wheels offset 120° of each other.
 */
class Platform4 : public Platform
{
public:
  static const int NUM_MOTORS = 4;

  static const float MOTOR_0_ANGLE = 45.0f * (M_PI/180.0f);
  static const float MOTOR_1_ANGLE = 135.0f * (M_PI/180.0f);
  static const float MOTOR_2_ANGLE = 225.0f * (M_PI/180.0f);
  static const float MOTOR_3_ANGLE = 315.0f * (M_PI/180.0f);;

protected:
  Motor _motors[NUM_MOTORS];
  void updateMotorSpeeds();

public:
  void init();

};

#endif
