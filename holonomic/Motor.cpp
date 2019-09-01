// #include "Motor.h"
// #include "config.h"
//
// Motor::Motor(float angle, int stepPin, int directionPin)
// {
//   _angle = angle;
//   _speed = 0;
//
//   _directionPin = directionPin;
//   _stepPin = stepPin;
//
//   pinMode(_stepPin, OUTPUT);
//   pinMode(_directionPin, OUTPUT);
//
//   _stepper = new AccelStepper(AccelStepper::DRIVER, _stepPin, _directionPin);
//   _stepper->setMaxSpeed(MAX_SPEED);
//
//   Serial.print("Creating motor, angle = ");
//   Serial.println(_angle);
// }
//
// Motor::~Motor()
// {
//   // nothing here for now
//   return;
// }
//
// void Motor::update()
// {
//   _stepper->run();
// }
//
// //
// // Angle
// //
//
// // void Motor::setAngle(float angle)
// // {
// //    _angle = angle;
// // }
//
// float Motor::getAngle()
// {
//   return _angle;
// }
//
// //
// // Speed
// //
//
// void Motor::setSpeed(int speed)
// {
//   if (speed > MAX_SPEED) {
//     speed = MAX_SPEED;
//   } else if (speed < -MAX_SPEED) {
//     speed = -MAX_SPEED;
//   } else {
//     _speed = speed;
//   }
//   _stepper->setSpeed(speed);
// }
//
// int Motor::getSpeed()
// {
//   return _speed;
// }
//
//
// void Motor::stop()
// {
//   setSpeed(0);
// }
