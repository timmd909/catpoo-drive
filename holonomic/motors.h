#ifndef __CATPOO_MOTORS_H__
#define __CATPOO_MOTORS_H__

#include <AccelStepper.h>
#include <MultiStepper.h>

#define STEPS_PER_REVOLUTION 2048
// #define MAX_SPEED 0.5
#define MAX_SPEED 1000
#define MAX_ACCELERATION 100

extern MultiStepper steppers;
extern AccelStepper leftStepper;
extern AccelStepper frontStepper;
extern AccelStepper rightStepper;
extern AccelStepper backStepper;

void resetAllSteppers();

#endif
