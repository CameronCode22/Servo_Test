#include <Servo.h>

Servo myservo;  // Create servo object to control a servo
const int buttonPin = 2; //
int buttonState = 0; //Variable for button state False to start
unsigned long startTime = 0;  // Variable to store the start time of the timer
unsigned long timerDuration = 5000;  // Timer duration in milliseconds (5 seconds)

void setup() {
  myservo.attach(9);  // Attach the servo on pin 9 to the servo object
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    myservo.write(180);
    startTime = millis(); // Start the timer

  } 
  
  else if (buttonState == LOW && millis()- startTime > timerDuration) {
    digitalWrite(LED_BUILTIN, LOW);
    myservo.write(0);
  }

  delay(15);  // Small delay for smoother operation
}
