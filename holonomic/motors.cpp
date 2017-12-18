#include <AccelStepper.h>

#include "motors.h"
#include "pins.h"

MultiStepper steppers = MultiStepper();
AccelStepper leftStepper = AccelStepper(AccelStepper::HALF4WIRE,  MOTOR_1_PIN_1, MOTOR_1_PIN_2, MOTOR_1_PIN_3, MOTOR_1_PIN_4);
AccelStepper frontStepper = AccelStepper(AccelStepper::HALF4WIRE, MOTOR_2_PIN_1, MOTOR_2_PIN_2, MOTOR_2_PIN_3, MOTOR_2_PIN_4);
AccelStepper rightStepper = AccelStepper(AccelStepper::HALF4WIRE, MOTOR_3_PIN_1, MOTOR_3_PIN_2, MOTOR_3_PIN_3, MOTOR_3_PIN_4);
AccelStepper backStepper = AccelStepper(AccelStepper::HALF4WIRE,  MOTOR_4_PIN_1, MOTOR_4_PIN_2, MOTOR_4_PIN_3, MOTOR_4_PIN_4);

void resetAllSteppers()
{
  leftStepper.setCurrentPosition(0);
  frontStepper.setCurrentPosition(0);
  rightStepper.setCurrentPosition(0);
  backStepper.setCurrentPosition(0);
}

