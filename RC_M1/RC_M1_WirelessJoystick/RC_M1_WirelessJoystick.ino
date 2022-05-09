#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A4; // analog pin connected to X output
const int Y_pin = A5; // analog pin connected to Y output

int SentMessage[3] = {0}; 
RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup()
{
  Serial.begin(9600);
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
}

void loop()
{
      //SentMessage[0] = digitalRead(SW_pin);
      SentMessage[1] = analogRead(X_pin);
      SentMessage[2] = analogRead(Y_pin);
      radio.write(SentMessage, sizeof(SentMessage));      // Send pressed data to NRF24L01
      //sizeof = byte used by SentMessage, so 2nd var indicates number of bytes htat needs to be taken from the sent message

      /*Serial.println(sizeof(SentMessage));
      Serial.print("Switch:  ");
      Serial.print(digitalRead(SW_pin));
      Serial.print("\n");
      Serial.println(SentMessage[0]);
      
      Serial.print("X-axis: ");
      Serial.print(analogRead(X_pin));   
      Serial.print("\n");
      Serial.println(SentMessage[1]);
     
      Serial.print("Y-axis: ");
      Serial.println(analogRead(Y_pin));
      Serial.println(SentMessage[2]);
      Serial.print("\n\n");*/
      delay(10);
}
