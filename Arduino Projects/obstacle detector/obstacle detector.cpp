int trigPin = 10;
int echoPin = 9;
long time;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // Short delay before triggering
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Proper pulse duration for the trigger
  digitalWrite(trigPin, LOW);

  time = pulseIn(echoPin, HIGH); // Measure echo pulse duration
  distance = time * 0.034 / 2;   // Convert to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  delay(500); // Small delay to stabilize readings
}
