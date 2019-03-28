#ifndef __CATPOO_MOTOR_H__
#define __CATPOO_MOTOR_H__

#include <AccelStepper.h>

class Motor
{
protected:

  AccelStepper *_stepper;

  float _angle;
  int _speed;

  int _stepPin;
  int _directionPin;

public:
  Motor(float angle, int directionPin, int stepPin);
  ~Motor();

  void setSpeed(int speed);
  int getSpeed();

  // void setAngle(float angle);
  float getAngle();

  void stop();

  void update();
};

#endif
