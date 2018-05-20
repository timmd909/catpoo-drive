#include "Commands.h"
#include "Motors.h"
#include "Tests.h"

namespace Commands
{
  const int RESET = 0x01;
  const int SET_SPEED = 0x02;

  const int ROTATE = 0x10;
  const int TRANSLATE = 0x20;

  const int TURN = 0x11;
  const int MOVE = 0x21;

  const int WHEEL = 0x68;
  const int DANCE = 0x69;

  QueueArray <char> commandQueue;

  void processQueue()
  {
    char command;
    int speed;

    while (!commandQueue.isEmpty())
    {
      command = commandQueue.pop();
      switch (command)
      {
        case RESET:
          Motors::reset();
        break;

        case SPEED:
          speed = (int) commandQueue.pop();
          Motors::setSpeed(speed);
          Motors::setMaxSpeed(speed);
        break;

        case WHEEL:
          Tests::wheel();
        break;

        case DANCE:
          Tests::dance();
        break;

        default:
          Serial.print("ERROR: ");
          Serial.println(command, HEX);
      }
    }

    return;
  } // void processQueue()
}
