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
  pinMode(tiltPin, OUTPUT);
  pinMode(button, INPUT); 
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
 digitalWrite(motorPinFly1,LOW);
//

  // JoystickY();
  // JoystickX();
  // printf(mapY);
//   printf(mapX);
  // Button();
 // FlyWheelShoot(true);
 // TiltandRotate(mapX,mapY);
}

//
  // digitalWrite(rotatePin,map(mapX,-100,100,1000,2000));
  // delay(50);
  // digitalWrite(tiltPin,map(mapY,-100,100,1000,2000));
//}//


// void TiltandRotate(long xSpeed = 0.0, long ySpeed=0.0){
//   digitalWrite(rotatePin,map(XSpeed,-100,100,1000,2000));
//   delay(50);
//   digitalWrite(tiltPin,map(ySpeed,-100,100,1000,2000));
// }
