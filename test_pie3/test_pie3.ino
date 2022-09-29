
int sensorPinA = A0;    // select the input pin for the potentiometer
int sensorPinD = 2;
int ledPin = 13;      // select the pin for the LED
int sensorValueA = 0;  // variable to store the value coming from the sensor
int sensorValueD = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(sensorPinA, INPUT);
  pinMode(sensorPinD, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValueA = analogRead(sensorPinA);
  sensorValueD = digitalRead(sensorPinD);
  Serial.println(sensorValueA);
  delay(3000);
  
}
