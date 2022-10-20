
/**
   PIE-S2 Project 3
   Name: DC Motor Control
   Purpose: Control a robot using inputs from 2 IR reflectance sensors and outputting to 2 DC motors
   @author Miranda Pietraski, Cherry Pham, and Vaani Bhatnagar
   @version 1.0 10/19/2022
*/

#include <Adafruit_MotorShield.h>

// Naming the Adafruit Motor Shield as AFMS
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Initiating left and right motors
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);


// Selecting input pins for the IR sensor on the left and right
int sensorPinLeft = A1;   
int sensorPinRight = A0;

// Initializing variables to store values coming from the sensors
int sensorValueLeft = 0;
int sensorValueRight = 0;

// Initializing variable to store input from .py file
String input;

// Setup function that run once
void setup() {
  // Initiating sensors as inputs
  pinMode(sensorPinLeft, INPUT);
  pinMode(sensorPinRight, INPUT);

  // Initiating motorshield
  AFMS.begin();           

  // Initial motor set-ups
  leftMotor->run(FORWARD);
  leftMotor->setSpeed(0);
  rightMotor->run(FORWARD);
  rightMotor->setSpeed(0);

  // Begin serial - matching the serial number declared in .py file
  Serial.begin(9600);
}

// Loop through taking inputs from sensors and parsing resultance outputs to DC motors
void loop() {
  // Read sensors' values:
  sensorValueLeft = analogRead(sensorPinLeft);
  sensorValueRight = analogRead(sensorPinRight);
  // Speed changing through terminal interface
  // If receive signals from terminal through .py file
  if (Serial.available() > 0) {
    // Read until the end of a line
    input = Serial.readStringUntil('\n');

    // Left motor speed: 7xxx
    if (input.charAt(0)== '7') {
      // Take only speed data
      input = input.substring(1,4).toInt();
      // Adjust left motor's speed accordingly
      leftMotor->setSpeed(input.toInt());  
    }
    // Right motor speed: 8xxx
    if (input.charAt(0) == '8') {
      // Take only speed data
      input = input.substring(1,4).toInt();
      // Adjust right motor's speed accordingly
      rightMotor->setSpeed(input.toInt());
    }
  }
  // If receive no signal from terminal, proceed to default behavior
  else {
    // On: ~900
    // Off: ~700

    // sensor on the right detects the tape
    // turn left wheel, right wheel stationary
    if (sensorValueRight >= 850) {
      leftMotor->setSpeed(50);
      rightMotor->setSpeed(10);
    }
    // sensor on the left detects the tape
    // turn right wheel, left wheel stationary
    if (sensorValueLeft >= 850) {
      leftMotor->setSpeed(10);
      rightMotor->setSpeed(50);
    }
  }
}
