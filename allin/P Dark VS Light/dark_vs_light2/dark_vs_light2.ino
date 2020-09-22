// demo of Starter kit V2.0 - Grove - Light Sensor
// when the value of light sensor ledd than a certain value
// led will on, you can set this certain value via change thresholdvalue
// such as when you cover light sensor with your hand, you'll find led on



#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;



const int colorR = 255;
const int colorG = 0;
const int colorB = 0;

const int pinLight = A0;
const int pinLed   = 7;

int thresholdvalue=20;                 //the threshold to turn on or off the LED

int speakerPin = 4;                  // Grove Buzzer connect to D3

byte armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
};

byte armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
};


int length = 15; // the number of notes
char notes[] = "aaeaf "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;

void playTone(int tone, int duration) {
    for (long i = 0; i < duration * 1000L; i += tone * 2) {
        digitalWrite(speakerPin, HIGH);
        delayMicroseconds(tone);
        digitalWrite(speakerPin, LOW);
        delayMicroseconds(tone);
    }
}

void playNote(char note, int duration) {
    char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

    // play the tone corresponding to the note name
    for (int i = 0; i < 8; i++) {
        if (names[i] == note) {
            playTone(tones[i], duration);
        }
    }
}


void setup()
{
     lcd.begin(16, 2);
    
    lcd.setRGB(255, 0, 0);
    
    // Print a message to the LCD.
    lcd.createChar(3, armsDown);
    // create a new character
    lcd.createChar(4, armsUp);
    lcd.print("hello, Petula! :)");

    delay(1500);

    pinMode(speakerPin, OUTPUT);
}

void loop()
{
  const int randNumber = random(1, 2);
    int sensorValue = analogRead(pinLight);    //the light sensor is attached to analog 0
    if(sensorValue<thresholdvalue)
    {
         lcd.begin(16, 2);
    
    lcd.setRGB(255, 0, 0);
    
    // Print a message to the LCD.
    lcd.print("It's Dark!!!");

    delay(1500);

    int sensorReading = analogRead(A0);
    // map the result to 200 - 1000:
    int delayTime = map(sensorReading, 65, 1023, 200, 1000);
    // set the cursor to the bottom row, 5th position:
    lcd.setCursor(4, 1);
    // draw the little man, arms down:
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // draw him arms up:
    lcd.write(4);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // draw the little man, arms down:
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // draw the little man, arms down:
    lcd.write(4);
    delay(delayTime);
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // draw the little man, arms down:
    lcd.write(4);
    delay(delayTime);
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // draw the little man, arms down:
    lcd.write(4);
    delay(delayTime);
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 0);
    // draw the little man, arms down:
    lcd.write(4);
    delay(delayTime);


for (int i = 0; i < length; i++) 
    {
        if (notes[i] == ' ')
        {
            delay(beats[i] * tempo); // rest
        }
        else
        {
            playNote(notes[i], beats[i] * tempo);
        }

        // pause between notes
        delay(tempo / 2);
    }


    
    }
    else
    {
        lcd.begin(16, 2);
    
    lcd.setRGB(255, 233, 0);
    
    // Print a message to the LCD.
    lcd.print("It's Light!!!");

    delay(1500);

    
    }
}
