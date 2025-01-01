#ifndef MORSE_H
#define MORSE_H

#include <Arduino.h>

int MORSE_PIN = 13; //set morse output pin
int UNIT_TIME = 150; //Time of dot (dit) in ms (default: 8wpm)
#define CHAR_SPACE_TIME 3 * UNIT_TIME // Time to wait for whitespaces in transmission
#define WORD_SPACE_TIME 7 * UNIT_TIME // Time to wait for whitespaces in transmission
#define DASH_TIME UNIT_TIME*3 // leave this line alone

static inline void dot(int n)
{
	for(int i = 0; i < n; i++)
    {
  		digitalWrite(MORSE_PIN, HIGH); 
  		delay(UNIT_TIME);            
  		digitalWrite(MORSE_PIN, LOW);  
  		delay(CHAR_SPACE_TIME);           
	}
	
}

static inline void dash(int n)
{
	for(int i = 0; i < n; i++)
    {
		digitalWrite(MORSE_PIN, HIGH);
		delay(DASH_TIME);            
  		digitalWrite(MORSE_PIN, LOW);  
  		delay(CHAR_SPACE_TIME);           
	}
}

static inline void char_to_morse(char c)
{
    switch (toLowerCase(c))
    {
        case 'a': dot(1); dash(1); break;
        case 'b': dash(1); dot(2); dot(1); break;
        case 'c': dash(1); dot(1); dash(1); dot(1); break;
        case 'd': dash(1); dot(2); break;
        case 'e': dot(1); break;
        case 'f': dot(2); dash(1); dot(1); break;
        case 'g': dash(2); dot(1); break;
        case 'h': dot(2); dot(2); break;
        case 'i': dot(2); break;
        case 'j': dot(1); dash(2); dash(1); break;
        case 'k': dash(1); dot(1); dash(1); break;
        case 'l': dot(1); dash(1); dot(2); break;
        case 'm': dash(2); break;
        case 'n': dash(1); dot(1); break;
        case 'o': dash(2); dash(1); break;
        case 'p': dot(1); dash(2); dot(1); break;
        case 'q': dash(2); dot(1); dash(1); break;
        case 'r': dot(1); dash(1); dot(1); break;
        case 's': dot(2); dot(1); break;
        case 't': dash(1); break;
        case 'u': dot(2); dash(1); break;
        case 'v': dot(2); dot(1); dash(1); break;
        case 'w': dot(1); dash(2); break;
        case 'x': dash(1); dot(2); dash(1); break;
        case 'y': dash(1); dot(1); dash(2); break;
        case 'z': dash(2); dot(2); break;
        case '0': dash(2); dash(2); dash(2); dash(2); dash(2); break;
        case '1': dot(1); dash(2); dash(2); dash(2); dash(2); break;
        case '2': dot(2); dot(1); dash(2); dash(2); dash(2); break;
        case '3': dot(3); dot(1); dot(1); dash(2); dash(2); break;
        case '4': dot(4); dot(1); dot(2); dash(2); break;
        case '5': dot(5); dot(1); dot(2); dot(2); break;
        case '6': dash(1); dot(4); dot(1); dot(2); break;
        case '7': dash(2); dot(3); dot(1); dash(1); break;
        case '8': dash(3); dot(2); dot(1); dash(1); break;
        case '9': dash(4); dot(1); dot(1); dot(1); break;
        case '.': dot(1); dash(1); dot(1); dash(1); break;    
        case ',': dash(2); dot(2); dash(2); dot(2); break;    
        case '?': dot(2); dot(1); dash(2); dot(1); break;   
        case '\'': dot(1); dash(2); dash(2); dash(2); dot(1); break; 
        case '!': dash(1); dot(1); dash(2); dot(2); break; 
        case '/': dash(1); dot(1); dot(1); dash(1); break;
        case '(': dash(1); dot(1); dash(2); dot(1); break;
        case ')': dash(1); dot(1); dash(2); dot(1); dash(1); break;
        case '&': dot(1); dash(1); dot(1); dash(1); break;
        case ':': dash(2); dot(1); dash(2); dot(1); dash(2); break;
        case ';': dash(1); dot(1); dash(1); dot(1); dash(1); break;
        case '=': dash(1); dot(1); dot(1); dash(1); break; 
        case '+': dot(1); dash(1); dot(1); dash(1); dot(1); break;
        case '-': dash(1); dot(1); dot(1); dot(1); dash(1); break;
        case '"': dot(1); dash(1); dot(1); dot(1); dash(1); dot(1); break;
        case '$': dot(2); dot(2); dash(1); dot(1); dot(1); break; 
        case '_': dot(2); dash(1); dot(2); dash(1); break;
        case ' ': delay(WORD_SPACE_TIME); break;  // Space (Word separator)
    }
}

static inline void string_to_morse(String mCode)
{
    for (int i = 0; i < mCode.length(); i++)
    {
        char_to_morse(mCode.charAt(i));
    }
}

#endif