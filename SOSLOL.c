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
  angle = map(analogRead(A5),789,1011,0,80);
  delay(1000);  
  Serial.println(angle);
  rotate.setDeadBand(30);
  tilt.setDeadBand(30);
  tilt2.setDeadBand(30);
  Joystick();
 // PController(40,angle);
  TiltandRotate(30);
  Button();
//  FlyWheelShoot(onOff);

}

void PController(long setpoint, long measured){
  long kp = 4;
  output = (measured - setpoint) * kp;

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
  xPosition = analogRead(VRx);
  delay(10);
  mapY = map(yPosition, 0, 736, -100, 100); //-512,512
  mapX = map(xPosition, 0, 736, -100, 100); //-512,512
}


void FlyWheelShoot(bool but){
  if(but == true){
    digitalWrite(motorPinFly1,HIGH);
  } else {
    digitalWrite(motorPinFly1,LOW);
  }

}
void TiltandRotate(long tOutput){
 rotate.write(mapX);
  //delay(10);
 // tilt.write(mapY);
 // tilt2.write(-mapY);
 tilt.write(-tOutput);
 tilt2.write(tOutput);

}
