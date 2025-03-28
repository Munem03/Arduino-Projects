// C++ code
//
int temp=A0;
float Voltage;
float temp_celsius;
float analog_reading;
float temp_far;

void setup()
{
  pinMode(A0, INPUT);
Serial.begin(9600);

}


void loop()
{
  analog_reading=analogRead(A0);
  Serial.print("Analog reading:");
  Serial.println(analog_reading);
Voltage=analog_reading*5/1024;
  Serial.print("volatge reading:");
  Serial.println(Voltage);
  temp_celsius=100*(Voltage-0.5);
  Serial.println("Celsius reading:"+String(temp_celsius)+(" C"));
  temp_far=(temp_celsius* 9/5)+32;
  Serial.println("Fahrenheit reading:"+String(temp_far)+(" f"));
}