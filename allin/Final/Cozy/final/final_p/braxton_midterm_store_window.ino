PFont myFont;
PImage img;
String serialVal = "";
float val= 0.0;

import processing.serial.*;

float size;
float[] sensorValues = new float [3];

Serial myConnection;


void setup() {

  size(450, 800);
  //smooth(1);

  String portName = Serial.list()[3];
  myConnection = new Serial(this, portName, 9600);
}

void draw() {
  
    if (myConnection.available() > 0) {
    String value = myConnection.readStringUntil('\n');

    if (value != null) {
      String[] valueArray = split(value, '\t');

      printArray(valueArray);
      if (valueArray.length == 3) {
        sensorValues[0] = float(valueArray[0]); //converting pot
        sensorValues[1] = float(valueArray[1]); //converting temp
        sensorValues[2] = float(valueArray[2]); //converting sound
      }
    }
  }
  
  img = loadImage("1.png");
  background(img);
  
  // blendMode(EXCLUSION); //looks dope af
  
  rect(width/4, 0, 15, 125, 0, 0, 0, 0);
  rect(width/1.4, 0, 15, 125, 0, 0, 0, 0);
  
  fill(129, 139, 149);
  rect(0, 700, 450, 100);
  
  //cozy black
  
  fill(0, 0, 0);
  ellipse(width/2, 110, 400, 125);
  noStroke();
  
  //cozy red
  
  fill(246, 76, 79, 72);
  ellipse(width/2, 110, 345, 100);
  noStroke();
  
  //cozy white
  
  fill(255, 255, 255, 15);
  ellipse(width/2, 110, 345, 100);
  noStroke();

  myFont = createFont("Neoneon", 60);
  textFont(myFont);
  textAlign(CENTER, CENTER);
  smooth();
  fill(sensorValues[1], 33.15, 33.15, 100);
  // make this correspond with a sensor to make the light flicker
  text("Cozy Crew", width/2, 105);
 
  //skamtebord is below
  
  
  //fill(255, 0, 0);
  
  fill(335, 33.15, 33.15);
  // sale circle
  circle(75, 275, 120);
  // percent circle
  circle(375, 525, 125); 

  // window sign SALE
  myFont = createFont("Eina01-Bold", 40);
  textFont(myFont);
  fill(0, 0, 0);
  smooth();
  text("SALE", 75, 275);
  textAlign(CENTER, CENTER);
  
  fill(255, 255, 255);
  smooth();
  text("SALE", 78, 278);
  
  // window sign percentage
  myFont = createFont("Eina01-Bold", 30);
  textFont(myFont);
  fill(255, 255, 255);
  text(" 69%\nOFF", 373.5, 525);
  textAlign(CENTER, CENTER);
  
  // antennas
  fill(204, 204, 204);
  
 pushMatrix();
  // move the origin to the pivot point
  translate(120, 40); 
  
  // then pivot the grid
  rotate(radians(45));
  
  // and draw the square at the origin
  rect(440, 240, 10, 100, 10, 10, 10, 10);
  popMatrix();
  
  pushMatrix();
  // move the origin to the pivot point
  translate(120, 40); 
  
  // then pivot the grid
  rotate(radians(122));
  
  // and draw the square at the origin
  rect(450, -305, 10, 100, 10, 10, 10, 10);
  popMatrix();
  
  // TV

  fill(112, 57, 38);
  rect(60, 580, 250, 170, 10, 10, 10, 10);
  
  // tv screen
  fill(sensorValues[0], sensorValues[2], sensorValues[2], sensorValues[1]);
  rect(70, 600, 190, 130, 10, 10, 10, 10);
  
  
  myFont = createFont("Eina01-Bold", 60);
  textFont(myFont);
  fill(255, 255, 255, sensorValues[0]);
  smooth();
  text("SALE", 160, 660);
  
  // make this correspond with a sensor to make the screen flicker


  // top knob
  // make this correspond with to the potentiometer to change channels
  
  //fill(0, 0, 0);
  //circle(width/1.58, 635, 22);
  
  push();
  float rotationAngle = map(sensorValues[0], 0.0, 1023.0, 0.0, 1.5*PI);
  translate(width/1.58 , 4*height/5);
  rotate(-rotationAngle);
  noStroke();
  fill(0);
  circle(0, 0, 22);
  stroke(204);
  strokeWeight(10);
  line(0, 0, 10, 2);
  pop();
  
  //bottom knob
  fill(0, 0, 0); //sensorValue[3];
  circle(width/1.58, 702, 22);
  
  
}
