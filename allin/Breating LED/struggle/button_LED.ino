int buttonPin = 2;
int ledPin = 3;
int speakerPin = 5;
int toneVal = 31;
int mouseXpos = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode(buttonPin, INPUT);
  //obviously button is an input – Maxim

  pinMode(ledPin, OUTPUT);

  pinMode(speakerPin, OUTPUT);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  if ( !digitalRead(buttonPin) ) {

    noTone(speakerPin);

    for (int i = 0; i < 256; i++) {

      analogWrite(ledPin, i);

      delay(5);

    }// end for loop

    delay(200);

    for (int i = 254; i >= 0; i--) {

      analogWrite(ledPin, i);
      delay(5);

    }// end of for loop

    delay(200);

    // END OF NO BUTTON PRESS

  }

  else {

    tone(speakerPin, toneVal);
    digitalWrite(ledPin, LOW);
    delay(40);

  }// end of else

  toneVal += 25;
  if (toneVal >= 3000) {

    toneVal = 31;
  }

  Serial.println(toneVal);


}
