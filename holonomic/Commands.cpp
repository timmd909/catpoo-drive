#include "Commands.h"
#include "Motors.h"
#include "Tests.h"

namespace Commands
{
  QueueArray <long> commandQueue;

  int popShort()
  {
    // Serial.print("Popping short ");
    short low = commandQueue.pop();
    short high = commandQueue.pop();
    short result = (low & 0xff) | ((high & 0xff) << 8 & 0xff00);
    // Serial.print(result);
    // Serial.println("");
    // Serial.println("POP DONE. REMAINING: ");
    // Serial.print(commandQueue.count());
    // Serial.println("");
    return result;
  }

  void emptyQueue()
  {
    Serial.println("Dumping command queue");
    long c = commandQueue.pop();
    Serial.println(c);
  }

  void processQueue()
  {
    char command;
    int arg1, arg2;

    if (commandQueue.isEmpty())
    {
      return; // no commands pending
    }

    command = commandQueue.peek();

    switch (command)
    {
      case RESET:
        commandQueue.pop();
        Motors::reset();
      break;

      case WHEEL:
        commandQueue.pop();
        Tests::wheel();
      break;

      case DANCE:
        commandQueue.pop();
        Tests::dance();
      break;

      case SET_SPEED:
        if (commandQueue.count() < 3)
        {
          return; // input not yet available
        }
        commandQueue.pop();
        arg1 = popShort();
        Motors::setSpeed(arg1);
        Motors::setMaxSpeed(arg1);
      break;

      // case TURN:
      //   if (commandQueue.count() < 3)
      //   {
      //     return; // input not yet available
      //   }
      //   commandQueue.pop();
      //   arg1 = popShort();
      //   Motors::turn(arg1);
      // break;
      //
      // case MOVE:
      //   if (commandQueue.count() < 5)
      //   {
      //     return; // input not yet available
      //   }
      //   commandQueue.pop();
      //   arg1 = popShort();
      //   arg2 = popShort();
      //   Motors::move(arg1, arg2);
      // break;

      case ROTATE:
        if (commandQueue.count() < 3)
        {
          return; // input not yet available
        }
        commandQueue.pop();
        arg1 = popShort();
        Motors::rotate(arg1);
      break;

      case TRANSLATE:
        if (commandQueue.count() < 5)
        {
          return; // input not yet available
          return;
        }
        commandQueue.pop();
        arg1 = popShort();
        arg2 = popShort();
        Motors::translate(arg1, arg2);
      break;

      default:
        Serial.print("???: 0x");
        Serial.print((unsigned int)command, HEX);
        Serial.println("  WTF?");
        commandQueue.pop();
      break;
    }

    return;
  } // void processQueue()
}
