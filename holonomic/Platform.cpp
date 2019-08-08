#include "macros.h"
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

  // calcualte the
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
  float bearing;

  if (!_vX && !_vY) {
    // no movement... any value here would be acceptable I guess...
    // but let's stick w/ 0
    bearing = 0.0f;
  } else if (!_vX) {
    if (_vY > 0)
      bearing = M_PI / 2; // 90 degress
    else
      bearing = M_PI / 2 * 3; // 270 degrees
  } else if (!_vY) {
    if (_vX > 0)
      bearing = 0.0f;
    else
      bearing = M_PI;
  } else {
    // need to do a little trig here
    bearing = atan(_vY/_vX);
    if (_vX < 0.0f) {
      // if the velocity is to the left, then the bearing will be
      // off by 180°, thus we need to:
      bearing += M_PI;
    }
    if (_vY < 0.0f) {
      // if velocity is down, then we we need to do another
      // rotation (this time + 360 deg)
      bearing += M_PI * 2;
    }
  }

  _lastVX = _vX;
  _lastVY = _vY;
  _lastRot = bearing;

  Serial.print("Bearing = ");
  Serial.println(bearing);

  return bearing;
}

void Platform::stop()
{
  setVelocity(0, 0, 0);
  update();
}
