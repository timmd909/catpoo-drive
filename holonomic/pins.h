//
// I/O Pin Information
//
#ifndef __CATPOO_PINS_H__
#define __CATPOO_PINS_H__

#include <Arduino.h>

#define MOTOR_0_DIR   4
#define MOTOR_0_STEP  5

#define MOTOR_1_DIR   6
#define MOTOR_1_STEP  7

#define MOTOR_2_DIR   8
#define MOTOR_2_STEP  9

#define MOTOR_3_DIR   10
#define MOTOR_3_STEP  11

// command line compilation issue workaround:
#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#endif
