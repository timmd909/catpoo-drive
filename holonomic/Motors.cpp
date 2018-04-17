#include <AccelStepper.h>
#include "Motors.h"
#include "pins.h"

namespace Motors
{
	const int PULSE_MIN_WIDTH = 2;
	const int STEPS_PER_REVOLUTION = 200;
	const int MAX_SPEED = 500;
	const int MAX_ACCELERATION = 50;

  const double SQRT2 = sqrt(2.0f);

	MultiStepper steppers = MultiStepper();
  AccelStepper flStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_FL_STEP, MOTOR_FL_DIR);
  AccelStepper frStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_FR_STEP, MOTOR_FR_DIR);
  AccelStepper blStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_BL_STEP, MOTOR_BL_DIR);
  AccelStepper brStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_BR_STEP, MOTOR_BR_DIR);

	void init()
	{
		Serial.println("MOTORS: INIT");

    flStepper.setMaxSpeed(MAX_SPEED);
    flStepper.setAcceleration(MAX_ACCELERATION );

    frStepper.setMaxSpeed(MAX_SPEED);
    frStepper.setAcceleration(MAX_ACCELERATION );
    
    blStepper.setMaxSpeed(MAX_SPEED);
    blStepper.setAcceleration(MAX_ACCELERATION );
    
    brStepper.setMaxSpeed(MAX_SPEED);
    brStepper.setAcceleration(MAX_ACCELERATION );
 
    pinMode(MOTOR_FL_STEP, OUTPUT);
    pinMode(MOTOR_FL_DIR,  OUTPUT);
    digitalWrite(MOTOR_FL_DIR,  LOW);
    digitalWrite(MOTOR_FL_STEP, LOW);
    
    pinMode(MOTOR_FR_STEP, OUTPUT);
    pinMode(MOTOR_FR_DIR,  OUTPUT);
    digitalWrite(MOTOR_FR_DIR,  LOW);
    digitalWrite(MOTOR_FR_STEP, LOW);

    pinMode(MOTOR_BR_STEP, OUTPUT);
    pinMode(MOTOR_BR_DIR,  OUTPUT);
    digitalWrite(MOTOR_BR_DIR,  LOW);
    digitalWrite(MOTOR_BR_STEP, LOW);

    pinMode(MOTOR_BL_STEP, OUTPUT);
    pinMode(MOTOR_BL_DIR,  OUTPUT);
    digitalWrite(MOTOR_BL_DIR,  LOW);
    digitalWrite(MOTOR_BL_STEP, LOW);
    
    steppers.addStepper(flStepper);
    steppers.addStepper(frStepper);
    steppers.addStepper(brStepper);
    steppers.addStepper(blStepper);

    Motors::reset();
    
  }

	void reset()
	{
		flStepper.setCurrentPosition(0);
		frStepper.setCurrentPosition(0);
		brStepper.setCurrentPosition(0);
		blStepper.setCurrentPosition(0);
	}

	void commit()
	{
		Motors::steppers.runSpeedToPosition();
	}

	void loop()
	{
		steppers.run();
	}

	void move(long xDistance, long yDistance)
	{
    double angle;

    reset();

    double fl_X, fr_X, bl_X, br_X; 
    fl_X = SQRT2 * xDistance;
    fr_X = SQRT2 * xDistance;
    br_X = SQRT2 * xDistance * -1.0f;
    bl_X = SQRT2 * xDistance * -1.0f;
        
    double fr_Y, fl_Y, bl_Y, br_Y; 
    fl_Y = SQRT2 * yDistance;
    fr_Y = SQRT2 * yDistance * -1.0f;
    br_Y = SQRT2 * yDistance * -1.0f;
    bl_Y = SQRT2 * yDistance;

		long positions[] = {
      (fl_X + fl_Y),
      (fr_X + fr_Y),
      (br_X + br_Y),
      (bl_X + bl_Y)
	  };
    
		steppers.moveTo(positions);
	}

	void rotate(long distance)
	{
		reset();

		long positions[] = {distance, distance, distance, distance};
		steppers.moveTo(positions);
	}

}

