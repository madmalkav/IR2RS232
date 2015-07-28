#include <SoftwareSerial.h>
#include <IRremote.h>

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 6;
IRrecv irrecv(recvPin);
SoftwareSerial mySerial(10, 11); // RX, TX

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
    case 0xFFFFFFFF:      mySerial.println(lastCommand);      break;
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
      delay(45);                    // to avoid too fast repeats
      irrecv.resume();              // Prepare for the next value
    }
}

