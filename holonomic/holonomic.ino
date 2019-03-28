#include <QueueArray.h>

#include <MultiStepper.h>
#include <AccelStepper.h>

/**
 * Main loop and callbacks for the holonomic drive
 */

#include <Arduino.h>
#include <Wire.h>
#include <HardwareSerial.h>

#include "Commands.h"
#include "Platform.h"
#include "Tests.h"
#include "config.h"

namespace
{
  Platform* platform;

  void i2cRequest()
  {
    Serial.println("i2c request ignored");
  }

  void i2cReceive(int numBytes)
  {
    while (Wire.available())
    {
      int nextByte = Wire.read();
      Commands::commandQueue.push(nextByte);
    }
  }
}

void setup()
{
  // Wait 2 seconds to give Arduino IDE time to upload new sketches
  // before we open the serial port.
  delay(5000);

  Serial.println("INITIALIZING");

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println("Initializing motors");
  Serial.print("Motor 0 angle ");
  Serial.println(MOTOR_0_ANGLE);
  Serial.print("Motor 1 angle ");
  Serial.println(MOTOR_1_ANGLE);
  Serial.print("Motor 2 angle ");
  Serial.println(MOTOR_2_ANGLE);
  Motor motor0(MOTOR_0_ANGLE, MOTOR_0_DIR, MOTOR_0_STEP);
  Motor motor1(MOTOR_1_ANGLE, MOTOR_1_DIR, MOTOR_1_STEP);
  Motor motor2(MOTOR_2_ANGLE, MOTOR_2_DIR, MOTOR_2_STEP);

  Serial.println("Initializing platform");
  Motor motors[] = {motor0, motor1, motor2};
  platform = new Platform(3, motors);

  Commands::init(platform);
  Tests::init(platform);

  Serial.println("Initializing I2C");
  Wire.begin(I2C_ADDR);
  Wire.onRequest(i2cRequest);
  Wire.onReceive(i2cReceive);

  // platform->setVelocity(0, 100, 0);

  Serial.println("INIT COMPLETE");
}

void loop()
{
  Commands::process();
  platform->update();
  Serial.println("loop");
  delay(5000);
}
