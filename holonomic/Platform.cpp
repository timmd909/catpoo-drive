#include "Platform.h"

Platform::Platform()
{
  _vX = 0;
  _vY = 0;
  _rot = 0;

  _decayRate = 0.05;

  _lastBearing = 0;
  _lastVX = 0;
  _lastVY = 0;
}

Platform::~Platform()
{
  return; // nothing yet
}

void Platform::init()
{
  // base class doesn't do anything
  return;
}

void Platform::update()
{
  if (_decayRate > 0.0f) {
    float multiplier = 1.0f - _decayRate;
    _vX = floor(_vX * multiplier);
    _vY = floor(_vY * multiplier);
    _rot = floor(_rot * multiplier);
  }
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
  _vX = xSpeed;
  _vY = ySpeed;
  _rot = rotation;

  updateMotorSpeeds();
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

  return bearing;
}

void Platform::updateMotorSpeeds()
{
  // base class doesn't do anything
  return;
}

void Platform::updateMotorSpeed(Motor &motor, const int angle)
{
  float angleDelta = angle - calculateBearing();
  motor.setSpeed((1.0f / cos(angleDelta)) + _rot);
}

//
// Simple command shortcuts
//
void Platform::forward(const int speed)
{
  setVelocity(0, speed, 0);
}

void Platform::backward(const int speed)
{
  setVelocity(0, -speed, 0);
}

void Platform::left(const int speed)
{
  setVelocity(-speed, 0, 0);
}

void Platform::right(const int speed)
{
  setVelocity(speed, 0, 0);
}

void Platform::turn(const int speed)
{
  setVelocity(0, 0, speed);
}

void Platform::stop()
{
  setVelocity(0, 0, 0);
}
