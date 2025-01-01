# Morse Code Library For Arduino IDE
This library allows the generation of Morse code signals through an Arduino pin.
It provides functions for setting pin outputs, adjusting Morse code speed (WPM), and converting characters to Morse code signals.

### **IMPORT THE LIBRARY**
Go to your Arduno IDE > Sketch > Add File...
and choose the Morse.h you downloaded from the Release page

### **USAGE**

#### `MORSE_PIN = 13;`
- **Description**: Sets the pin that will output Morse code signals.
- The Variable is already set in the header file Morse.h, please dont re-initialize it
  
#### `UNIT_TIME = 150;`
- **Description**: Sets the speed of the Morse code transmission in milliseonds.
  - **Note**: The time for a dot is calculated as `1200 / wpm`ms, which adjusts the speed of transmission.
- The Variable is already set in the header file Morse.h, please dont re-initialize it


#### `dot(int n)`
- **Description**: Sends the dot (dit) signal for a specified number of repetitions.
- **Parameters**:
  - `n`: The number of dots to send. MUST BE GREATER THAN OR EQUAL TO 1
  
#### `dash(int n)`
- **Description**: Sends the dash (dah) signal for a specified number of repetitions.
- **Parameters**:
  - `n`: The number of dots to send. MUST BE GREATER THAN OR EQUAL TO 1
  
#### `char_to_morse(char c)`
- **Description**: Converts a single character to its Morse code equivalent and sends the signal for that character.
- **Parameters**:
  - `c`: The character to convert to Morse code. This function handles both uppercase and lowercase letters, digits, and space.
  - **Supported characters**:
    - Letters: a-z (both uppercase and lowercase).
    - Digits: 0-9.
    - Space (`' '`): Represents a word space.

#### ` string_to_morse(String mCode)`
- **Description**: Converts an entire string to Morse code and transmits it, character by character.
- **Parameters**:
  - `mCode`: The string to convert to Morse code.

---

### **Usage Example**

```cpp
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
```

### **Explanation**
- In the example above, the `setup()` function configures the Morse code output pin and speed
- The `string_to_morse()` function calls `char_to_morse()` for each character in the string, converting them to their Morse code representation and transmitting them through the output pin.
---

