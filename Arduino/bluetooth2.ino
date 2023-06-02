/**
* Source code:
* https://www.italiantechproject.it/tutorial-arduino/bluetooth-hc-05
*/
#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(10, 11); // RX | TX
 
void setup(){
  pinMode ( 9, OUTPUT );
  digitalWrite(9, HIGH);
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);
  
}
 
void loop(){
  if(BTSerial.available()){
    Serial.write("ON");
    Serial.write(BTSerial.read());
  }
  else{
    Serial.write("\nOFF");
  }
  
  if(Serial.available()){
    BTSerial.write(Serial.read());
  }
  delay(1000);
}
