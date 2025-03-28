// C++ code
//
#include <Keypad.h>

const byte row = 4;
const byte col = 4;
const int redLed = 10;
const int greenLed = 11;
const int piezo = 12;

char numPad[row][col] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPin[row] = {9, 8, 7, 6};
byte colPin[col] = {5, 4, 3, 2};

String pass = "1234";
String vstup = "";

Keypad cKeypad = Keypad(makeKeymap(numPad), rowPin, colPin, row, col);

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(piezo, OUTPUT);

  digitalWrite(redLed, HIGH);  // Red LED on (locked)
  digitalWrite(greenLed, LOW); // Green LED off

  Serial.begin(9600);
  Serial.println("Enter password:");
}

void loop() {
  char cKey = cKeypad.getKey();

  if (cKey) {
    if (vstup.length() < 4) {
      Serial.print("*");  // Hide password input
      vstup += cKey;
    }
  }

  if (vstup.length() == 4) {  // Password entered completely
    delay(1000);

    if (vstup == pass) {  // ✅ Correct Password
      Serial.println("\nAccess Granted");
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);

      // ✅ Single beep for success
      tone(piezo, 1000);
      delay(500);
      noTone(piezo);
    } 
    else {  // ❌ Incorrect Password
      Serial.println("\nWrong Password");
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);

      // ❌ Three beeps for wrong password
      for (int i = 0; i < 3; i++) {
        tone(piezo, 1000);
        delay(300);
        noTone(piezo);
        delay(300);
      }
    }

    delay(1500);
    vstup = ""; // Reset entered password
    Serial.println("Enter password:");
    
    // Reset LEDs
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
}
