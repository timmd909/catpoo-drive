#include "Platform.h"

Platform::Platform(int numMotors, Motor *motors)
{
  _numMotors = numMotors;
  _motors = motors;

  _vX = 0;
  _vY = 0;
  _rot = 0;

  _decayRate = 0.05;

  _lastBearing = 0;
  _lastVX = 0;
  _lastVY = 0;
}

void Platform::update()
{
  int i;

  Serial.println("Updating platform");

  //
  // Gradually slow the platform
  //
  if (_decayRate > 0.0f) {
    float decayMultiplier = 1.0f - _decayRate;
    _vX = floor(_vX * decayMultiplier);
    _vY = floor(_vY * decayMultiplier);
    _rot = floor(_rot * decayMultiplier);
  }

  //
  // Update the motor speeds
  //
  float angleDelta, speed;
  float linearSpeed = sqrt(_vX * _vX  + _vY * _vY);
  for (i = 0 ; i < _numMotors; i++) {
    Serial.print("Motor ");
    Serial.print(i);
    Motor *motor = _motors + i;

    Serial.print(" Angle = ");
    Serial.print(motor->getAngle());

    // calculate the linear motion speed first
    angleDelta = motor->getAngle() - calculateBearing();
    Serial.print(" angleDelta = ");
    Serial.println(angleDelta);

    /*
    Serial.print(" cos(angleDelta) = ");
    Serial.println(cos(angleDelta));
    speed = (1.0f / cos(angleDelta)) * linearSpeed;

    // add in the rotational speed
    speed += _rot;

    Serial.print(" speed = ");
    Serial.println(speed);

    // finally update the motor's speed
    motor->setSpeed(speed);

    */
  }

/*   //
  // Update the motors internal state
  //
  for (i = 0 ; i < _numMotors; i++) {
    Serial.print("Motor ");
    Serial.print(i);
    _motors[i].update();
  } */

}

void Platform::setDecayRate(float decayRate)
{
  _decayRate = decayRate;
}

float Platform::getDecayRate()
{
  return _decayRate;
}


void Platform::setVelocity(const int xSpeed, const int ySpeed, const int rotation)
{
  Serial.print("Updating velocity - ");
  Serial.print(xSpeed);
  Serial.print(" - ");
  Serial.print(ySpeed);
  Serial.print(" - ");
  Serial.println(rotation);

  _vX = xSpeed;
  _vY = ySpeed;
  _rot = rotation;
}

float Platform::calculateBearing()
{
  if (_vX == _lastVX && _vY == _lastVY) {
    // velocity hasn't changed, return cached bearing
    return _lastBearing;
  }

  float bearing;

  if (!_vX && !_vY) {
    // no movement... any value here would be acceptable I guess...
    // but let's stick w/ 0
    bearing = 0.0f;
  } else if (!_vX) {
    if (_vY > 0)
      bearing = (M_PI/2.0f);
    else
      bearing = (3.0f * M_PI / 2.0f);
  } else if (!_vY) {
    if (_vX > 0)
      bearing = 0.0f;
    else
      bearing = -M_PI;
  } else {
    // need to do a little trig here
    bearing = atan(_vY/_vX);
    if (_vX < 0.0f) {
      // if the velocity is to the left, then the bearing will be
      // off by 180°, thus we need to:
      bearing += M_PI;
    }
  }

  _lastVX = _vX;
  _lastVY = _vY;
  _lastBearing = bearing;

  Serial.print("Bearing = ");
  Serial.println(bearing);

  return bearing;
}

void Platform::stop()
{
  setVelocity(0, 0, 0);
  update();
}
