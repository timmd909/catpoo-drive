#include "config.h"
#include "Platform3.h"

Platform3::Platform3()
{
  _motors = (AccelStepper*) malloc(sizeof(AccelStepper) * 3);
  AccelStepper *motor0 = new AccelStepper(AccelStepper::FULL4WIRE, MOTOR_0_STEP, MOTOR_0_DIR);
  AccelStepper *motor1 = new AccelStepper(AccelStepper::FULL4WIRE, MOTOR_1_STEP, MOTOR_1_DIR);
  AccelStepper *motor2 = new AccelStepper(AccelStepper::FULL4WIRE, MOTOR_2_STEP, MOTOR_2_DIR);
  _motors[0] = *motor0;
  _motors[1] = *motor1;
  _motors[2] = *motor2;
}

Platform3::~Platform3()
{
  free(_motors);
}
