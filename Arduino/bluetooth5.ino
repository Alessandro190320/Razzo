/**
 * @Author Alessandro190320 
 * Programma per testare l'antenna bluetooth con la porta seriale del computer
 * È possibile anche configurarlo con la modalità AT
 */
 
#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX, TX
String ricevuto;
boolean NL = true; // flag

void setup()
{
  Serial.begin(38400); // inzializzo la seriale a 38400 baud
  Serial.print("Sketch Uploaded"); // comunico che è stato caricato il codice
  Serial.println(" ");
  BTserial.begin(9600); // inizializzo la seriale del Bluetooth a 9600 
  Serial.println("BTserial started at 9600");
  Serial.println(" ");
}

void loop()
{
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BTserial.available() > 0){
    while(BTserial.available()){
      ricevuto += char(BTserial.read());
    }
    Serial.println(ricevuto);
    ricevuto= "";
  }
  delay(100);
   
}
