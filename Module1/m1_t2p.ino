const int motionSensorPin = 2; // Connects to the Pir Sensor Output pin
const int redLedMotionPin = 13; // Red LED Connects to the 13 on Arduino (indication motion)
const int greenLedNoMotionPin = 12; // Green LED Connects to 12 on Arduino (indication No motion)
volatile bool motionDetected = false; // Flag to indicate motion detection

void setup() {
  pinMode(motionSensorPin, INPUT); // Sets Motion Sensor as Input
  pinMode(redLedMotionPin, OUTPUT); // Sets Red LED pin as output
  pinMode(greenLedNoMotionPin, OUTPUT); // Sets Green LED pin as output
  Serial.begin(9600); // Initialize serial communication

  // Attach interrupt to the motion sensor pin, triggering on CHANGE
  attachInterrupt(digitalPinToInterrupt(motionSensorPin), motionISR, CHANGE);
}

void loop() 
{
  if (motionDetected)
  {
    digitalWrite(redLedMotionPin, HIGH); // Turn on the Red LED
    Serial.println("Motion detected! Red LED is ON.");
    digitalWrite(greenLedNoMotionPin, LOW); // Turn off the Green LED
    
    motionDetected = false; // Reset the flag
  } 
  else 
  {
    digitalWrite(redLedMotionPin, LOW); // Turn off the Red LED
    digitalWrite(greenLedNoMotionPin, HIGH); // Turn on the Green LED
    Serial.println("No motion. Green LED is ON.");
  }

  delay(1000); // Wait for 1000ms
}
// Interrupt Service Routine (ISR)
void motionISR() {
  motionDetected = true; // Set the flag when motion is detected
  Serial.println("Motion detected.");
}
