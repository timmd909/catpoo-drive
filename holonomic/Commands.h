#ifndef __DRIVE_COMMANDS_H_
#define __DRIVE_COMMANDS_H_

#include <queue>

namespace Commands {
  const int RESET = 0x01;
  const int SPEED = 0x02;

  const int ROTATE = 0x10;
  const int TRANSLATE = 0x20;

  const int TURN = 0x11;
  const int MOVE = 0x21;

  const int WHEEL = 0x68;
  const int DANCE = 0x69;

  extern std::queue <char> commandQueue;
}


#endif
