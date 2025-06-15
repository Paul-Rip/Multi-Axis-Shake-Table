#include <AccelStepper.h>

#define dirPinLeft 7
#define stepPinLeft 8
#define dirPinRight 3
#define stepPinRight 4
#define motorInterfaceType 1

AccelStepper stepperLeft(motorInterfaceType, stepPinLeft, dirPinLeft);
AccelStepper stepperRight(motorInterfaceType, stepPinRight, dirPinRight);

const int enPin1 = 9;
const int enPin2 = 10;

void setup() {
  pinMode(enPin1, OUTPUT);
  pinMode(enPin2, OUTPUT);

  digitalWrite(enPin1, LOW);  // enable motors
  digitalWrite(enPin2, LOW);

  stepperLeft.setMaxSpeed(30000);
  stepperLeft.setAcceleration(10000);
  stepperLeft.moveTo(120);

  stepperRight.setMaxSpeed(30000);
  stepperRight.setAcceleration(10000);
  stepperRight.moveTo(-120);
}

void loop() {
  // Left motor direction reversal
  if (stepperLeft.distanceToGo() == 0) {
    stepperLeft.moveTo(-stepperLeft.currentPosition());
  }
  stepperLeft.run();

  // Right motor direction reversal
  if (stepperRight.distanceToGo() == 0) {
    stepperRight.moveTo(-stepperRight.currentPosition());
  }
  stepperRight.run();
}
