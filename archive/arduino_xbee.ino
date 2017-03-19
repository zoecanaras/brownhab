/*
  Xbee1
  D. Thiebaut
  
  Makes Arduino send 1 character via XBee wireless to another XBee connected
  to a computer via a USB cable. 

  The circuit: 
  * RX is digital pin 2 (connect to TX of XBee)
  * TX is digital pin 3 (connect to RX of XBee)
 
  Based on a sketch created back in the mists of time by Tom Igoe
  itself based on Mikal Hart's example
 
*/

// Xbee 1 to 3.3V
// Xbee 2 to Arduino RX2
// Xbee 3 to Arduino TX2
// Xbee bottom left to Arduino Ground


//#include <SoftwareSerial.h>

//SoftwareSerial xbee(2, 3); // RX, TX
char c = 'A';
int  pingPong = 1;

void setup()  {
   Serial.begin(19200);
   Serial2.begin(19200);
   Serial.println( "Arduino started sending bytes via XBee" );

   // set the data rate for the SoftwareSerial port
   //xbee.begin( 19200 );
}

void loop()  {
  // send character via XBee to other XBee connected to Mac
  // via USB cable
  Serial2.write( c );
  
  //--- display the character just sent on console ---
  Serial.println( c );
  
  //--- get the next letter in the alphabet, and reset to ---
  //--- 'A' once we have reached 'Z'. 
  c = c + 1;
  if ( c>'Z' ) 
       c = 'A';
  
  //--- switch LED on Arduino board every character sent---
  if ( pingPong == 0 )
    digitalWrite(13, LOW);
  else
    digitalWrite(13, HIGH);
  pingPong = 1 - pingPong;
  delay( 1000 );

 //read
 if (Serial2.read() != -1) {
    char RX = Serial2.read();
    Serial.print(RX);
 }
}
