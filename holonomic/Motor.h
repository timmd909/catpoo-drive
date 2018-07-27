#ifndef __CATPOO_MOTOR_H__
#define __CATPOO_MOTOR_H__

#include <AccelStepper.h>

class Motor
{
  // Tune these as necessary for your motors. The code currently
  // assumes you're using compatible motors and such.
public:
  static const int MAX_SPEED = 250;
  static const int PULSE_MIN_WIDTH = 5;
  static const int STEPS_PER_REVOLUTION = 200;
  static const int MAX_ACCELERATION = 100;

protected:

  AccelStepper *_stepper;

  int _angle;
  int _speed;

  int _stepPin;
  int _directionPin;

public:

  Motor();
  Motor(int stepPin, int directionPin);
  ~Motor();

  void setSpeed(int speed);
  int getSpeed();
  void stop();
};

#endif
