// Initialize Pins
int analogPin = 0;
int chargePin = 8;
int dischargePin = 9; // Speeds up discharging, but not necessary

// Initialize Resistor
int resistorValue = 10000; // 10kΩ Resistor

// Initialize Timer
unsigned long startTime;
unsigned long elapsedTime;

// Initialize Capacitance Variables
float microFarads;
float nanoFarads;

void setup() {
    pinMode(chargePin, OUTPUT);
    digitalWrite(chargePin, LOW);
    Serial.begin(9600); // Necessary for serial output
}

void loop() {
    digitalWrite(chargePin, HIGH); // Start charging the capacitor
    startTime = millis(); // Start timing

    while (analogRead(analogPin) < 610) {
        // Wait until the capacitor reaches 63.2% of total voltage
    }

    elapsedTime = millis() - startTime; // Time taken for charging
    microFarads = ((float)elapsedTime / resistorValue) * 1000;

    Serial.print(elapsedTime);
    Serial.print(" ms ");

    if (microFarads > 1) {
        Serial.print((long)microFarads);
        Serial.println(" microFarads");
    } else {
        nanoFarads = microFarads * 1000.0;
        Serial.print((long)nanoFarads);
        Serial.println(" nanoFarads");
    }

    delay(500); // Short delay before discharging

    digitalWrite(chargePin, LOW); // Stop charging
    pinMode(dischargePin, OUTPUT);
    digitalWrite(dischargePin, LOW); // Discharge the capacitor

    while (analogRead(analogPin) > 0) {
        // Wait until capacitor is fully discharged
    }

    pinMode(dischargePin, INPUT); // Stop discharging
}
