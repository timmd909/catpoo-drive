#include "Commands.h"
#include "Tests.h"

namespace Commands
{
  // QueueArray <long> commandQueue;
  // Platform *_platform;
  //
  // int popShort()
  // {
  //   // Serial.print("Popping short ");
  //   short low = commandQueue.pop();
  //   short high = commandQueue.pop();
  //   short result = (low & 0xff) | ((high & 0xff) << 8 & 0xff00);
  //   // Serial.print(result);
  //   // Serial.println("");
  //   // Serial.println("POP DONE. REMAINING: ");
  //   // Serial.print(commandQueue.count());
  //   // Serial.println("");
  //   return result;
  // }
  //
  // void emptyQueue()
  // {
  //   Serial.println("Dumping command queue");
  //   long c = commandQueue.pop();
  //   Serial.println(c);
  // }
  //
  // void init(Platform *platform)
  // {
  //   _platform  = platform;
  // }
  //
  // void process()
  // {
  //   char command;
  //   int arg1, arg2;
  //
  //   if (commandQueue.isEmpty())
  //   {
  //     return; // no commands pending
  //   }
  //
  //   command = commandQueue.peek();
  //
  //   switch (command)
  //   {
  //     case RESET:
  //       commandQueue.pop();
  //       _platform->stop();
  //     break;
  //
  //     case WHEEL:
  //       commandQueue.pop();
  //       Tests::wheel();
  //     break;
  //
  //     case DANCE:
  //       commandQueue.pop();
  //       Tests::dance();
  //     break;
  //
  //     // case SET_SPEED:
  //     //   if (commandQueue.count() < 3)
  //     //   {
  //     //     return; // input not yet available
  //     //   }
  //     //   commandQueue.pop();
  //     //   arg1 = popShort();
  //     //   _platform->setSpeed(arg1);
  //     // break;
  //
  //     case TURN:
  //       if (commandQueue.count() < 3)
  //       {
  //         return; // input not yet available
  //       }
  //       commandQueue.pop();
  //       arg1 = popShort();
  //       _platform->setVelocity(0, 0, arg1);
  //     break;
  //
  //     case MOVE:
  //       if (commandQueue.count() < 5)
  //       {
  //         return; // input not yet available
  //       }
  //       commandQueue.pop();
  //       arg1 = popShort();
  //       arg2 = popShort();
  //       _platform->setVelocity(arg1, arg2, 0);
  //     break;
  //
  //     // case ROTATE:
  //     //   if (commandQueue.count() < 3)
  //     //   {
  //     //     return; // input not yet available
  //     //   }
  //     //   commandQueue.pop();
  //     //   arg1 = popShort();
  //     //   _platform->setVelocity(0, 0, arg1);
  //     // break;
  //     //
  //     // case TRANSLATE:
  //     //   if (commandQueue.count() < 5)
  //     //   {
  //     //     return; // input not yet available
  //     //     return;
  //     //   }
  //     //   commandQueue.pop();
  //     //   arg1 = popShort();
  //     //   arg2 = popShort();
  //     //   _platform->setVelocity(arg1, arg2, 0);
  //     // break;
  //
  //     default:
  //       Serial.print("???: 0x");
  //       Serial.print((unsigned int)command, HEX);
  //       Serial.println("  WTF?");
  //       commandQueue.pop();
  //     break;
  //   }
  //
  //   return;
  // } // void process()
}
