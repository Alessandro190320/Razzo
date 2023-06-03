#include <Stepper.h>


// Pin motorino
#define STEPS 200
#define motorInterfaceType 1;
int MotorDir = 13;
int MotorStep = 12;
// non ho bisogno dell'EN in quando basta collegarlo a GND per garantire il valore LOW

Stepper myStepper(STEPS, MotorDir, MotorStep);

// Pin Led
int giallo = 6;
int rosso = 5;
int verde = 4;
int blue = 3;
int bianco = 2;

#define R "rosso"
#define G "giallo"
#define V "verde"
#define Bi "bianco"
#define Bl "blue"


// cnt
int cntGiallo = 0;
int cntRosso = 0;
int cntVerde = 0;
int cntBlue = 0;
int cntBianco = 0;

String inputString=""; // stringa in input
char junk; // variabile cestino

unsigned long t1,dt;

boolean flagMotorinoUp = false;
boolean flagMotorinoDown = false;
boolean flagMillis = false;

#define TIME 2000

void setup() {
  Serial.begin(9600); // inizializzo la seriale del bluetooth a 9600

  // inizializzo i pin per OUTPUT
  pinMode(rosso,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(verde,OUTPUT);
  pinMode(giallo,OUTPUT);
  pinMode(bianco,OUTPUT);
  //pinMode(motorino,OUTPUT);
  delay(1000);
  
  // i relay funzionano al contrario, se a LOW chiudono il circuito e accendono i LED
  digitalWrite(rosso,LOW);
  digitalWrite(blue, LOW);
  digitalWrite(verde,LOW);
  digitalWrite(giallo,LOW);
  digitalWrite(bianco,LOW);
  
  delay(2000); // mantengo accessi 2 secondi

  // spengo i led
  digitalWrite(rosso,HIGH);
  digitalWrite(blue, HIGH);
  digitalWrite(verde,HIGH);
  digitalWrite(giallo,HIGH);
  digitalWrite(bianco,HIGH);

  // inzializzo la velocità del motorino
  myStepper.setSpeed(1000);

  Serial.println("Pronto");
}

void loop() {
 
  
  if (Serial.available()) { // se ci sono caratteri da leggere
    while (Serial.available()) { // finchè ci sono caratteri da leggere
      char inChar = (char) Serial.read(); // leggo un carattere
      inputString += inChar; // aggiungo alla stringa
    }
    Serial.println(inputString); // stampo la stringa
    while (Serial.available() > 0) { // se ci sono altri caratteri 
      junk = Serial.read() ; // li leggo e li butto via
    }
  }

  // CONTROLLI

  // 1-giallo
  if(inputString == "Y"){ // se l'input è Y di yellow
    cntGiallo++;
    Serial.print(G);
    if(cntGiallo%2==1){ // se è dispari vuol dire che è acceso
      digitalWrite(giallo,LOW); // mettere il rosso a LOW vuol dire accendere il reley
      Serial.println(" on");
    }
    else{
      digitalWrite(giallo,HIGH);
      Serial.println(" off");
    }
  }

  // 2-rosso
  if(inputString == "R"){ // se l'input è R di red
    cntRosso++;
    Serial.print(R);
    if(cntRosso%2==1){ // se è dispari vuol dire che è acceso
      digitalWrite(rosso,LOW); // mettere il rosso a LOW vuol dire accendere il reley
      Serial.println(" on");
    }
    else{
      digitalWrite(rosso,HIGH);
      Serial.println(" off");
    }
  }

  // 3-verde 
  if(inputString == "G"){ // se l'input è G di green
    cntVerde++;
    Serial.print(V);
    if(cntVerde %2 == 1){ // se è dispari vuol dire che è acceso
      digitalWrite(verde,LOW); // mettere il rosso a LOW vuol dire accendere il reley
      Serial.println(" on");
    }
    else{
      digitalWrite(verde,HIGH);
      Serial.println(" off");
    }
  }

  // 4-blue
    if(inputString == "B"){ // se l'input è B di blue
    cntBlue++;
    Serial.print(Bl);
    if(cntBlue%2==1){ // se è dispari vuol dire che è acceso
      digitalWrite(blue,LOW); // mettere il rosso a LOW vuol dire accendere il reley
      Serial.println(" on");
    }
    else{
      digitalWrite(blue,HIGH);
      Serial.println(" off");
    }
  }

  // 5-bianco 
    if(inputString == "W"){ // se l'input è W di white
    cntBianco++;
    Serial.print(Bi);
    if(cntBianco %2 == 1){ // se è dispari vuol dire che è acceso
      digitalWrite(bianco,LOW); // mettere il rosso a LOW vuol dire accendere il reley
      Serial.println(" on");
    }
    else{
      digitalWrite(bianco,HIGH);
      Serial.println(" off");
    }
  }

  // motorino
   if(inputString == "U") // U di Up 
  { 
    Serial.print("Motorino SU ");
    flagMotorinoUp = true;
    Serial.println(flagMotorinoUp);
    t1 = millis(); // mi salvo il valore di millis
    flagMillis = true; // garantisco che dopo TIME secondi si fermi
  }

  if(inputString == "S" ) // S di Stop
  {
    Serial.println("Motorino Stop");
    flagMotorinoUp = false;
    flagMotorinoDown = false;
  }

  if(inputString == "D") // D di Down 
  { 
    Serial.print("Motorino Giu ");
    flagMotorinoDown = true;
    Serial.println(flagMotorinoDown);
    t1 = millis(); // mi salvo il valore di millis
    flagMillis = true; // garantisco che dopo TIME secondi si fermi
  }
  
  // Up
  if(flagMotorinoUp == true && inputString != "S")
  {
    //Serial.println("SU");
    myStepper.step(STEPS); // alza il razzo
  }

  // Down
  if(flagMotorinoDown == true && inputString != "S")
  {
    //Serial.println("giu");
    myStepper.step(-STEPS); // abbasso il razzo
  }

   dt = millis() -t1;
  
  if(dt > TIME && flagMillis) // quando è scaduto il tempo
  {
    Serial.print("sono passati ");
    Serial.println(TIME);
    flagMotorinoUp = false; // metto a false tutti i flag
    flagMotorinoDown = false;
    flagMillis = false;
    t1 = millis();
  }


  inputString=""; // resetto la stringa
 
  

}