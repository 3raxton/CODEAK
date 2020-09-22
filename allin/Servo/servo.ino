#include <Servo.h>
String serialReadout; 
Servo myServo;
int defaultPos = 0;
int pot = 0;
int servoPin = A3; // only works in ports 3,5,6,9,10,11
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  myServo.attach(servoPin);

}
void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(pot);
  Serial.print(value);
  Serial.print('\t');
  
  if(Serial.available()){
    serialReadout = Serial.read();
    myServo.write(serialReadout.toInt());
    delay(15);
    }
}
