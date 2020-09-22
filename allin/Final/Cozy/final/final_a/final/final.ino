#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;
  
  int buttonPin = 2;
  int soundPin= A1;
  const int lightPin = A0;
  int ledPin = 3;
  int thresholdvalue = 20; // light coming into light sensor
  char serialRead;
  int buttonState = 0;
  int sensorValue = analogRead(lightPin); 
  String serialReadout;

void setup() {


  lcd.begin(16, 2);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
//  int lastButtonState = LOW;

  
  
}

void loop() {
  // put your main code here, to run repeatedly:

     // INPUT: button, light sensor, LED 
     // - button turns on & off TV 
     // - twisty thing on TV would need to move or something with the lack of sound
     // • light sensor makes screen darker (maybe TV or sum)
     // OR button that changes the color / screen on the TV 
     // OUTPUT: a button or a potentiometer, and an LED going on and off, servo motor 
     // - the button pressed turns on an LED on the arduino 
     // • (done... can be improved)
     // One-way serial communication between Arduino and Processing
     // - the button changing something in the sketch or some sensor changing something
     // - sound sensor changes something in the sketch
     // • LED 0 or 1 sends to Processing to turn off or on
    

  // get serial for processing
    if (Serial.available()) {
    digitalWrite(ledPin, HIGH);
    serialReadout = Serial.read();

    }

    else {
    digitalWrite(ledPin, LOW);
  }


  if (Serial.available()) {
       
    }
    else
    {
     lcd.begin(16, 2);
    
    lcd.setRGB(255, 0, 0);
    
    // Print a message to the LCD.
    lcd.print("SALE");

    delay(0);

    
    }


  // Get the current state of the button
//  int currentButtonState = digitalRead(buttonPin);
//  int lastButtonState = digitalRead(buttonPin);
//
//  // button on & off code {
//  if (currentButtonState == HIGH && lastButtonState == LOW) {
//     // Switch the state of the output
//     digitalWrite(ledPin, !digitalRead(ledPin));
//  }
//
//  // Store the button's state so we can tell if it's changed next time round
//  lastButtonState = currentButtonState;


//
//else {
//
//  // probably nothing
//  
//  }

  int value = analogRead(lightPin);
  Serial.println(value);
  

}
