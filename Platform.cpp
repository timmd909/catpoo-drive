#include "config.h"
#include "Platform.h"

void Platform::run()
{
  for (int i = 0; i < NUM_MOTORS; i++) {
    _motors[i].run();
  }
}

void Platform::stop()
{
  for (int i = 0; i < NUM_MOTORS; i++) {
    _motors[i].stop();
  }
}

Platform::Platform()
{
  return;
}

Platform::~Platform()
{
  return;
}
