/**
 * @Author Alessandro190320 
 * Programma per testare l'antenna bluetooth con la porta seriale del computer
 * È possibile anche configurarlo con la modalità AT
 */
 
#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX, TX
char c=' '; // varile di tipo carattere vuota per leggere i caratteri dalla seriale
boolean NL = true; // flag

void setup()
{
  Serial.begin(38400); // inzializzo la seriale a 38400 baud
  Serial.print("Sketch Uploaded"); // comunico che è stato caricato il codice
  Serial.println(" ");
  BTserial.begin(9600); // inzializzo la seriale a 9600 baud
  Serial.println("BTserial started at 9600");
  Serial.println(" ");
}

void loop()
{
  // Read from the Bluetooth module and send to the Arduino Serial Monitor
  if (BTserial.available()){
    c = BTserial.read();
    Serial.print(c);
  }

  // Read from the Serial Monitor and send to the Bluetooth module
  if (Serial.available()){
    c = char (Serial.read()); 
    BTserial.print(c);
    // Echo the user input to the main window. The ">" character indicates the user entered text.
    if (NL) { 
      Serial.print(">");
      NL = false; 
    }
    Serial.write(c);
    if (c==10) { NL = true; }
    } 
}
