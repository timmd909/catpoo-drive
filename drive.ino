//
// DRIVE!
//
// My universal robot handling library
//

#include "config.h"

#include <Arduino.h>
#include <AccelStepper.h>

#include "Platform3.h"
#include "I2C.h"

Platform3 platform;

void setup()
{
  // Wait a short bit to give Arduino IDE time to upload new sketches
  // before we open the serial port.
  delay(5000);

  Serial.println("INITIALIZING");

  pinMode(MOTOR_0_STEP, OUTPUT);
  pinMode(MOTOR_0_DIR, OUTPUT);

  pinMode(MOTOR_1_STEP, OUTPUT);
  pinMode(MOTOR_1_DIR, OUTPUT);

  pinMode(MOTOR_2_STEP, OUTPUT);
  pinMode(MOTOR_2_DIR, OUTPUT);

  pinMode(RANGE_0, INPUT);
  pinMode(RANGE_1, INPUT);
  pinMode(RANGE_2, INPUT);
  pinMode(RANGE_3, INPUT);
  pinMode(RANGE_4, INPUT);
  pinMode(RANGE_5, INPUT);

  I2C::init();
  platform.init();

  // simulate initializing
  delay(1000);

  Serial.println("INIT COMPLETE");
}

void loop()
{
  delay(1000);
  Serial.println("loop");

  int r0 = analogRead(RANGE_0);
  int r1 = analogRead(RANGE_1);
  int r2 = analogRead(RANGE_2);
  int r3 = analogRead(RANGE_3);
  int r4 = analogRead(RANGE_4);
  int r5 = analogRead(RANGE_5);

  Serial.print("range finders = [");
  Serial.print(r0);
  Serial.print("  ");
  Serial.print(r1);
  Serial.print("  ");
  Serial.print(r2);
  Serial.print("  ");
  Serial.print(r3);
  Serial.print("  ");
  Serial.print(r4);
  Serial.print("  ");
  Serial.print(r5);
  Serial.println("]");

}
