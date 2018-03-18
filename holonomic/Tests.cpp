//#include <HardwareSerial.h>
//#include "Motors.h"
//#include "Tests.h"
//
//extern Serial_ Serial;
//
//namespace Tests
//{
//  // Spin the left, front, right, and back wheels 1 revolution in order
//  // clockwise 1 revolution, then 1 revolution counterclockwise.
//  void wheel()
//  {
////    Motors::reset();
////
////    int distance = Motors::STEPS_PER_REVOLUTION;
////
////    Serial.println("Front stepper test");
////    Motors::frontStepper.runToNewPosition(distance);
////    Motors::frontStepper.runToNewPosition(0);
////
////    Serial.println("Right stepper test");
////    Motors::rightStepper.runToNewPosition(distance);
////    Motors::rightStepper.runToNewPosition(0);
////
////    Serial.println("Back stepper test");
////    Motors::backStepper.runToNewPosition(distance);
////    Motors::backStepper.runToNewPosition(0);
////
////    Serial.println("Left stepper test");
////    Motors::leftStepper.runToNewPosition(distance);
////    Motors::leftStepper.runToNewPosition(0);
//
//  }
//
//  void dance()
//  {
////    long distance = Motors::STEPS_PER_REVOLUTION;
////
////    Motors::rotate(distance * -2); Motors::commit();
////    Motors::rotate(distance *  2); Motors::commit();
////
////    //
////    // straight directions
////    //
////    Motors::move(0, distance);      Motors::commit();
////    Motors::move(0, -distance * 2); Motors::commit();
////    Motors::move(distance, 0);      Motors::commit();
////    Motors::move(-distance, 0);     Motors::commit();
////
////    //
////    // angled movements
////    //
////    Motors::move(-distance, distance);  Motors::commit();
////    Motors::move(distance, -distance);  Motors::commit();
////
////    Motors::move(distance, distance);   Motors::commit();
////    Motors::move(-distance, -distance); Motors::commit();
////
////    Motors::move(distance, -distance);  Motors::commit();
////    Motors::move(-distance, distance);  Motors::commit();
////
////    Motors::move(-distance, -distance); Motors::commit();
////    Motors::move(distance, distance);   Motors::commit();
//  }
//
//}
