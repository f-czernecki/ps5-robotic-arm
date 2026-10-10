#include <Wire.h>
#include "PCA9685.h"

ServoDriver servo;

const int startAngles[3] = {0, 45, 45};
int currentAngles[3] = {0, 0, 0};
const int homingAngles[3] = {0, 90, 95};
const int resetAngles[3] = {0, 45, 45};
//Limits of used servos
const int low_limits[3] = {0, 0, 0};
const int high_limits[3] = {270, 180, 180};

void setup() {
  Wire.begin();
  Serial.begin(9600);
  servo.init(0x7f);
  //Moving to starting positions
  for (int i = 0; i < 3; i++) {
    servo.setAngle(i + 1, startAngles[i]);
    currentAngles[i] = startAngles[i];
    delay(60);
  }
}
//Helper function for moving servos
void moveServo(int servoIndex, int inc_point){
  currentAngles[servoIndex] += inc_point;
  currentAngles[servoIndex] = constrain(currentAngles[servoIndex], low_limits[servoIndex], high_limits[servoIndex]);
  servo.setAngle(servoIndex + 1, currentAngles[servoIndex]);
}
//Helper function for homing/reset
void moveTo(const int targetAngles[]){
  for (int i = 0; i < 3; i++){
    servo.setAngle(i + 1, targetAngles[i]);
    currentAngles[i] = targetAngles[i];
    delay(60);
  }
}

void loop() {
  while (Serial.available() > 0) {
    String x = Serial.readStringUntil('\n');
    x.trim(); 

    if (x == "exit") {
      moveTo(homingAngles);
    }
    else if (x == "reset") {
      moveTo(resetAngles);
    }
    else if (x == "1") {
      moveServo(0, 1);  
    }
    else if (x == "-1") {
      moveServo(0, -1); 
    }
    else if (x == "2") {
      moveServo(1, 1);  
    }
    else if (x == "-2") {
      moveServo(1, -1); 
    }
    else if (x == "3") {
      moveServo(2, 1); 
    }
    else if (x == "-3") {
      moveServo(2, -1); 
    }
  }
}



