#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

//#define SwitchPin 2 

int SentMessage[1] = {000}; 
RF24 radio(9,10); // NRF24L01 used SPI pins + Pin 9 and 10 on the NANO

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup()
{
  //pinMode(SwitchPin, INPUT_PULLUP); 
  //digitalWrite(SwitchPin,HIGH); 
  
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
  Serial.begin(9600);
}

void loop()
{
      SentMessage[0] = 111;
      radio.write(SentMessage, 1);      // Send pressed data to NRF24L01
      Serial.println(SentMessage[0]);
      Serial.println(SentMessage[1]);
      delay(1000);

      SentMessage[0] = 222;
      radio.write(SentMessage, 1);      // Send pressed data to NRF24L01
      Serial.println(SentMessage[0]);
      Serial.println(SentMessage[1]);
      delay(1000);

      SentMessage[0] = 333;
      radio.write(SentMessage, 1);      // Send pressed data to NRF24L01
      Serial.println(SentMessage[0]);
      Serial.println(SentMessage[1]);
      delay(1000);
}
