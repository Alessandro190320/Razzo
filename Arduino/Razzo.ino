#include <Stepper.h>

#define STEPS 200

const int stepperTime = 5000; //Tempo dopo il quale lo stepper torna giù

int rosso = 5;
int blue = 6;
int verde = 8;
int giallo = 10;
int bianco = 9;

//Pin di configurazione per lo stepper
const int dirPin = 2;
const int stepPin = 3;
const int enPin = 4;
#define motorInterfaceType 1;
Stepper myStepper(STEPS, 4, 2);

char junk;
String inputString="";

unsigned long t1,dt;

boolean flagMotorino = false;

void setup() {
  Serial.begin(9600); // inizializzo la seriale del bluetooth a 9600

  // inizializzo i pin per OUTPUT
  pinMode(rosso,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(giallo,OUTPUT);
  pinMode(bianco,OUTPUT);
  delay(1000);
  digitalWrite(rosso,HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(giallo,HIGH);
  digitalWrite(bianco,HIGH);
  delay(2000); // mantengo accessi 2 secondi
  digitalWrite(rosso,LOW);
  digitalWrite(blue, LOW);
  digitalWrite(verde,LOW);
  digitalWrite(giallo,LOW);
  digitalWrite(bianco,LOW);
  //Stepper setup
  myStepper.setSpeed(1000);
  pinMode( enPin ,OUTPUT);
  digitalWrite( enPin , LOW);
}

void loop() {
  dt = millis() - t1;
  
  if(Serial.available()){
     while (Serial.available()) {
      char inChar = (char) Serial.read();
      inputString += inChar;
    }
    Serial.println(inputString);
    while (Serial.available() > 0) {
      junk = Serial.read() ;
    }
  }
  if(inputString == "rossoON"){
    digitalWrite(rosso,HIGH); // accendo rosso
  }
  if(inputString == "rossoOFF"){
    digitalWrite(rosso,LOW); // spengo il rosso
  }

   if(inputString == "bluON"){
    digitalWrite(blue,HIGH); // accendo blu
  }
  if(inputString == "bluOFF"){
    digitalWrite(blue,LOW); // spengo il blu
  }

   if(inputString == "verdeON"){
    digitalWrite(verde,HIGH); // accendo verde
  }
  if(inputString == "verdeOFF"){
    digitalWrite(verde,LOW); // spengo il verde
  }

   if(inputString == "gialloON"){
    digitalWrite(giallo,HIGH); // accendo bianco
  }
  if(inputString == "gialloOFF"){
    digitalWrite(giallo,LOW); // spengo il bianco
  }

   if(inputString == "biancoON"){
    digitalWrite(bianco,HIGH); // accendo bianco
  }
  if(inputString == "biancoOFF"){
    digitalWrite(bianco,LOW); // spengo il bianco
  }

  if(inputString == "Motorino25")
  {
    // accendo il motorino per il 25% dell'altezza
  }
  
  if(inputString == "Motorino50")
  {
    // accendo il motorino per il 50% dell'altezza
  }

   if(inputString == "Motorino75")
  {
    // accendo il motorino per il 75% dell'altezza
  }

   if(inputString == "Motorino100")
  {
    // accendo il motorino per il 100% dell'altezza 
    flagMotorino = true;
  }

  if(flagMotorino == true )
  {
    // codice motorino
    if(dt < StepperTime){
       myStepper.step(-STEPS);
    }
    else{
      t1 = millis();
      flagMotorino = "Scendi";
      delay(1000);
  }

  if(flagMotorino == "Scendi"){
   if(dt < StepperTime){
       myStepper.step(STEPS);
    }
    else{
      t1 = millis();
      flagMotorino = false;
  }

  inputString="";

}
