#include <Keypad.h>

const byte ROWS = 4; // Number of rows in keypad
const byte COLS = 4; // Number of columns in keypad

// Define the key layout of the 4x4 keypad
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Connect these pins to the keypad
byte rowPins[ROWS] = {9, 8, 7, 6}; // Row pins
byte colPins[COLS] = {5, 4, 3, 2}; // Column pins

// Create keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    Serial.begin(9600); // Initialize serial communication
}

void loop() {
    char key = keypad.getKey(); // Read the keypress

    if (key) { // If a key is pressed
        Serial.print("Key Pressed: ");
        Serial.println(key);
    }
}
