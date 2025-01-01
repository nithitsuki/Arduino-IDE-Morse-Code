#include "Morse.h"

void setup()
{
    MORSE_PIN = 13; //set morse output pin
    UNIT_TIME = 150; //Time of dot in milliseconds (1200/wpm)  
    // int UNIT_TIME = 150; is wrong, dont do it
}
void loop()
{
    string_to_morse("HELLO WORLD");// Transmit the string "HELLO WORLD" repeatedly
}