#include <vexMotor.h> // includes the vexMotor library (must also include Servo.h)
#include <Servo.h>    // servo library -- vexMotor relies on the Servo library

int motorPinFly1 = 7;

//TiltMotor
int tiltPin = 3; 
int tiltPin2 = 8;
vexMotor  tilt;
vexMotor  tilt2;

//RotateMotor
int rotatePin = 9;
vexMotor rotate;

//Joystick 
int VRx = A1;
int VRy = A0;
int SW = 5;
long xPosition = 0;
long yPosition = 0;
int SW_state = 0;
long mapX = 0;
long mapY = 0;

//Button
int button = 6;
int onOff = false;


int angle = 0;
 long output = 0;
void setup() {
  Serial.begin(9600);
  pinMode(rotatePin, OUTPUT);
  pinMode(motorPinFly1, OUTPUT);
  pinMode(tiltPin, OUTPUT);
  pinMode(button, INPUT); 
  pinMode(tiltPin2,OUTPUT);
  pinMode(10,INPUT);

  // motorFly1.attach(motorPinFly1);
  // motorFly2.attach(motorPinFly2);
  rotate.attach(rotatePin);
  tilt.attach(tiltPin);
  tilt2.attach(tiltPin2);


  //Joystick
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  // put your setup code here, to run once:

}

void loop() {
  angle = map(analogRead(10),0,4096,0,90);
  rotate.setDeadBand(60);
  printf(angle);
  tilt.setDeadBand(60);
  tilt2.setDeadBand(60);
 // Joystick();
//  PController(mapY);
  TiltandRotate();
  Button();
  FlyWheelShoot(onOff);
  // put your main code here, to run repeatedly:

}

void PController(long setpoint){
  long kp = 0.5;
  output = (angle - setpoint) * kp;

}

void Button(){
  if(digitalRead(button)==HIGH){
    onOff = true;
  } else {
    onOff = false;
  }
}

void Joystick(){
  yPosition = analogRead(VRy);
  delay(10);
  mapY = map(yPosition, 0, 1024, -100, 100); //-512,512
  mapX = map(xPosition, 0, 1024, -100, 100); //-512,512
}


void FlyWheelShoot(bool but){
  if(but == true){
    digitalWrite(motorPinFly1,HIGH);
  } else {
    digitalWrite(motorPinFly1,LOW);
  }

}
void TiltandRotate(){
 // rotate.write(mapX);
//  rotate.write(map(-mapX,-100,100,1000,2000));
  //delay(10);
 // tilt.write(mapY);
 // tilt2.write(-mapY);
 tilt.write(-0);
 tilt2.write(0);



}
