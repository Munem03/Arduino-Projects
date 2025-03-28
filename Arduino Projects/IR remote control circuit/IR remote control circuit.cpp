#include <IRremote.h>  

int IR_Recv = 12;  // IR Receiver pin
int bluePin = 2;
int orangePin = 3;
int greenPin = 4;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_Recv, ENABLE_LED_FEEDBACK);  // Start the IR receiver

  pinMode(bluePin, OUTPUT);
  pinMode(orangePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {  // If IR signal is received
    long int decCode = IrReceiver.decodedIRData.command;
    Serial.println(decCode);  // Print received IR code
    IrReceiver.resume();  // Resume receiving IR signals

    switch (decCode) {
      case 16:  // Button "1"
        digitalWrite(bluePin, HIGH);
        break;
      case 17:  // Button "2"
        digitalWrite(bluePin, LOW);
        break;
      case 18:  // Button "3"
        digitalWrite(orangePin, HIGH);
        break;
      case 20:  // Button "4"
        digitalWrite(orangePin, LOW);
        break;
      case 21:  // Button "5"
        digitalWrite(greenPin, HIGH);
        break;
      case 22:  // Button "6"
        digitalWrite(greenPin, LOW);
        break;
    }
  }
}
