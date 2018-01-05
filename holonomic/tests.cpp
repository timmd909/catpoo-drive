#include <HardwareSerial.h>
#include "motors.h"
#include "tests.h"

extern Serial_ Serial;

// Spin the left, front, right, and back wheels 1 revolution in order 
// clockwise 1 revolution, then 1 revolution counterclockwise. 
void wheelTest()
{
  Serial.println("Starting wheel test ");

  resetAllSteppers();

  int distance = STEPS_PER_REVOLUTION / 4;
  
  leftStepper.runToNewPosition(distance);
  leftStepper.runToNewPosition(0);

  frontStepper.runToNewPosition(distance);
  frontStepper.runToNewPosition(0);

  rightStepper.runToNewPosition(distance);
  rightStepper.runToNewPosition(0);

  backStepper.runToNewPosition(distance);
  backStepper.runToNewPosition(0);  
}

void danceTest()
{
  Serial.println("Starting dance test ");
  
  long distance = STEPS_PER_REVOLUTION / 8;

  rotate(distance*4);
  rotate(distance*-4);
  
  long moveForward[] =  {-distance , 0,  distance, 0};
  long moveBackward[] = { distance , 0, -distance, 0};
  long moveLeft[] =  {0, -distance , 0,  distance};
  long moveRight[] = {0,  distance , 0, -distance};
  long moveForwardAndLeft[] =   {-distance ,  distance ,  distance, -distance };
  long moveForwardAndRight[] =  {-distance , -distance ,  distance,  distance };
  long moveBackwardAndRight[] = { distance , -distance , -distance,  distance };
  long moveBackwardAndLeft[] =  { distance ,  distance , -distance, -distance };

  // straight directions 
  Serial.println("Moving forward");
  move(moveForward);
  Serial.println("Moving backward");
  move(moveBackward);
  Serial.println("Moving backward");
  move(moveBackward);
  Serial.println("Moving forward");
  move(moveForward);
  
  Serial.println("Moving right");
  move(moveRight);
  Serial.println("Moving left");
  move(moveLeft);  
  Serial.println("Moving left");
  move(moveLeft);
  Serial.println("Moving right");
  move(moveRight);

  // angled movements 
   
  Serial.println("Moving forward and left");
  move(moveForwardAndLeft);
  Serial.println("Moving backward and right");
  move(moveBackwardAndRight);
    
  Serial.println("Moving forward and right");
  move(moveForwardAndRight);
  Serial.println("Moving backward and left");
  move(moveBackwardAndLeft); 

  Serial.println("Moving backward and right");
  move(moveBackwardAndRight);
  Serial.println("Moving forward and left");
  move(moveForwardAndLeft);

  Serial.println("Moving backward and left");
  move(moveBackwardAndLeft);
  Serial.println("Moving forward and right");
  move(moveForwardAndRight);
}

