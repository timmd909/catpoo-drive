#include "Motor.h"

Motor::Motor()
{
  _stepPin = 0;
  _directionPin = 0;

  _angle = 0;
  _speed = 0;

  _stepper = new AccelStepper(AccelStepper::DRIVER, _stepPin, _directionPin);
}

Motor::Motor(int stepPin, int directionPin)
{
  Motor();
  _directionPin = directionPin;
  _stepPin = stepPin;
}

Motor::~Motor()
{
  delete _stepper;
}

//
// Speed
//

void Motor::setSpeed(int speed)
{
  if (speed > MAX_SPEED) {
    speed = MAX_SPEED;
  } else if (speed < -MAX_SPEED) {
    speed = -MAX_SPEED;
  } else {
    _speed = speed;
  }
}

int Motor::getSpeed()
{
  return _speed;
}

void Motor::stop()
{
  setSpeed(0);
}
