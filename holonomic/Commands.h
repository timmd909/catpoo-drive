#ifndef __DRIVE_COMMANDS_H_
#define __DRIVE_COMMANDS_H_

#include <QueueArray.h>

#define RESET 0x01
#define SET_SPEED 0x02

#define ROTATE 0x10
#define TRANSLATE 0x20

#define TURN 0x11
#define MOVE 0x21

#define WHEEL 0x68
#define DANCE 0x69

namespace Commands
{
  extern QueueArray <long> commandQueue;

  void process();
}


#endif
