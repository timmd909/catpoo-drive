#include "Platform4.h"

void Platform4::updateMotorSpeeds()
{
  updateMotorSpeed(_motors[0], MOTOR_0_ANGLE);
  updateMotorSpeed(_motors[1], MOTOR_1_ANGLE);
  updateMotorSpeed(_motors[2], MOTOR_2_ANGLE);
  updateMotorSpeed(_motors[3], MOTOR_3_ANGLE);
}

void Platform4::init()
{
  pinMode(MOTOR_0_DIR, OUTPUT);
  pinMode(MOTOR_0_STEP, OUTPUT);

  pinMode(MOTOR_1_DIR, OUTPUT);
  pinMode(MOTOR_1_STEP, OUTPUT);

  pinMode(MOTOR_2_DIR, OUTPUT);
  pinMode(MOTOR_2_STEP, OUTPUT);

  pinMode(MOTOR_3_DIR, OUTPUT);
  pinMode(MOTOR_3_STEP, OUTPUT);

  stop();
}
