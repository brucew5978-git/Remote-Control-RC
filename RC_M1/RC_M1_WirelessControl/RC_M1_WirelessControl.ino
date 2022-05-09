#include <Servo.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "SPI.h"

Servo myServo;

// Servo pin numbers and var
int servoMax = 120;
//Only using 120 degrees 
//int servoMin = 0;
//int servoCurrent = 60;
const int X_MAX = 1023;
const int X_MIN = 0;
const int SERVO_PIN = 2;

// DC Motor pin
const int MOTOR_PIN1 = 6;
const int MOTOR_PIN2 = 7;
float forwardThreshold = 500;
float backwardThreshold = 100;

//Reciever
int ReceivedMessage[3] = {0}; // Used to store value received by the NRF24L01
RF24 radio(9,10); // NRF24L01 SPI pins. Pin 9 and 10 on the Nano
const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

bool reverse = false;

float test[4] = {300, 600, 300, 50};
int count = 0;

void setup() {
  Serial.begin(9600);
  
  myServo.attach(SERVO_PIN);

  //DC Motor
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);

  radio.begin(); // Start the NRF24L01
  radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
  radio.startListening(); // Listen to see if information received
}

void loop() {

  if(radio.available()){
    Serial.println("In");

    radio.read(ReceivedMessage, 6); // Read information from the NRF24L01
    //delay(50);
    //int button = ReceivedMessage[0];
    float sensorValueX = ReceivedMessage[1];
    float sensorValueY = ReceivedMessage[2];

    float angleChange = servoMax*((X_MAX - sensorValueX)/X_MAX);
    Serial.println(angleChange);
    myServo.write(angleChange);
    delay(50);

    /*if(count != 4){
      sensorValueY = test[count];
    } else {
      //sensorValueY = 300;
      //sensorValueX = 0;
      count = 0;
      sensorValueY = test[count];
    }*/
    

    //float angleChange = servoMax*((X_MAX - sensorValueX)/X_MAX);

    //Serial.print("Switch:  ");
    //Serial.println(button);
    Serial.print("X-axis: ");
    Serial.println(sensorValueX);
    Serial.print("Y-axis: ");
    Serial.println(sensorValueY);
    
    //delay(50);
  
    //myServo.write(angleChange);
    
    if(sensorValueY > forwardThreshold){
        digitalWrite(MOTOR_PIN1, HIGH);
        digitalWrite(MOTOR_PIN2, LOW);   
        //Serial.println("forward");
    } else if(sensorValueY < backwardThreshold){
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, HIGH);     
        //Serial.println("backward"); 
    } else {
        digitalWrite(MOTOR_PIN1, LOW);
        digitalWrite(MOTOR_PIN2, LOW);
        //Serial.println("Idle");
    }

    /*if(button == 0){
      Serial.println("Stop");
      delay(100000);
    }*/
    count++;
    Serial.println("Out");
    Serial.print("\n\n");
    //Serial.println(reverse);
    //Serial.println(digitalRead(SW_PIN));
    delay(50);
      
  } 
  else {
    Serial.println("No Signal");
    delay(50);
  }

}
