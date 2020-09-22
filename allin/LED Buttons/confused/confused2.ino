String serialReadout;
int PWM_Ledpin = 3;


void setup() {
  pinMode(PWM_Ledpin, OUTPUT);
  Serial.begin(115200);

}

void loop() {
  if(Serial.available()){
    serialReadout = Serial.read();

    analogWrite(PWM_Ledpin, serialReadout.toInt());
    }

    // digital write is 1 or 0
        // analog write is up and down etc

} void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
