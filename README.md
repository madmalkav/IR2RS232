# IR2RS232

This is a quick project for converting IR signals from an universal remote
to RS232 commands.

It currently works with sony20 remote signals. You have to fill the data.csv
file with the needed info and run the parser to generate the list of inputs
and outputs in the file data.txt. Program doesn't check the data.csv format
so be cautious of respecting the format. Also avoid characters like \ , "
and basically anything you can't directly write to a string without an
escape character. English letters, numbers, +, -, <, > and . are perfectly
safe. The data.csv included as example is the one I use for my LG50PS300 TV.

Paste the contents of data.txt in the arduino program where it says so,
compile, and TA-DAH.

This software uses arduino libraries IRremote and SoftSerial, so license is
whatever that libraries enforce.

For the hardware part, you need a led conected with a resistor to Arduino
port 13, an IR receiver -I tested with a osrb38c9aa-, and a MAX232N or
compatible. The MAX232N must have:

A 1uF cap between pin 1 (+) and 3(-), a 1uF between 4 (+) and 5(-),
a 1uF cap between 6(-) and ground, a 1uf cap between 2(+) and ground(-),
a 1uF cap between 16(+) and ground, 5V on pin 16, ground on pin 15,
pin 9 to arduino pin 10, pin 10 to arduino pin 11, pin 8 to RS232 pin 3
and pin 7 to RS232 pin 2.

I have almost no idea of programming or electronics, but I will gladly
receive comments and ideas, please use this forum thread for that:

http://www.hifi-remote.com/forums/viewtopic.php?t=16224

## Version 1.0

Initial Commit