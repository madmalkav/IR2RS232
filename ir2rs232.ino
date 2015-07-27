#include <SoftwareSerial.h>
#include <IRremote.h>

//------------------------------------------------------------------------------
// Tell IRremote which Arduino pin is connected to the IR Receiver (TSOP4838)
//
int recvPin = 6;
IRrecv irrecv(recvPin);
SoftwareSerial mySerial(10, 11); // RX, TX

//+=============================================================================
// Configure the Arduino
//
void  setup ( )
{
  //Serial.begin(9600);   // Status message will be sent to PC at 9600 baud
  mySerial.begin(9600); // RS232 output
  //mySerial.println("Inicializando...");
  irrecv.enableIRIn();  // Start the receiver
  irrecv.blink13(true);
}

//+=============================================================================
// Translate to RS232
//
void  translate (decode_results *results)
{
  switch ((results->value)) {
    // INSERT YOUR DATA.TXT HERE
    case 0x01080:      mySerial.println("k a 0 00");       break ;  // Power Off

    case 0x81080:      mySerial.println("k a 0 01");       break ;  // Power On
    
    case 0x41080:      mySerial.println("m c 0 08");       break ;  // Power Toggle
    
    case 0xC1080:      mySerial.println("k c 0 01");       break ;  // Aspect Ratio 4:3
    
    case 0x21080:      mySerial.println("k c 0 02");       break ;  // Aspect Ratio16:9
    
    case 0xA1080:      mySerial.println("k c 0 09");       break ;  // Aspect Ratio Just Scan
    
    case 0x61080:      mySerial.println("k e 0 00");       break ;  // Mute On
    
    case 0xE1080:      mySerial.println("k e 0 01");       break ;  // Mute Off
    
    case 0x11080:      mySerial.println("m c 0 09");       break ;  // Mute Toggle
    
    case 0x91080:      mySerial.println("m c 0 02");       break ;  // Volume Up
    
    case 0x51080:      mySerial.println("m c 0 03");       break ;  // Volume Down
    
    case 0xD1080:      mySerial.println("j p 0 02");       break ;  // ISM Orbiter
    
    case 0x31080:      mySerial.println("j p 0 20");       break ;  // ISM Colour Wash
    
    case 0xB1080:      mySerial.println("x b 0 00");       break ;  // Input DTV
    
    case 0x71080:      mySerial.println("x b 0 90");       break ;  // Input HDMI1
    
    case 0xF1080:      mySerial.println("x b 0 91");       break ;  // Input HDMI2
    
    case 0x09080:      mySerial.println("x b 0 92");       break ;  // Input HDMI3
    
    case 0x89080:      mySerial.println("m c 0 00");       break ;  // Channel +
    
    case 0x49080:      mySerial.println("m c 0 01");       break ;  // Channel -
    
    case 0xC9080:      mySerial.println("m c 0 72");       break ;  // RED
    
    case 0x29080:      mySerial.println("m c 0 71");       break ;  // GREEN
    
    case 0xA9080:      mySerial.println("m c 0 63");       break ;  // YELLOW
    
    case 0x69080:      mySerial.println("m c 0 61");       break ;  // BLUE
    
    case 0xE9080:      mySerial.println("m c 0 40");       break ;  // Arrow Up
    
    case 0x19080:      mySerial.println("m c 0 41");       break ;  // Arrow Down
    
    case 0x99080:      mySerial.println("m c 0 07");       break ;  // Arrow Left
    
    case 0x59080:      mySerial.println("m c 0 06");       break ;  // Arrow Right
    
    case 0xD9080:      mySerial.println("m c 0 45");       break ;  // Quick Menu
    
    case 0x39080:      mySerial.println("m c 0 AA");       break ;  // Info
    
    case 0xB9080:      mySerial.println("m c 0 AB");       break ;  // Guide
    
    case 0x79080:      mySerial.println("m c 0 F0");       break ;  // TV/RADIO
    
    case 0xF9080:      mySerial.println("m c 0 0B");       break ;  // Input Cicle
    
    case 0x05080:      mySerial.println("m c 0 10");       break ;  // Number 0
    
    case 0x85080:      mySerial.println("m c 0 11");       break ;  // Number 1
    
    case 0x45080:      mySerial.println("m c 0 12");       break ;  // Number 2
    
    case 0xC5080:      mySerial.println("m c 0 13");       break ;  // Number 3
    
    case 0x25080:      mySerial.println("m c 0 14");       break ;  // Number 4
    
    case 0xA5080:      mySerial.println("m c 0 15");       break ;  // Number 5
    
    case 0x65080:      mySerial.println("m c 0 16");       break ;  // Number 6
    
    case 0xE5080:      mySerial.println("m c 0 17");       break ;  // Number 7
    
    case 0x15080:      mySerial.println("m c 0 18");       break ;  // Number 8
    
    case 0x95080:      mySerial.println("m c 0 19");       break ;  // Number 9
    
    case 0x55080:      mySerial.println("m c 0 43");       break ;  // Menu
    
    case 0xD5080:      mySerial.println("m c 0 44");       break ;  // OK
    
    case 0x35080:      mySerial.println("m c 0 28");       break ;  // Return / Exit
    
    case 0xB5080:      mySerial.println("m c 0 30");       break ;  // AV Mode
    
    case 0x75080:      mySerial.println("m c 0 1E");       break ;  // FAV(MARK)
    
    case 0xF5080:      mySerial.println("m c 0 53");       break ;  // List
    
    case 0x0D080:      mySerial.println("m c 0 1A");       break ;  // Q.View
    
    case 0x8D080:      mySerial.println("m c 0 20");       break ;  // Text
    
    case 0x4D080:      mySerial.println("m c 0 21");       break ;  // T.Opt
    
    case 0xCD080:      mySerial.println("m c 0 39");       break ;  // Subtitle
    
    case 0x2D080:      mySerial.println("m c 0 7E");       break ;  // Simplink
    
    case 0xAD080:      mySerial.println("m c 0 95");       break ;  // Power Saving
    
    case 0x6D080:      mySerial.println("m c 0 65");       break ;  // Freeze
    
    case 0xED080:      mySerial.println("m c 0 79");       break ;  // Ratio
    
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

