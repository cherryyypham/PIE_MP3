
int sensorPinLeft = A1;   // select the input pin for the IR sensor on the left
int sensorPinRight = A0;  // select the input pin for the IR sensor on the right

int sensorValueLeft = 0;  // variable to store the value coming from the sensor
int sensorValueRight = 0;  // variable to store the value coming from the sensor

void setup() {
  pinMode(sensorPinLeft, INPUT);
  pinMode(sensorPinRight, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValueLeft = analogRead(sensorPinLeft);
  sensorValueRight = analogRead(sensorPinRight);
  delay(500);
  Serial.println(sensorValueLeft);
  Serial.println(sensorValueRight);
  // On: 900 sth
  // Off: 700 sth
  
  if (sensorValueLeft < 850) {    //Off tape
    if (sensorValueRight >= 850) {  //On tape
      Serial.println("Turn left wheel, right wheel stationary");
    }
    else {
      Serial.println("Turn right wheel, left wheel stationary");
    }
  }
  else {
    Serial.println("Go straight");
  }
  
  
}
