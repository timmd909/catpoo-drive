#ifndef __DRIVE_COMMANDS_H_
#define __DRIVE_COMMANDS_H_

#include <QueueArray.h>

namespace Commands
{
  extern const int RESET;
  extern const int SET_SPEED;

  extern const int ROTATE;
  extern const int TRANSLATE;

  extern const int TURN;
  extern const int MOVE;

  extern const int WHEEL;
  extern const int DANCE;

  extern QueueArray <char> commandQueue;

  void processQueue();
}


#endif
