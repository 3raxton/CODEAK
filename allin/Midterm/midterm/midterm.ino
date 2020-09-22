
const int potentiometer = A0;
const int pinSound = A1;
const int pinTemp = A2;

const int B=3975;

void setup() {
  // put your setup code here, to run once:

    Serial.begin(9600);                         // set the serial communication frequency at 9600 bits per sec
    
    pinMode(potentiometer, INPUT);

    pinMode(pinSound, INPUT);

    pinMode(pinTemp, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int value = analogRead(potentiometer);
    // Serial.print("Pot: ");
    Serial.print(value);  
    Serial.print('\t');  

  value = analogRead(pinSound);
    // Serial.print("Sound: ");
    Serial.print(value);
    Serial.print('\t');

  value = analogRead(pinTemp);
  
  // used to get a temperature 
  
  float resistance=(float)(1023-value)*10000/value;
  float temperature=1/(log(resistance/10000)/B+1/298.15)-273.15;
  
    // Serial.print("Temp: ");
    Serial.println(temperature);
    

  delay(100);

}
