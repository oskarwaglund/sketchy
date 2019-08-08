#include <Servo.h>
Servo myServo;

#define SERVO_PIN 9
#define AUTO_PIN 3
#define LEFT_PIN 12
#define RIGHT_PIN 11

int autoCounter = 90;
int currentAngle = 90;
int mode = 0; // 0 = auto, else manual

void setup() {
  myServo.attach(SERVO_PIN);
  pinMode(LEFT_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  pinMode(AUTO_PIN, INPUT);
}

void loop() {
  int leftPin = digitalRead(LEFT_PIN);
  int rightPin = digitalRead(RIGHT_PIN);
  int autoPin = digitalRead(AUTO_PIN);  
  if(mode == 0){
    if(leftPin == HIGH || rightPin == HIGH){
      mode = 1;
    } else {
      autoCounter = (autoCounter+1)%360;
      currentAngle = autoCounter < 180 ? autoCounter : 359 - autoCounter;
    }
  } else {
    if(autoPin == HIGH){
      mode = 0;
      autoCounter = currentAngle;
    } else if(leftPin == HIGH && rightPin == HIGH){
      //Do nothing 
    } else if(leftPin == HIGH){
      currentAngle--;
      if(currentAngle < 0) currentAngle = 0;
    } else if(rightPin == HIGH){
      currentAngle++;
      if(currentAngle > 179) currentAngle = 179;
    }
  }
  myServo.write(currentAngle);
  delay(10);
}
