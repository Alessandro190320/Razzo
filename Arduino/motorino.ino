#include <Stepper.h>

#define STEPS 200

const int dirPin = 4;
const int stepPin = 2;
const int enPin = 8;
#define motorInterfaceType 1;

Stepper myStepper(STEPS, 4, 2);


void setup() {
  // put your setup code here, to run once:

  myStepper.setSpeed(1000);
  pinMode( enPin ,OUTPUT);
  digitalWrite( enPin , LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //myStepper.step(10);
  myStepper.step(-STEPS);
  /*if(cnt < 10)
    myStepper.step(10);

  else
    myStepper.step(-10);

   cnt++;+*/
}