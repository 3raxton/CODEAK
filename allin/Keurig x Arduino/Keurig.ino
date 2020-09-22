#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int pinLight = A0;
int thresholdvalue = 20;
int ledPin = 3;
char serialRead;
const int pinButton = 7;

void setup() {
  // put your setup code here, to run once:

  pinMode(pinButton, INPUT);                 
  pinMode(ledPin, OUTPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    if (Serial.available()) {
    serialRead = Serial.read();

    analogWrite(ledPin, serialRead);
  }

  else {

    digitalWrite(ledPin, LOW);


  }
  
  delay(10);


  while (Serial.available()) {

    delay(100);
    lcd.clear();

    while (Serial.available() > 0) {
      char fromP = Serial.read();
      lcd.write(fromP);

    }
  }
  
{

  const int randNumber = random(1, 2);
    int sensorValue = analogRead(pinLight);    //the light sensor is attached to analog 0
    if(sensorValue<thresholdvalue)
    {
         lcd.begin(16, 2);
    
    lcd.setRGB(255, 0, 0);
    digitalWrite(ledPin, HIGH);
    // Print a message to the LCD.
    lcd.print("Brewing...");

    delay(1500);
    }
    else
    {
        lcd.begin(16, 2);
    
    lcd.setRGB(255, 255, 0);
    
    // Print a message to the LCD.
    lcd.print("Ready to brew");

    delay(10);

    
    }

    {
    if(digitalRead(pinButton))                     // when button is pressed
    {
        digitalWrite(ledPin, HIGH);             // led on
    }
    else
    {
        
    }

        delay(100);


}
    
}
}
