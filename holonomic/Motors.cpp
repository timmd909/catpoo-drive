#include <AccelStepper.h>
#include "Motors.h"
#include "pins.h"

namespace Motors
{
  const double SQRT2 = sqrt(2.0f);

  MultiStepper steppers = MultiStepper();
  AccelStepper flStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_FL_STEP, MOTOR_FL_DIR);
  AccelStepper frStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_FR_STEP, MOTOR_FR_DIR);
  AccelStepper blStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_BL_STEP, MOTOR_BL_DIR);
  AccelStepper brStepper  = AccelStepper(AccelStepper::DRIVER, MOTOR_BR_STEP, MOTOR_BR_DIR);

  void init()
  {
    Serial.println("MOTORS: INIT");

    pinMode(MOTOR_FL_STEP, OUTPUT);
    pinMode(MOTOR_FL_DIR,  OUTPUT);
    digitalWrite(MOTOR_FL_DIR,  LOW);
    digitalWrite(MOTOR_FL_STEP, LOW);

    pinMode(MOTOR_FR_STEP, OUTPUT);
    pinMode(MOTOR_FR_DIR,  OUTPUT);
    digitalWrite(MOTOR_FR_DIR,  LOW);
    digitalWrite(MOTOR_FR_STEP, LOW);

    pinMode(MOTOR_BR_STEP, OUTPUT);
    pinMode(MOTOR_BR_DIR,  OUTPUT);
    digitalWrite(MOTOR_BR_DIR,  LOW);
    digitalWrite(MOTOR_BR_STEP, LOW);

    pinMode(MOTOR_BL_STEP, OUTPUT);
    pinMode(MOTOR_BL_DIR,  OUTPUT);
    digitalWrite(MOTOR_BL_DIR,  LOW);
    digitalWrite(MOTOR_BL_STEP, LOW);

    steppers.addStepper(flStepper);
    steppers.addStepper(frStepper);
    steppers.addStepper(brStepper);
    steppers.addStepper(blStepper);

    setMaxSpeed(MAX_SPEED);
    setAcceleration(MAX_ACCELERATION);

    Motors::reset();
  }

  void reset()
  {
    Serial.println("MOTORS: RESET");

    flStepper.setCurrentPosition(0);
    frStepper.setCurrentPosition(0);
    brStepper.setCurrentPosition(0);
    blStepper.setCurrentPosition(0);

    long zeros[] = { 0, 0, 0, 0 };
    steppers.moveTo(zeros);
  }

  void setSpeed(int speed)
  {
    if (speed > MAX_SPEED) {
      speed = MAX_SPEED;
    }
    Serial.print("MOTORS: SET SPEED ");
    Serial.println(speed);
    flStepper.setSpeed(speed);
    frStepper.setSpeed(speed);
    brStepper.setSpeed(speed);
    blStepper.setSpeed(speed);
  }

  void setMaxSpeed(int speed)
  {
    if (speed > MAX_SPEED) {
      speed = MAX_SPEED;
    }
    Serial.print("MOTORS: SET MAX SPEED ");
    Serial.println(speed);
    flStepper.setMaxSpeed(speed);
    frStepper.setMaxSpeed(speed);
    brStepper.setMaxSpeed(speed);
    blStepper.setMaxSpeed(speed);
  }

  void setAcceleration(int accel)
  {
    if (accel > MAX_ACCELERATION) {
      accel = MAX_ACCELERATION;
    }
    Serial.print("MOTORS: SET ACCEL ");
    Serial.println(accel);
    flStepper.setAcceleration(accel);
    frStepper.setAcceleration(accel);
    brStepper.setAcceleration(accel);
    blStepper.setAcceleration(accel);
  }

  void commit()
  {
    Serial.println("MOTORS: COMMIT");
    Motors::steppers.runSpeedToPosition();
  }

  void loop()
  {
    steppers.run();
  }

  // void move(long x, long y)
  // {
  //   Serial.print("MOTORS: MOVE (");
  //   Serial.print(x);
  //   Serial.print(", ");
  //   Serial.print(y);
  //   Serial.println(")");
  //
  //   double magnitude = sqrt((double)x * x + (double)y * y);
  //
  //   reset();
  //   setSpeed((int)magnitude);
  //   setMaxSpeed((int)magnitude);
  //
  //   // don't allow more than a meter at a time
  //   x = x > MAX_DISTANCE ? MAX_DISTANCE : x;
  //   y = y > MAX_DISTANCE ? MAX_DISTANCE : y;
  //
  //   translate(x, y);
  // }

  void translate(long xDistance, long yDistance)
  {
    Serial.print("MOTORS: TRANSLATE (");
    Serial.print(xDistance);
    Serial.print(", ");
    Serial.print(yDistance);
    Serial.println(")");

    reset();

    double fl_X, fr_X, bl_X, br_X;
    fl_X = SQRT2 * xDistance;
    fr_X = SQRT2 * xDistance;
    br_X = SQRT2 * xDistance * -1.0f;
    bl_X = SQRT2 * xDistance * -1.0f;

    double fr_Y, fl_Y, bl_Y, br_Y;
    fl_Y = SQRT2 * yDistance;
    fr_Y = SQRT2 * yDistance * -1.0f;
    br_Y = SQRT2 * yDistance * -1.0f;
    bl_Y = SQRT2 * yDistance;

    long positions[] = {
      (fl_X + fl_Y),
      (fr_X + fr_Y),
      (br_X + br_Y),
      (bl_X + bl_Y)
    };

    steppers.moveTo(positions);
  }

  void rotate(long distance)
  {
    Serial.print("ROTATING "); Serial.println(distance);
    reset();

    long positions[] = {distance, distance, distance, distance};
    steppers.moveTo(positions);
  }

  // void turn(long speed)
  // {
  //   setSpeed(fabs(speed));
  //   setMaxSpeed(fabs(speed));
  //
  //   rotate(MAX_DISTANCE / 2);
  // }

}
