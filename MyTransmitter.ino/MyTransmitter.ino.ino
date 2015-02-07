#include <Manchester.h>

/*

  Manchester Transmitter example
  
  In this example transmitter will send one 16 bit number per transmittion

  try different speeds using this constants, your maximum possible speed will 
  depend on various factors like transmitter type, distance, microcontroller speed, ...

  MAN_300 0
  MAN_600 1
  MAN_1200 2
  MAN_2400 3
  MAN_4800 4
  MAN_9600 5
  MAN_19200 6
  MAN_38400 7


*/

#define TX_PIN 12  //pin where your transmitter is connected
#define LED_PIN 13 //pin for blinking LED

uint8_t moo = 1; //last led status
uint16_t transmit_data = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, moo);
 // man.workAround1MhzTinyCore(); //add this in order for transmitter to work with 1Mhz Attiny85/84
  man.setupTransmit(TX_PIN, MAN_1200);
}

void loop() {
  man.transmit(transmit_data);
  transmit_data++;
  moo = ++moo % 2;
  digitalWrite(LED_PIN, moo);
}

