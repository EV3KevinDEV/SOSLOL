#include <Servo.h>
/* 
Output
2 Motor for Flywheel
1 Tilt Motor
1 Rotate Motor

Input
Vex Button
Joystick
*/



/* Replace null with pin number*/       

//Flywheel 
int motorPinFly1 = 7;
Servo motorFly1;
Servo motorFly2;

//TiltMotor
int tiltPin = 3; 
Servo tilt;

//RotateMotor
int rotatePin = 4;
Servo rotate;

//Joystick 
int VRx = A0;
int VRy = A1;
int SW = 5;
long xPosition = 0;
long yPosition = 0;
int SW_state = 0;
long mapX = 0;
long mapY = 0;

//Button
int button = 6;
int onOff = false;


void setup () {
  Serial.begin(9600);
  pinMode(rotatePin, OUTPUT);
  pinMode(motorPinFly1, OUTPUT);
  pinMode(motorPinFly2, OUTPUT);
  pinMode(tiltPin, OUTPUT);
  pinMode(button, INPUT); 

  // motorFly1.attach(motorPinFly1);
  // motorFly2.attach(motorPinFly2);
  rotate.attach(rotatePin);
  tilt.attach(tiltPin);


  //Joystick
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
}

void loop() {
   // rotate.write(180);
    //digitalWrite(rotatePin,map(100,-100,100,-1000,2000));
  rotate.write(map(100,-100,100,1000,2000));


  // JoystickY();
  // JoystickX();
  // printf(mapY);
//   printf(mapX);
  // Button();
  // FlyWheelShoot(onOff);
 // TiltandRotate(mapX,mapY);
}

void Button(){
  if(digitalRead(button)==HIGH){
    onOff = true;
  } else {
    onOff = false;
  }
}

void JoystickY(){
  yPosition = analogRead(VRy);
  delay(10);
  mapY = map(yPosition, 0, 1023, -512, 512);
}

void JoystickX(){
  xPosition = analogRead(VRx);
  delay(10);
  mapX = map(xPosition, 0, 1023, -512, 512);
}

void FlyWheelShoot(bool but){
  if(but == true){
    digitalWrite(motorPinFly1,HIGH);
    delay(10);
    digitalWrite(motorPinFly2,HIGH);
  } else {
    digitalWrite(motorPinFly1,LOW);
    delay(50);
    digitalWrite(motorPinFly2,LOW);
  }

}
void TiltandRotate(){
  rotate.write(map(mapX,-100,100,1000,2000));
  delay(10);
  tilt.write(map(mapY,-100,100,1000,2000));


  // digitalWrite(rotatePin,map(mapX,-100,100,1000,2000));
  // delay(50);
  // digitalWrite(tiltPin,map(mapY,-100,100,1000,2000));
}


// void TiltandRotate(long xSpeed = 0.0, long ySpeed=0.0){
//   digitalWrite(rotatePin,map(XSpeed,-100,100,1000,2000));
//   delay(50);
//   digitalWrite(tiltPin,map(ySpeed,-100,100,1000,2000));
// }
