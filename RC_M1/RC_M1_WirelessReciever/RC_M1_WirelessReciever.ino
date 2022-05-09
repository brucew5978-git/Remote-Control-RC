#include "nRF24L01.h" // NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

int ReceivedMessage[3] = {0}; // Used to store value received by the NRF24L01
RF24 radio(9,10); // NRF24L01 SPI pins. Pin 9 and 10 on the Nano

const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01 

void setup(void)
{
  Serial.begin(9600);
  radio.begin(); // Start the NRF24L01
  radio.openReadingPipe(1,pipe); // Get NRF24L01 ready to receive
  radio.startListening(); // Listen to see if information received
}

void loop(void)
{
  while (radio.available())
  {
    radio.read(ReceivedMessage, 6); // Read information from the NRF24L01

    Serial.print("Switch:  ");
    Serial.println(ReceivedMessage[0]);
    Serial.print("X-axis: ");
    Serial.println(ReceivedMessage[1]);
    Serial.print("Y-axis: ");
    Serial.println(ReceivedMessage[2]);
    Serial.print("\n\n");
    delay(1000);
  }
}
