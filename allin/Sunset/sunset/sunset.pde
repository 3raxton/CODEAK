import processing.serial.*;

float size;

float posX;

float backgroundColor; 

float[] sensorValues = new float [3];




Serial myConnection;

void setup(){
 
  size(600, 600);
  
  posX= width/2;
 
  String portName = Serial.list()[3];
  
  myConnection = new Serial(this, portName, 9600);
}

void draw(){
  
  background(255, 255, sensorValues[1]);
  
   if (myConnection.available() > 0) {
    String value = myConnection.readStringUntil('\n');

    if (value != null) {
      String[] valueArray = split(value, '\t');

      printArray(valueArray);
      if (valueArray.length == 3) {
        sensorValues[0] = float(valueArray[0]); //converting pot
        sensorValues[1] = float(valueArray[1]); //converting temp
        sensorValues[2] = float(valueArray[2]); //converting sound
        
backgroundColor = sensorValues[1];

backgroundColor = map(sensorValues[1], 26, 31, 50, 255);
      }
    }
    }
    noStroke();
  fill(255, 153, 51);
  circle(width/2, height/2, sensorValues[0]);
  
  fill(102, 204, 255);
  rect(0, width/2, 600, 300);
  
  fill(204, 255, 255);
  rectMode(CENTER);
  rect(500, width/2, 600, sensorValues[1]);
  }
  
