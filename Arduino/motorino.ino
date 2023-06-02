#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER,2,4);

void setup()
{
  pinMode(8,OUTPUT);
  digitalWrite(8,LOW);
  stepper.setMaxSpeed(4000);
  stepper.setSpeed(4000);
}

void loop()
{
  stepper.runSpeed();
}
