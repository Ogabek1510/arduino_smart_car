/*
  Bluetooth controlled Arduino Smart Car

  by Og'abek Sattorov
*/

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(11, 10); // RX, TX

// Motor Driver Pins
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {
  BTSerial.begin(9600);
  
  // Set the motor driver pins as output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}

void Forward(){
  //Set the motor to go forward
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void Backward(){
  //Set the motor to go backward
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void toRight(){
  //Set the motor to go right
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  digitalWrite(in3, 0);
  digitalWrite(in4, 1);
}

void toLeft(){
  //Set the motor to go left
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  digitalWrite(in3, 1);
  digitalWrite(in4, 0);
}

void Stop(){
  // Stop the motor
  digitalWrite(in1, 0);
  digitalWrite(in2, 0);
  digitalWrite(in3, 0);
  digitalWrite(in4, 0);
}

void loop() {
  char value;
  
  if (BTSerial.available() > 0){
    value = BTSerial.read();
  }
  
  if (value == 'F'){
    Forward();
  }
  else if (value == 'B'){
    Backward();
  }
  else if (value == 'R'){
    toRight();
  }
  else if (value == 'L'){
    toLeft();
  }
  else if (value == 'G'){
    Forward();
    toLeft();
  }
  else if (value == 'I'){
    Forward();
    toRight();
  }
  else if (value == 'H'){
    Backward();
    toRight();
  }
  else if (value == 'J'){
    Backward();
    toLeft();
  }
  else{
    Stop();
  }
}
