/*

  Created By: Divyank Shah
  9th June 2021
  Remote Control Arduino Car Test Program

  The following program will move forward, backward, turn left, turn right with 3 second intervals
  between each movement.

*/

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
void backward() {
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

//Define all pins as output 
//Brake car to ensure it is not moving when starting
void setup() {
  Serial.begin(9600);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT); 
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  brake();   
}

void loop() {
  Serial.println("Moving Forward...");
  forward();
  delay(3000);
  
  Serial.println("Moving Backward...");
  backward();
  delay(3000);

  Serial.println("Turning Left...");
  left();
  delay(3000);

  Serial.println("Turning Right...");
  right();
  delay(3000);

  Serial.println("Robot is Stopped...");
  brake();
  delay(3000);
} 
