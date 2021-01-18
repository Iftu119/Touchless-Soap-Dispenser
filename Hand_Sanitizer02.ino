#include <Servo.h>   //servo library
Servo servo;     
const int trigPin = 10 ; 
const int echoPin = 11; 
const int servoPin = 9 ;
//int led= 10;
long duration, dist, average;   
long aver[5];   //array for average


void setup() {       
    Serial.begin(9600);
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(echoPin, INPUT);  
    servo.write(0);         //close cap on power on
    delay(100);
    servo.detach(); 
} 

void measure() {  
 digitalWrite(10,HIGH);
digitalWrite(trigPin, LOW);
delayMicroseconds(5);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);
duration = pulseIn(echoPin, HIGH);
dist = (duration/2) / 29.1;    //obtain distance
}
void loop() { 
  for (int i=0;i<=4;i++) {   //average distance
    measure();               
   aver[i]=dist;            
    delay(10);              //delay between measurements
  }
 dist=(aver[0]+aver[1]+aver[2]+aver[3]+aver[4])/5;    

if ( dist<25 )
{
//Change distance as per your need
 servo.attach(servoPin);
  delay(100);
 servo.write(0);  
 delay(100);       
 servo.write(210);    
 delay(100);
 servo.detach();      
}
Serial.print(dist);
}
