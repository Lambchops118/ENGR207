//Liam Jackson
//Lab 4 A
//DC motor with servo motor as an indicator of DC motor speed/voltage

#include<Servo.h> //servo library
Servo myServo;    //assigns name for servo

#define pwm 3 //Pin3 will be used for transistor
#define pot A0 //analog 0 will be used for potentiometer

int potpin = 0; 
int val; //reads value from analong pin

void setup() {
  pinMode(pwm,OUTPUT);
  pinMode(pot,INPUT);
  Serial.begin(9600);
  analogWrite(pwm,0);

  myServo.attach(9); //servo attached to pin 9

}

void loop() {
  val = analogRead(pot);
  val = map(val,0,1023,0,180);
  analogWrite(pwm, val); //here's how to generate PWM signal from Digital arduino pin
  Serial.println(val);

  myServo.write(180-val); // subtracting 180 inverts the direction the servo moves. with this the hand is on the right at zero
  delay(15); 


}
