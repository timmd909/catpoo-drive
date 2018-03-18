//#include <AccelStepper.h>
//
#include "Motors.h"
#include "pins.h"

namespace Motors
{
	const int PULSE_MIN_WIDTH = 50;
	const int STEPS_PER_REVOLUTION = 1025;
	const int MAX_SPEED = 500;
	const int MAX_ACCELERATION = 10;

//	MultiStepper steppers = MultiStepper();
//	AccelStepper leftStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_LEFT_STEP_PIN,  MOTOR_LEFT_DIR_PIN);
//	AccelStepper frontStepper = AccelStepper(AccelStepper::DRIVER, MOTOR_FRONT_STEP_PIN, MOTOR_FRONT_DIR_PIN);
//	AccelStepper rightStepper = AccelStepper(AccelStepper::DRIVER, MOTOR_RIGHT_STEP_PIN, MOTOR_RIGHT_DIR_PIN);
//	AccelStepper backStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_BACK_STEP_PIN,  MOTOR_BACK_DIR_PIN);

	void init()
	{
		Serial.println("MOTORS: INIT");

//    pinMode(MOTOR_LEFT_STEP_PIN,  OUTPUT);
//    pinMode(MOTOR_LEFT_DIR_PIN,   OUTPUT);
//    pinMode(MOTOR_FRONT_STEP_PIN, OUTPUT);
//    pinMode(MOTOR_FRONT_DIR_PIN,  OUTPUT);
//    pinMode(MOTOR_RIGHT_STEP_PIN, OUTPUT);
//    pinMode(MOTOR_RIGHT_DIR_PIN,  OUTPUT);
//    pinMode(MOTOR_BACK_STEP_PIN,  OUTPUT);
//    pinMode(MOTOR_BACK_DIR_PIN,   OUTPUT);

    //	  leftStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
    //	  leftStepper.setMaxSpeed(MAX_SPEED);
    //	  leftStepper.setSpeed(MAX_SPEED);
    //	  leftStepper.setAcceleration(MAX_ACCELERATION);
    //
    //	  frontStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
    //	  frontStepper.setMaxSpeed(MAX_SPEED);
    //	  frontStepper.setSpeed(MAX_SPEED);
    //	  frontStepper.setAcceleration(MAX_ACCELERATION);
    //
    //	  rightStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
    //	  rightStepper.setMaxSpeed(MAX_SPEED);
    //	  rightStepper.setSpeed(MAX_SPEED);
    //	  rightStepper.setAcceleration(MAX_ACCELERATION);
    //
    //	  backStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
    //	  backStepper.setMaxSpeed(MAX_SPEED);
    //	  backStepper.setSpeed(MAX_SPEED);
    //	  backStepper.setAcceleration(MAX_ACCELERATION);
    //
    //	  steppers.addStepper(leftStepper);
    //	  steppers.addStepper(frontStepper);
    //	  steppers.addStepper(rightStepper);
    //	  steppers.addStepper(backStepper);
    //
    //		reset();
  }
//
//	void powerOff()
//	{
////    digitalWrite(MOTOR_LEFT_STEP_PIN,  LOW);
////    digitalWrite(MOTOR_LEFT_DIR_PIN,   LOW);
////    digitalWrite(MOTOR_FRONT_STEP_PIN, LOW);
////    digitalWrite(MOTOR_FRONT_DIR_PIN,  LOW);
////    digitalWrite(MOTOR_RIGHT_STEP_PIN, LOW);
////    digitalWrite(MOTOR_RIGHT_DIR_PIN,  LOW);
////    digitalWrite(MOTOR_BACK_STEP_PIN,  LOW);
////    digitalWrite(MOTOR_BACK_DIR_PIN,   LOW);
//	}
//
//	void reset()
//	{
////		leftStepper.setCurrentPosition(0);
////		frontStepper.setCurrentPosition(0);
////		rightStepper.setCurrentPosition(0);
////		backStepper.setCurrentPosition(0);
////
////		powerOff();
//	}
//
//	void commit()
//	{
////		Motors::steppers.runSpeedToPosition();
//	}
//
//	void loop()
//	{
////		steppers.run();
//	}
//
//	void move(long xDistance, long yDistance)
//	{
////		reset();
////
////		long positions[] = {-yDistance, -xDistance, yDistance, xDistance};
////
////		steppers.moveTo(positions);
//	}
//
//	void rotate(long distance)
//	{
////		reset();
////
////		long positions[] = {distance, distance, distance, distance};
////		steppers.moveTo(positions);
//	}

}
