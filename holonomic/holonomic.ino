/**
 * Main loop and callbacks for the holonomic drive
 */

#include <AccelStepper.h>
#include "pins.h"
#include "motors.h"

int stepCount = 0;
int destination = STEPS_PER_REVOLUTION;

void setup() {
  pinMode(MOTOR_1_PIN_1, OUTPUT);
  pinMode(MOTOR_1_PIN_2, OUTPUT);
  pinMode(MOTOR_1_PIN_3, OUTPUT);
  pinMode(MOTOR_1_PIN_4, OUTPUT);

  pinMode(MOTOR_2_PIN_1, OUTPUT);
  pinMode(MOTOR_2_PIN_2, OUTPUT);
  pinMode(MOTOR_2_PIN_3, OUTPUT);
  pinMode(MOTOR_2_PIN_4, OUTPUT);

  pinMode(MOTOR_3_PIN_1, OUTPUT);
  pinMode(MOTOR_3_PIN_2, OUTPUT);
  pinMode(MOTOR_3_PIN_3, OUTPUT);
  pinMode(MOTOR_3_PIN_4, OUTPUT);

  pinMode(MOTOR_4_PIN_1, OUTPUT);
  pinMode(MOTOR_4_PIN_2, OUTPUT);
  pinMode(MOTOR_4_PIN_3, OUTPUT);
  pinMode(MOTOR_4_PIN_4, OUTPUT);

  leftStepper.setMinPulseWidth(50);
  leftStepper.setMaxSpeed(MAX_SPEED);
  leftStepper.setSpeed(MAX_SPEED);
  leftStepper.setAcceleration(MAX_ACCELERATION);

  frontStepper.setMinPulseWidth(50);
  frontStepper.setMaxSpeed(MAX_SPEED);
  frontStepper.setSpeed(MAX_SPEED);
  frontStepper.setAcceleration(MAX_ACCELERATION);

  rightStepper.setMinPulseWidth(50);
  rightStepper.setMaxSpeed(MAX_SPEED);
  rightStepper.setSpeed(MAX_SPEED);
  rightStepper.setAcceleration(MAX_ACCELERATION);

  backStepper.setMinPulseWidth(50);
  backStepper.setMaxSpeed(MAX_SPEED);
  backStepper.setSpeed(MAX_SPEED);
  backStepper.setAcceleration(MAX_ACCELERATION);

  steppers.addStepper(leftStepper);
  steppers.addStepper(frontStepper);
  steppers.addStepper(rightStepper);
  steppers.addStepper(backStepper);

}

void move(long positions[])
{
  resetAllSteppers();
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
}

void loop() { 
//  long test[] = {STEPS_PER_REVOLUTION, STEPS_PER_REVOLUTION, STEPS_PER_REVOLUTION, STEPS_PER_REVOLUTION};
//  move(test);

  long distance = STEPS_PER_REVOLUTION * 2;
  
  long moveForward[] =  {0, -distance , 0,  distance};
  long moveBackward[] = {0,  distance , 0, -distance};
  long moveLeft[] =  {-distance , 0,  distance , 0};
  long moveRight[] = { distance , 0, -distance , 0};
  long moveForwardAndLeft[] =   {-distance , -distance ,  distance ,  distance };
  long moveForwardAndRight[] =  { distance , -distance , -distance ,  distance };
  long moveBackwardAndRight[] = { distance ,  distance , -distance , -distance };
  long moveBackwardAndLeft[] =  {-distance ,  distance ,  distance , -distance };

   move(moveForward);
   
   move(moveForwardAndLeft);
   move(moveBackwardAndRight);
   
   move(moveRight);
   
   move(moveForwardAndRight);
   move(moveBackwardAndLeft);
   
   move(moveBackward);

   move(moveBackwardAndRight);
   move(moveForwardAndLeft);

   move(moveLeft);
   
   move(moveBackwardAndLeft);
   move(moveForwardAndRight);

}
