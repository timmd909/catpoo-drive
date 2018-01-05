#ifndef __CATPOO_MOTORS_H__
#define __CATPOO_MOTORS_H__

#include <AccelStepper.h>
#include <MultiStepper.h>

#define PULSE_MIN_WIDTH 50
#define STEPS_PER_REVOLUTION 4095 
// #define MAX_SPEED 0.5
#define MAX_SPEED 666
#define MAX_ACCELERATION 1000

extern MultiStepper steppers;
extern AccelStepper leftStepper;
extern AccelStepper frontStepper;
extern AccelStepper rightStepper;
extern AccelStepper backStepper;

void resetAllSteppers();
void move(long positions[]);

void rotate(long distance);

#endif
