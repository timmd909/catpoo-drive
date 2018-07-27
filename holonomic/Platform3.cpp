#include "Platform3.h"

void Platform3::updateMotorSpeeds()
{
  updateMotorSpeed(_motors[0], MOTOR_0_ANGLE);
  updateMotorSpeed(_motors[1], MOTOR_1_ANGLE);
  updateMotorSpeed(_motors[2], MOTOR_2_ANGLE);
}

void Platform3::init()
{
  pinMode(MOTOR_0_DIR, OUTPUT);
  pinMode(MOTOR_0_STEP, OUTPUT);

  pinMode(MOTOR_1_DIR, OUTPUT);
  pinMode(MOTOR_1_STEP, OUTPUT);

  pinMode(MOTOR_2_DIR, OUTPUT);
  pinMode(MOTOR_2_STEP, OUTPUT);

  stop();
}
