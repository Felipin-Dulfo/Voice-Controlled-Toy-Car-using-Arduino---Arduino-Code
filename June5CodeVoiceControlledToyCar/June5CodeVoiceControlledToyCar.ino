#include <AFMotor.h>
#include <NewPing.h>
#include<Servo.h>
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 300

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

Servo myservo;

String voice;

void setup() {
Serial.begin(9600);
myservo.attach(10); // attaches servo to pin 10
myservo.write(90);
}

void loop() {
int distance = sonar.ping_cm();
 
if(Serial.available()>0) {
  voice="";
  delay(2);
  voice = Serial.readString();
  delay(2);
  Serial.println(voice);
if(voice == "left" || voice == "Left") {
  left();
}else if(voice == "right" || voice == "Right") {
  right();
}else if(voice == "stop" || voice == "Stop") {
  Stop();
}else if(voice == "forward" || voice == "Forward") {
  forward();
}
//else if(voice == "forward" || voice == "Forward"){
//   int distance = 0;
//   do {
//     distance = sonar.ping_cm();
//     motor1.setSpeed(255); 
//     motor1.run(FORWARD); 
//     motor2.setSpeed(255);
//     motor2.run(FORWARD);
//     motor3.setSpeed(255); 
//     motor3.run(FORWARD); 
//     motor4.setSpeed(255); 
//     motor4.run(FORWARD); 
//   } while (distance > 10);
//   
//}
}
//while(voice == "forward" || voice == "Forward") {
//  forward();
//}

}

void forward() {
 //int distance = sonar.ping_cm();
  int distance = sonar.ping_cm();
  while(distance > 10){
     motor1.setSpeed(255); 
     motor1.run(FORWARD); 
     motor2.setSpeed(255);
     motor2.run(FORWARD);
     motor3.setSpeed(255); 
     motor3.run(FORWARD); 
     motor4.setSpeed(255); 
     motor4.run(FORWARD); 
  }
  Stop();
}

void left() {
  int distance = sonar.ping_cm();
  myservo.write(180);
  delay(500);
  myservo.write(90);
  delay(500);
  if(distance < 10){
  Stop();
  }else {
  motor1.run(BACKWARD);
  motor1.setSpeed(255);
  motor2.run(BACKWARD);
  motor2.setSpeed(255);
  motor3.run(FORWARD);
  motor3.setSpeed(255);
  motor4.run(FORWARD);
  motor4.setSpeed(255);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}

void right() {
  int distance = sonar.ping_cm();
  myservo.write(0);
  delay(500);
  myservo.write(90);
  delay(500);
  if(distance < 10){
  Stop();
  }else {
  motor1.run(FORWARD);
  motor1.setSpeed(255);
  motor2.run(FORWARD);
  motor2.setSpeed(255);
  motor3.run(BACKWARD);
  motor3.setSpeed(255);
  motor4.run(BACKWARD);
  motor4.setSpeed(255);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
  }
}

void Stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
