
#include <Manchester.h>
//#include <SimpleTimer.h>
//#include <ServoTimer2.h>
#include <Servo.h>
/*

  Manchester Receiver example
  
  In this example receiver will receive one 16 bit number per transmittion

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

#define RX_PIN 12
#define LED_PIN 13
#define SERVO_PIN 9

int counter = 1;
boolean closed;
uint8_t moo = 1;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); 
  pinMode(9, OUTPUT);
  digitalWrite(LED_PIN, moo);
  closed = false;
  myServo.attach(SERVO_PIN);
  myServo.write(0);
  man.setupReceive(RX_PIN, MAN_1200);
  man.beginReceive();
}

void loop() {
  
  boolean check;
  check = man.receiveComplete();
  Serial.println(man.receiveComplete());
  Serial.println('/n');
  Serial.println(counter);
  Serial.println('/n');
 // check = checkData( bool, 1 );  
  
  if (check == true) {
    uint16_t m = man.getMessage();
    man.beginReceive(); //start listening for next message right after you retrieve the message
    moo = ++moo % 2;
    digitalWrite(LED_PIN, moo);
    delay(250);
    myServo.write(30);
    counter = 0;
    closed = true;
    //myServo.write(turn);
  }
  
  if (check == false && counter > 10 && closed == false) {
    delay(100);
    myServo.write(150);
    delay(300);
    myServo.write(40);
    closed = true;
  
}
counter++;
delay(1000);
}


/*
boolean checkData( boolean bool, int count){
  if (bool == true){
    return true;
  if (counter > 15 && bool == false)
    return false;
  if (counter < 15 && bool == false){
    man.beginReceive();
    bool = man.receiveComplete();
    count++;
    delay(100);
    checkData(bool, count);
  */
  
    
    
    
  
/*
void algorithm() {
  
  man.beginReceive();
  myServo.write(0);
  time = millis();
  if (man.receiveComplete()) {
    moo = ++moo % 2;
    digitalWrite(LED_PIN, moo);
    algorithm();
  }
//  if (millis() - time > 10000) {
//    myServo.write(130);
//  }
}
*/
