#include <AFMotor.h> // We use this library to control the speed and direction of motor
#include <NewPing.h>
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 300
//This is the constructor for a DC motor.  Call this constructor once for each motor in sketch.
//Syntax: AF_DCMotor motorname(portnum, freq), portnum is which channel (1-4) of the motor controller the motor will be connected to
//freq we use here is default 
AF_DCMotor motor1(1); //For motor number 1
AF_DCMotor motor2(2); //For motor number 2
AF_DCMotor motor3(3); //For motor number 3
AF_DCMotor motor4(4); //For motor number 4

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() //run once 
{

  motor1.setSpeed(150); //set the speed to 150, note minumum is 0 and max is 255
  motor2.setSpeed(150);
  motor3.setSpeed(150);
  motor4.setSpeed(150);

  motor1.run(RELEASE); //Stop the motor
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
   
}

void loop() //run continuously 
{
  
//  motor1.run(FORWARD); // run forward
//  motor2.run(FORWARD);
//  motor3.run(FORWARD);
//  motor4.run(FORWARD);
//  delay(6000); // run the motors forward for 4 seconds
//
//  motor1.run(RELEASE); 
//  motor2.run(RELEASE);
//  motor3.run(RELEASE);
//  motor4.run(RELEASE);
//  delay(2000);  //Stop the motors for 2 second

//  motor1.run(BACKWARD); // run backward
//  motor2.run(BACKWARD);
//  motor3.run(BACKWARD);
//  motor4.run(BACKWARD);
//  delay(6000); // run the motors backward for 4 second

//  motor1.run(RELEASE);
//  motor2.run(RELEASE);
//  motor3.run(RELEASE);
//  motor4.run(RELEASE);
//  delay(2000); //Stop the motors for 2 second

 int distance = sonar.ping_cm();
 if(distance < 10){
  Stop();
 }else {
  motor1.setSpeed(255); 
  motor1.run(FORWARD); 
  motor2.setSpeed(255);
  motor2.run(FORWARD);
  motor3.setSpeed(255); 
  motor3.run(FORWARD); 
  motor4.setSpeed(255); 
  motor4.run(FORWARD); 
}

}
void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
