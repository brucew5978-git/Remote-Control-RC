#include <Servo.h>

Servo myServo;

// Servo pin numbers and var
int servoMax = 120;
//Only using 120 degrees 
int servoMin = 0;
int servoCurrent = 60;
const int X_MAX = 1023;
const int X_MIN = 0;
const int SERVO_PIN = 9;

// Joystick pin numbers
const int SW_PIN = 2; // digital pin connected to switch output
const int X_PIN = A4; // analog pin connected to X output
const int Y_PIN = A5; // analog pin connected to Y output

// DC Motor pin
const int MOTOR_PIN1 = 6;
const int MOTOR_PIN2 = 7;

bool reverse = false;

void setup() {

  myServo.attach(SERVO_PIN);

  //Joystick setup
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);
  Serial.begin(115200);

  //DC Motor
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
}

void loop() {
  float sensorValueX = analogRead(X_PIN);
  float sensorValueY = analogRead(Y_PIN);
  delay(50);
  float angleChange = servoMax*((X_MAX - sensorValueX)/X_MAX);
  reverse = digitalRead(SW_PIN);
  delay(50);

  myServo.write(angleChange);
  if(sensorValueY > 800){
      digitalWrite(MOTOR_PIN1, HIGH);
      digitalWrite(MOTOR_PIN2, LOW);   
  } else if(sensorValueY < 200){
      digitalWrite(MOTOR_PIN1, LOW);
      digitalWrite(MOTOR_PIN2, HIGH);      
  } else {
      digitalWrite(MOTOR_PIN1, LOW);
      digitalWrite(MOTOR_PIN2, LOW);
  }
  delay(50);
  //Serial.println(reverse);
  Serial.println(sensorValueX);
  Serial.println(sensorValueY);
  Serial.println(digitalRead(SW_PIN));
  //delay(500);
  
}
