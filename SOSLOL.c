#include <Servo.h>
/* 
Output
2 Motor for Flywheel
1 Tilt Motor
1 Rotate Motor

Input
Joystick
*/



/* Replace null with pin number*/       

#Flywheel 
int motorFly1 = 1;
int motorFly2 = 2;

#TiltMotor
int tilt = 3; 

#RotateMotor
int rotate = 4;

#Joystick 
int VRx = A0;
int VRy = A1;
int SW = 5;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

#Button
int button = 6;
int onOff = false;


void setup () {
  Serial.begin(9600);
  pinMode(rotate, OUTPUT);
  pinMode(motorFly1, OUTPUT);
  pinMode(motorFly2, OUTPUT);
  pinMode(tilt, OUTPUT);
  pinMode(motorFly2, OUTPUT):  
  pinMode(button, INPUT); 

  motorFly1.attach(motorFly1);
  motorFly2.attach(motorFly2);
  rotate.attach(rotate);
  tilt.attach(tilt);


  //Joystick
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

void loop() {
  JoystickY();
  JoystickX();
  Button();
  FlyWheelShoot(onOff);
  TiltandRotate(mapX,mapY);

}

void Button(){
  if(digitalRead(midButton)==HIGH){
    onOff = true;
  } else {
    onOff = false;
  }
}

void JoystickY()){
  yPosition = analogRead(VRy);
  delay(10);
  mapY = map(yPosition, 0, 1023, -512, 512);
}

void JoystickX(){
  xPosition = analogRead(VRx);
  delay(10);
  mapX = map(xPosition, 0, 1023, -512, 512);
}

void FlyWheelShoot(bool switch){
  if(switch){
    digitalWrite(motorFly1,HIGH);
    delay(10);
    digitalWrite(motorFly2,HIGH);
  } else {
    digitalWrite(motorFly1,LOW);
    delay(50);
    digitalWrite(motorFly2,LOW);
  }

}

void TiltandRotate(int xSpeed, int ySpeed){
  digitalWrite(rotate,map(XSpeed,-100,100,1000,2000))
  delay(50);
  digitalWrite(tilt,map(XSpeed,-100,100,1000,2000))
}

