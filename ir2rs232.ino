#include <IRremote.h>
#include <IRremoteInt.h>
#include <SoftwareSerial.h>



//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 3;
int blinkPin = 4;
IRrecv irrecv(recvPin, blinkPin);
SoftwareSerial mySerial(11, 10); // RX, TX



//------------------------------------------------------------------------------
// We use this string for repeat commands
String lastCommand = String("");

//+=============================================================================
// Configure the Arduino
//
void  setup ( )
{
  mySerial.begin(9600); // RS232 output
  irrecv.enableIRIn();  // Start the receiver
  irrecv.blink13(true);
}

//+=============================================================================
// Translate to RS232
//
void  translate (decode_results *results)
{
  switch ((results->value)) {
    // INSERT YOUR DATA.TXT FROM HERE

    // TO HERE
    case 0xFFFFFFFF:      mySerial.println(lastCommand);     delay(45);      break;
  }
}


//+=============================================================================
// The repeating section of the code
//
void  loop ( )
{
    decode_results  results;        // Somewhere to store the results
    if (irrecv.decode(&results)) {  // Grab an IR code
    translate(&results);
    irrecv.resume();              // Prepare for the next value
    }
}

