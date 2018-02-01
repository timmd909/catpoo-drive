#include <AccelStepper.h>

#include "Motors.h"
#include "pins.h"

namespace Motors
{
	const int PULSE_MIN_WIDTH = 50;
	const int STEPS_PER_REVOLUTION = 4095;
	const int MAX_SPEED = 666;
	const int MAX_ACCELERATION = 1000;

	MultiStepper steppers = MultiStepper();
	AccelStepper leftStepper = AccelStepper(AccelStepper::HALF4WIRE,  MOTOR_1_PIN_1, MOTOR_1_PIN_2, MOTOR_1_PIN_3, MOTOR_1_PIN_4);
	AccelStepper frontStepper = AccelStepper(AccelStepper::HALF4WIRE, MOTOR_2_PIN_1, MOTOR_2_PIN_2, MOTOR_2_PIN_3, MOTOR_2_PIN_4);
	AccelStepper rightStepper = AccelStepper(AccelStepper::HALF4WIRE, MOTOR_3_PIN_1, MOTOR_3_PIN_2, MOTOR_3_PIN_3, MOTOR_3_PIN_4);
	AccelStepper backStepper = AccelStepper(AccelStepper::HALF4WIRE,  MOTOR_4_PIN_1, MOTOR_4_PIN_2, MOTOR_4_PIN_3, MOTOR_4_PIN_4);

	void init()
	{
		Serial.println("MOTORS: INIT");

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

	  leftStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
	  leftStepper.setMaxSpeed(MAX_SPEED);
	  leftStepper.setSpeed(MAX_SPEED);
	  leftStepper.setAcceleration(MAX_ACCELERATION);

	  frontStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
	  frontStepper.setMaxSpeed(MAX_SPEED);
	  frontStepper.setSpeed(MAX_SPEED);
	  frontStepper.setAcceleration(MAX_ACCELERATION);

	  rightStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
	  rightStepper.setMaxSpeed(MAX_SPEED);
	  rightStepper.setSpeed(MAX_SPEED);
	  rightStepper.setAcceleration(MAX_ACCELERATION);

	  backStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
	  backStepper.setMaxSpeed(MAX_SPEED);
	  backStepper.setSpeed(MAX_SPEED);
	  backStepper.setAcceleration(MAX_ACCELERATION);

	  steppers.addStepper(leftStepper);
	  steppers.addStepper(frontStepper);
	  steppers.addStepper(rightStepper);
	  steppers.addStepper(backStepper);

		reset();
	}

	void powerOff()
	{
		digitalWrite(MOTOR_1_PIN_1, LOW);
		digitalWrite(MOTOR_1_PIN_2, LOW);
		digitalWrite(MOTOR_1_PIN_3, LOW);
		digitalWrite(MOTOR_1_PIN_4, LOW);

		digitalWrite(MOTOR_2_PIN_1, LOW);
		digitalWrite(MOTOR_2_PIN_2, LOW);
		digitalWrite(MOTOR_2_PIN_3, LOW);
		digitalWrite(MOTOR_2_PIN_4, LOW);

		digitalWrite(MOTOR_3_PIN_1, LOW);
		digitalWrite(MOTOR_3_PIN_2, LOW);
		digitalWrite(MOTOR_3_PIN_3, LOW);
		digitalWrite(MOTOR_3_PIN_4, LOW);

		digitalWrite(MOTOR_4_PIN_1, LOW);
		digitalWrite(MOTOR_4_PIN_2, LOW);
		digitalWrite(MOTOR_4_PIN_3, LOW);
		digitalWrite(MOTOR_4_PIN_4, LOW);
	}

	void reset()
	{
		Serial.println("MOTORS: RESET");

		leftStepper.setCurrentPosition(0);
		frontStepper.setCurrentPosition(0);
		rightStepper.setCurrentPosition(0);
		backStepper.setCurrentPosition(0);

		powerOff();
	}

	void loop()
	{
		// step the motors here
	}

	void move(long xDistance, long yDistance)
	{
		Serial.println(String("MOTORS: MOVE ") + xDistance + String(" ") + yDistance);
		reset();

		long positions[] = {-yDistance, -xDistance, yDistance, xDistance};

		steppers.moveTo(positions);
		steppers.runSpeedToPosition();
	}

	void rotate(long distance)
	{
		Serial.println(String("MOTORS: ROTATE ") + distance);
		reset();

		long positions[] = {distance, distance, distance, distance};
		steppers.moveTo(positions);
		steppers.runSpeedToPosition();
	}
}
