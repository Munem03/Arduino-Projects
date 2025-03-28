// C++ code
float temp;
float vout;
float vout1;
int LED = 13;
int gasSensor;
int piezo = 7;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(LED, OUTPUT); 
  pinMode(piezo, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read temperature sensor voltage
  vout = analogRead(A1);
  vout1 = (vout * 5000.0) / 1023.0; // Convert ADC reading to millivolts
  temp = (vout1 - 500) / 10.0; // Convert millivolts to temperature in °C

  // Read gas sensor value
  gasSensor = analogRead(A0);

  // Temperature warning
  if (temp >= 80) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  // Gas sensor warning
  if (gasSensor >= 100) {
    digitalWrite(piezo, HIGH);
  } else {
    digitalWrite(piezo, LOW);
  }

  // Print readings for debugging
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C");

  Serial.print("    Gas Sensor Value: ");
  Serial.println(gasSensor);

  delay(500); // Delay to stabilize readings
}
