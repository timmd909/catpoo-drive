#include <HardwareSerial.h>
#include <Wire.h>
#include "Comms.h"
#include "Commands.h"
#include "Motors.h"
#include "Tests.h"

extern Serial_ Serial;

namespace Comms
{
  const int I2C_ADDR = 0x45;

  const int COMM_BUFFER_LENGTH = 1024;

  char receiveBuffer[COMM_BUFFER_LENGTH];
  int receiveBufferIndex = 0;

  void i2cRequest()
  {
    // ...
  }

  void i2cReceive(int numBytes)
  {
    if (Wire.available())
    {
      Serial.print("I2C: ");
    }
    while (Wire.available())
    {
      int c = Wire.read();

      // print out recv'd characters for debugging
      Serial.print("0x");
      if (c < 16) { Serial.print("0"); }
      Serial.print(c, HEX);
      Serial.print(" ");

      // pass through to the command command queue
      Commands::commandQueue.push(c);
    }
    Serial.print("\n");
  }

  void init()
  {
    Wire.begin(I2C_ADDR);
    Wire.onRequest(i2cRequest);
    Wire.onReceive(i2cReceive);

    Serial.println("COMMS: INIT");
    resetBuffer();
  }

  void resetBuffer()
  {
    Serial.println("COMMS: OK");
    memset(receiveBuffer, 0, COMM_BUFFER_LENGTH);
    receiveBufferIndex = 0;
  }

  // void processSerialBuffer()
  // {
  //   char* token;
  //
  //   token = strtok(receiveBuffer, " ");
  //   // strip off whitespace in a hacky manner... do it right better later
  //   String tokenStr = String(token);
  //   tokenStr.trim();
  //   token = (char*) tokenStr.c_str();
  //
  //   if (0 == strcmp(token, "DANCE")) {
  //     Commands::commandQueue.push(Commands::DANCE);
  //   } else if (0 == strcmp(token, "WHEEL")) {
  //     Commands::commandQueue.push(Commands::WHEEL);
  //   } else if (0 == strcmp(token, "RESET")) {
  //     Commands::commandQueue.push(Commands::RESET);
  //   } else if (0 == strcmp(token, "TRANSLATE")) {
  //     int xDistance = atoi(strtok(NULL, " "));
  //     int yDistance = atoi(strtok(NULL, " "));
  //     Motors::translate(xDistance, yDistance);
  //   } else if (0 == strcmp(token, "MOVE")) {
  //     int xDistance = atoi(strtok(NULL, " "));
  //     int yDistance = atoi(strtok(NULL, " "));
  //     Motors::move(xDistance, yDistance);
  //   } else if (0 == strcmp(token, "TURN")) {
  //     int speed = atoi(strtok(NULL, " "));
  //     Motors::turn(speed);
  //   } else if (0 == strcmp(token, "ROTATE")) {
  //     int rotation = atoi(strtok(NULL, " "));
  //     Motors::rotate(rotation);
  //   } else if (0 == strcmp(token, "SPEED")) {
  //     int speed = atoi(strtok(NULL, " "));
  //     Motors::setSpeed(speed);
  //     Motors::setMaxSpeed(speed);
  //   } else {
  //     Serial.print("DAFUQ: ");
  //     Serial.println(receiveBuffer);
  //   }
  //
  //   // cleanup: wipe and reset the receive buffer
  //   resetBuffer();
  // }

  void loop()
  {
    Commands::processQueue();

    // char nextByte;
    //
    // while (Serial.available() > 0) {
    //   nextByte = Serial.read();
    //   // notice the lack of bounds checking. as an artist, it's what
    //   // you take out that's more important than what you put in.
    //   receiveBuffer[receiveBufferIndex++] = nextByte;
    //
    //   // did we get a newline yet?
    //   if (nextByte == '\n') {
    //     // yup! process that!
    //     processSerialBuffer();
    //   }
    // }

  }
}
