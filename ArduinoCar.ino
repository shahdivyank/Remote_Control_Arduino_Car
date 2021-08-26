/*
  Created By: Divyank Shah
  13th July 2021
  Remote Control Arduino Car Program

  The following program will move forward, backward, turn left, turn right based on 
  input from the IR remote!
*/

//Include IR library to interface with IR sensor
#include <IRremote.h>

//IR sensor is connected to PORT 12
#define receiver 12

//IR values for buttons (Up, Down, Left, Right Arrows and Center buttons)
#define forwardButton 16736925  // FORWARD
#define backwardButton 16754775  // BACK
#define leftButton 16720605  // LEFT
#define rightButton 16761405  // RIGHT
#define stopButton 16712445  // STOP

//Motor Configuration (Should Reflect Wiring Done Eariler)
//Responsible for Motor Speed
#define enableA 3
#define enableB 9 
//Responsible for Movement on LEFT Motor
#define leftForward 2 
#define leftBackward 4 
//Responsible for Movement on RIGHT Motorv
#define rightBackward 8 
#define rightForward 10 
//Speed that robot will move at (0 - 255)
#define robotSpeed 255

//Intialize IR sensor
IRrecv irrecv(receiver);
decode_results results;

//Value to store input from IR sensor
long val;

//Moving Forward
void forward(){ 
  analogWrite(enableA, robotSpeed);
  analogWrite(enableB, robotSpeed);
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, LOW);
  digitalWrite(rightForward, HIGH);
  Serial.println("Forward");
} 

//Moving Backward
void back() {
  analogWrite(enableA, robotSpeed);
  analogWrite(enableB, robotSpeed);
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightBackward, HIGH);
  digitalWrite(rightForward, LOW);
  Serial.println("Back");
}

//Turning Left
void left() {
  analogWrite(enableA, robotSpeed);
  analogWrite(enableB, robotSpeed);
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, HIGH);
  digitalWrite(rightBackward, LOW);
  digitalWrite(rightForward, HIGH); 
  Serial.println("Left");
}
 
//Turning Right
void right() {
  analogWrite(enableA, robotSpeed);
  analogWrite(enableB, robotSpeed);
  digitalWrite(leftForward, HIGH);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightBackward, HIGH);
  digitalWrite(rightForward, LOW);
  Serial.println("Right");
}

//Stopped Car
void brake() {
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);
  Serial.println("Stop!");
} 

void setup() {
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT); 
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  brake();
  irrecv.enableIRIn();   
}

void loop() {
  //Detect if a signal is recieved from the IR sensor and proceed to store that input
  if (irrecv.decode(&results)){ 
    val = results.value;
    Serial.println(val); 

    //Determine which action the input corresponds to 
    //If an irrelevant button is pressed, nothing occurs
    switch(val){  
      case forwardButton: 
         forward(); 
         break;
      case backwardButton: 
         back(); 
         break;
      case leftButton: 
        left(); 
        break;
      case rightButton: 
        right();
        break;
      case stopButton: 
        brake(); 
        break;
      default: 
        break;
    }

  //Resume IR sensor to recieve more input
  irrecv.resume();
  }
} 