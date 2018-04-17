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
	extern AccelStepper flStepper;
	extern AccelStepper frStepper;
	extern AccelStepper brStepper;
	extern AccelStepper blStepper;

	void init();

	/**
	 * Reset the internal position 
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

