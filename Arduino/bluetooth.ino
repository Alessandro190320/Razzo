/**
* Source code:
* https://www.italiantechproject.it/tutorial-arduino/bluetooth-hc-05
*/
#include <SoftwareSerial.h>
 
SoftwareSerial BTSerial(2, 3); // RX | TX
 
void setup(){
  Serial.begin(38400);
  BTSerial.begin(38400);
  if(BTSerial.isListening())
      Serial.write("software serial avviato\n");
  delay(1000);
  Serial.write("Avviato");
}
 
void loop(){
  if(BTSerial.available() > 0){
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
