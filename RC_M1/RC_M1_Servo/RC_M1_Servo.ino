#include <Servo.h>

Servo myServo;

int servoMax = 120;
//Only using 120 degrees 
int servoMin = 0;
int servoCurrent = 60;

int potMax = 1023;
int potMin = 0;

void setup() {
  // put your setup code here, to run once:

  myServo.attach(9);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  float sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(50);
  float angleChange = servoMax*((potMax - sensorValue)/potMax);
  Serial.println(angleChange);
  delay(50);

  myServo.write(angleChange);
  delay(100);

}
