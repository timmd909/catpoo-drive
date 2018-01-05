/**
 * Main loop and callbacks for the holonomic drive
 */

#include <AccelStepper.h>
#include "pins.h"
#include "motors.h"
#include "tests.h"

int stepCount = 0;
int destination = STEPS_PER_REVOLUTION;

void setup() 
{
  Serial.begin(57600);
  delay(1000); // wait a sec in case we've got a USB serial port
  Serial.println("Initializing");

  pinMode(MOTOR_1_PIN_1, OUTPUT);
  pinMode(MOTOR_1_PIN_2, OUTPUT);
  pinMode(MOTOR_1_PIN_3, OUTPUT);
  pinMode(MOTOR_1_PIN_4, OUTPUT);

  pinMode(MOTOR_2_PIN_1, OUTPUT);
  pinMode(MOTOR_2_PIN_2, OUTPUT);
  pinMode(MOTOR_2_PIN_3, OUTPUT);
  pinMode(MOTOR_2_PIN_4, OUTPUT);

  pinMode(MOTOR_3_PIN_1, OUTPUT);
  pinMode(MOTOR_3_PIN_2, OUTPUT);
  pinMode(MOTOR_3_PIN_3, OUTPUT);
  pinMode(MOTOR_3_PIN_4, OUTPUT);

  pinMode(MOTOR_4_PIN_1, OUTPUT);
  pinMode(MOTOR_4_PIN_2, OUTPUT);
  pinMode(MOTOR_4_PIN_3, OUTPUT);
  pinMode(MOTOR_4_PIN_4, OUTPUT);

  leftStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
  leftStepper.setMaxSpeed(MAX_SPEED);
  leftStepper.setSpeed(MAX_SPEED);
  leftStepper.setAcceleration(MAX_ACCELERATION);

  frontStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
  frontStepper.setMaxSpeed(MAX_SPEED);
  frontStepper.setSpeed(MAX_SPEED);
  frontStepper.setAcceleration(MAX_ACCELERATION);

  rightStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
  rightStepper.setMaxSpeed(MAX_SPEED);
  rightStepper.setSpeed(MAX_SPEED);
  rightStepper.setAcceleration(MAX_ACCELERATION);

  backStepper.setMinPulseWidth(PULSE_MIN_WIDTH);
  backStepper.setMaxSpeed(MAX_SPEED);
  backStepper.setSpeed(MAX_SPEED);
  backStepper.setAcceleration(MAX_ACCELERATION);

  steppers.addStepper(leftStepper);
  steppers.addStepper(frontStepper);
  steppers.addStepper(rightStepper);
  steppers.addStepper(backStepper);

  // do a little jig when powered on
  danceTest();  

  // wait another sec after initialization before we start accepting commands
  delay(1000);
}


void loop() 
{
  const int BUFFER_LENGTH = 1024;
  char receiveBuffer[BUFFER_LENGTH];
  memset(receiveBuffer, 0, BUFFER_LENGTH);

  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', receiveBuffer, BUFFER_LENGTH);
  }

}
