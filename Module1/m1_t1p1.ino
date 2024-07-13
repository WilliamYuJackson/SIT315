const int motionSensorPin = 4; // Connects to the Pir Sensor Output pin
const int redLedMotionPin = 13; // Red LED Connects to the 13 on Arduino (indication motion)
const int greenLedNoMotionPin = 12; // Green LED Connects to 12 on Arduino (indication No motion)

void setup() 
{
  pinMode(motionSensorPin, INPUT); // Sets Motion Sensor as Input
  pinMode(redLedMotionPin, OUTPUT); // Sets Red LED pin as output
  pinMode(greenLedNoMotionPin, OUTPUT); // Sets Green LED pin as output
  Serial.begin(9600); // Initialize serial communication
}

void loop() 
{
  int motionState = digitalRead(motionSensorPin); // Read the state of the motion sensor
  Serial.print("Motion sensor state: ");
  Serial.println(motionState); // Print the raw sensor state

  if (motionState == HIGH) 
  {
    digitalWrite(redLedMotionPin, HIGH); // Turn on the Red LED
    digitalWrite(greenLedNoMotionPin, LOW); // Turn off the Green LED
    Serial.println("Motion detected! Red LED is ON.");
  } 
  else 
  {
    digitalWrite(redLedMotionPin, LOW); // Turn off the Red LED
    digitalWrite(greenLedNoMotionPin, HIGH); // Turn on the Green LED
    Serial.println("No motion. Green LED is ON.");
  }
  delay(500); // Wait 500ms
}
