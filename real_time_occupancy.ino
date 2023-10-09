#define trigPin  9   // Arduino pin connected to trigger pin on the ultrasonic sensor
#define echoPin     10  // Arduino pin connected to echo pin on the ultrasonic sensor
#define maxDistance 100 // Maximum distance (in centimeters) to detect occupancy
#define ledPin      13  // Arduino pin connected to the LED


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  unsigned long pulseDuration = pulseIn(echoPin, HIGH); // Measure pulse width in microseconds
  
  unsigned int distance = pulseDuration / 58; // Convert pulse width to distance in centimeters
  
  if (distance < maxDistance) {
    digitalWrite(ledPin, HIGH); // Turn on the LED if an object is detected
    Serial.println("Occupied");
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED if no object is detected
    Serial.println("Vacant");
  }
  
  delay(100); // Delay for stability and to reduce serial output
}
