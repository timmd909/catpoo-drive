/**
 * Main loop and callbacks for the holonomic drive
 */

//#include <AccelStepper.h>
//#include "Comms.h"
#include "Motors.h"
#include "Tests.h"
#include "pins.h"

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
  pinMode(A5, INPUT);

  //Comms::init();
  Motors::init();

  Serial.println("INIT COMPLETE");

  Motors::frStepper.moveTo(500);
  Motors::flStepper.moveTo(500);
  Motors::brStepper.moveTo(500);
  Motors::blStepper.moveTo(500);
}


int count = 0;

void printValue(char *description, int value)
{
  int lowRes = value >> 7;
//  Serial.print(lowRes);
  int i;
  Serial.print("[");
  Serial.print(description);
  Serial.print(" ");
  for (i=0; i < lowRes; i++) {
    Serial.print("=");
  }  
  for (; i < 8; i++) {
    Serial.print(" ");
  }
  Serial.print("]");
}

void loop()
{
  Motors::loop();

  static bool firstTime = true;

  if (firstTime) {
    firstTime = false; 
    Tests::dance();    
  }

//  int a0;
//  int a1;
//  int a2;
//  int a3;
//  int a4;
//  int a5;
//  char buffer[1024];
//  sprintf(
//    buffer,
//    "%4d %4d %4d %4d",
//    Motors::flStepper.currentPosition(),
//    Motors::frStepper.currentPosition(),
//    Motors::brStepper.currentPosition(),
//    Motors::blStepper.currentPosition()
//   );
//  Serial.println(buffer);
//  
//  a0 = analogRead(A0);
//  a1 = analogRead(A1);
//  a2 = analogRead(A2);
//  a3 = analogRead(A3);
//  a4 = analogRead(A4);
//  a5 = analogRead(A5);
//
//  printValue("A0", a0);
//  printValue("A1", a1);
//  printValue("A2", a2);
//  printValue("A3", a3);
//  printValue("A4", a4);
//  printValue("A5", a5);
//
//  Serial.println("\n");
}

