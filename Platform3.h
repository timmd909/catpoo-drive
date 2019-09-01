#ifndef __DRIVE_PLATFORM3_H_
#define __DRIVE_PLATFORM3_H_

#include "Platform.h"

/**
 * Three wheeled holonomic platform class
 */
class Platform3 : public Platform
{
public:
  const int NUM_MOTORS = 3;

  Platform3();
  ~Platform3();
};

#endif
