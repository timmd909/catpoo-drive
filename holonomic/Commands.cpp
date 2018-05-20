#include "Commands.h"

namespace Commands {
  std::queue <char> commandQueue;

  void processQueue()
  {
    char command;
    int speed;

    while (!commandQueue.empty())
    {
      command = commandQueue.pop();
      switch (command)
      {
        case RESET;
          Motors::reset();
        break;

        case SPEED;
          speed = (int) commandQueue.pop();
          Motors::setSpeed(speed);
          Motors::setMaxSpeed(speed);
        break;

        case WHEEL;
          Tests::wheel();
        break;

        case DANCE;
          Tests::dance();
        break;

        default:
          Serial.print("Invalid command: ");
          Serial.println(command, HEX);
      }
    }

    return;
  } // void processQueue()
}
