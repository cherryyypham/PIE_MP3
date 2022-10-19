//#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Naming the Adafruit Motor Shield as AFMS
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);   // initiating left motor
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);  // inititating right motor

int sensorPinLeft = A1;   // select the input pin for the IR sensor on the left
int sensorPinRight = A0;  // select the input pin for the IR sensor on the right

int sensorValueLeft = 0;  // variable to store the value coming from the sensor
int sensorValueRight = 0;  // variable to store the value coming from the sensor

String input;       // variable to store input from .py file

void setup() {
  // initiating sensors
  pinMode(sensorPinLeft, INPUT);
  pinMode(sensorPinRight, INPUT);

  // initiating motorshield
  AFMS.begin();           

  // initial motor set-ups
  leftMotor->run(FORWARD);
  leftMotor->setSpeed(0);
  rightMotor->run(FORWARD);
  rightMotor->setSpeed(0);

  // begin serial - matching the serial number declared in python file
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValueLeft = analogRead(sensorPinLeft);
  sensorValueRight = analogRead(sensorPinRight);

  // print out sensor values - crucial to test if sensors are reading
  // because our sensors' connection is bad
//  Serial.println(sensorValueLeft);
//  Serial.println(sensorValueRight);
  // On: 900 sth
  // Off: 700 sth
  
  if (Serial.available() > 0) {
    input = Serial.readStringUntil('\n');
    Serial.write("RECEIVED");
    leftMotor->setSpeed(30);
    rightMotor->setSpeed(30);
    if (input == "n") {
      if (sensorValueRight >= 850) {
//          Serial.println("Turn left wheel, right wheel stationary");
          Serial.write("RIGHT");
          leftMotor->setSpeed(50);
          rightMotor->setSpeed(10);
      }
      else if (sensorValueLeft >= 850) {
//          Serial.println("Turn right wheel, left wheel stationary");
          Serial.write("LEFT");
          leftMotor->setSpeed(10);
          rightMotor->setSpeed(50);
      }
      
    }
    if (input == "s") {
      leftMotor->setSpeed(0);
      rightMotor->setSpeed(0);      
    }
//
//
//    if (input == "r") {
//      if (sensorValueLeft >= 850) {
////        Serial.println("Turn right wheel, left wheel stationary");
//        leftMotor->setSpeed(0);
//        rightMotor->setSpeed(40);
//      }
//      else if (sensorValueRight >= 850) {
//          leftMotor->setSpeed(40);
//          rightMotor->setSpeed(0);
//      }
//      else if (sensorValueLeft >= 850 and sensorValueRight >= 850) {
//    
////        Serial.println("Sharp turnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn1");
//        leftMotor->setSpeed(250);
//        rightMotor->setSpeed(0);
//        delay(100);
//      }
//      else {
////        Serial.println("Go straight");
//        leftMotor->setSpeed(25);
//        rightMotor->setSpeed(25);
//      }
//    if (input.charAt(0)== '7') {
//      input = input.substring(1,4).toInt();
//      leftMotor->setSpeed(input.toInt());
//      rightMotor->setSpeed(0);
//      Serial.write("LEFT");
//      
//    }
//    if (input.charAt(0) == '8') {
//      input = input.substring(1,4).toInt();
//      rightMotor->setSpeed(input.toInt());
//      leftMotor->setSpeed(0);
//      Serial.write("RIGHT");
//    }
//    } 
  }
//        if (sensorValueRight >= 850) {
////          Serial.println("Turn left wheel, right wheel stationary");
//          leftMotor->setSpeed(50);
//          rightMotor->setSpeed(10);
//      }
//      else if (sensorValueLeft >= 850) {
////          Serial.println("Turn right wheel, left wheel stationary");
//          leftMotor->setSpeed(10);
//          rightMotor->setSpeed(50);
//      }
}
