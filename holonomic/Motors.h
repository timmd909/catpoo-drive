#ifndef __CATPOO_MOTORS_H__
#define __CATPOO_MOTORS_H__

#include <AccelStepper.h>
#include <MultiStepper.h>

namespace Motors
{
	extern const int PULSE_MIN_WIDTH;
	extern const int STEPS_PER_REVOLUTION;
	extern const int MAX_SPEED;
	extern const int MAX_ACCELERATION;

	extern MultiStepper steppers;
	extern AccelStepper leftStepper;
	extern AccelStepper frontStepper;
	extern AccelStepper rightStepper;
	extern AccelStepper backStepper;

	void init();

	/**
	 * Reset the internal position and power off of all motors
	 */
	void reset();

	void loop();

	/**
	 * Commit to letting the motors run until they reach their
	 * destination, no matter how far away that could be.
	 *
	 * Use sparingly.
	 */
	void commit();

	/**
	 * Turn off power to the motor coils
	 */
	void powerOff();

	/**
	 * How many units to move along the x and y axis
	 * @param xDistance Positive values => right. Negative values => left.
	 * @param yDistance Positive values => forward. Negative values => backwards,
	 */
	void move(long xDistance, long yDistance);

	/**
	 * Number of units to rotate.
	 *
	 * Note: Currently this doesn't take into account the wheels diameter or
	 * distance apart. It's how many steps to take instead... for now.
	 *
	 * @param distance Positive => counterclockwise. Negative => clockwise.
	 */
	void rotate(long distance);
}

#endif
