const int trigPin = 10 ; 
const int echoPin = 11; 
const int servoPin = 9 ; 

long duration ;
float distance ;
#include <Servo.h>
Servo myservo ;

void setup() {
 pinMode (trigPin , OUTPUT ) ; 
 pinMode (trigPin , INPUT ) ; 
 myservo.attach(9);
 myservo.write(0) ;
 Serial.begin (9600);
}

void loop() 
{
 digitalWrite (trigPin , LOW) ;
 delayMicroseconds (1) ;
 digitalWrite (trigPin , HIGH) ;
 delayMicroseconds (5) ;

 duration = pulseIn (echoPin , HIGH) ;
 distance = duration * (0.034/2);
 Serial.print ("Distance :") ;
 Serial.println (distance) ;

 if (distance < 5)
 { myservo.write (45);
 delay (100) ;
 myservo.write (90);
 delay (100) ;
 myservo.write (135);
 delay (100) ;
 myservo.write (180);
 delay (100) ;
 myservo.write (0);
 delay (3000) ;
 }
}
