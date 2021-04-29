
 
#include <Servo.h>
Servo myServo;
int potpin=0;
int Red = 7;
int Blue =2 ;
int Green=3;
int val;
Servo servo1;
int trigpin=4;
int echopin=5;
long distance;
long duration;
 
void setup()
{
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
  pinMode(Green,OUTPUT);
  myServo.attach(8);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
 
void loop() {
  
 ultra();
  myServo.write(0);
  val=analogRead(potpin);
  val = map(val, 0,1023,0,150);
  myServo.write(val);
   delay(15);
  
  if(distance <=9){
  digitalWrite(Red,HIGH);
  delay(2000);
  digitalWrite(Red, LOW);
  delay(1000);
   myServo.write(60);
  }
   else  { myServo.write(0);}
  if (distance<=9){
  digitalWrite(Blue, HIGH);
  delay(3000);
  digitalWrite(Blue,LOW);
  delay(3000);  
   myServo.write(120);
 }
 
  else { myServo.write(0);}
   if (distance<=9){
  digitalWrite(Green,HIGH);
  delay(3000);
  digitalWrite(Green,LOW);
  delayMicroseconds(3000);
  myServo.write(180);
    }
 
   
  else{ myServo.write(0);}
      }
void ultra(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(20);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(30);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
                    
}
  //distance=duration*0.343/2;
//The following are application of sarvo motors.
//They are use in elevetors which are use to trsansport people on tall buidings near us here.
//They are cameras which are use to shoot Akirachix vlogs.
//use in cars,provide linear position and velosity.