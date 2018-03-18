/**
 * Main loop and callbacks for the holonomic drive
 */

//#include <AccelStepper.h>
//#include "Comms.h"
#include "Motors.h"
//#include "Tests.h"
#include "pins.h"

//int stepCount = 0;
//int destination = Motors::STEPS_PER_REVOLUTION;

void setup()
{
	// Wait 2 seconds to give Arduino IDE time to upload new sketches
	// before we open the serial port.
	delay(5000);

  Serial.println("INITIALIZING");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
//  pinMode(11, OUTPUT);
//  pinMode(12, OUTPUT);

  //Comms::init();
  Motors::init();

  Serial.println("INIT COMPLETE");

  digitalWrite(MOTOR_LEFT_DIR_PIN,  HIGH);
  digitalWrite(MOTOR_FRONT_DIR_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_DIR_PIN, HIGH);
  digitalWrite(MOTOR_BACK_DIR_PIN,  HIGH);

}


int count = 0;

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(50);
  digitalWrite(LED_BUILTIN, LOW);

//	Comms::loop();
//	Motors::loop();
//

  delay(1000);

  digitalWrite(MOTOR_LEFT_STEP_PIN,  HIGH);
  digitalWrite(MOTOR_FRONT_STEP_PIN, HIGH);
  digitalWrite(MOTOR_RIGHT_STEP_PIN, HIGH);
  digitalWrite(MOTOR_BACK_STEP_PIN,  HIGH);

  delay(1000);
  
  digitalWrite(MOTOR_LEFT_STEP_PIN,  LOW);
  digitalWrite(MOTOR_FRONT_STEP_PIN, LOW);
  digitalWrite(MOTOR_RIGHT_STEP_PIN, LOW);
  digitalWrite(MOTOR_BACK_STEP_PIN,  LOW);
  

//  Serial.println("Dance!");
//  Tests::dance();
//  delay(1000);  

  int input;
  
//  input = analogRead(A0);
//  Serial.print("A0: ");
//  Serial.println(input);

  input = analogRead(A1);
  Serial.print("A1: ");
  Serial.println(input);

//  input = analogRead(A2);
//  Serial.print("A2: ");
//  Serial.println(input);
//
//  input = analogRead(A3);
//  Serial.print("A3: ");
//  Serial.println(input);
//
//  input = analogRead(A4);
//  Serial.print("A4: ");
//  Serial.println(input);
//
//  input = analogRead(A5);
//  Serial.print("A5: ");
//  Serial.println(input);

  Serial.println(count++);

}
