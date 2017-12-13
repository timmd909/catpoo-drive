#ifndef __CATPOO_MOTORS_H__
#define __CATPOO_MOTORS_H__

#include <Stepper.h>

#define STEPS_PER_REVOLUTION 4095

extern Stepper leftStepper;
extern Stepper frontStepper;
extern Stepper rightStepper;
extern Stepper backStepper;

#endif
