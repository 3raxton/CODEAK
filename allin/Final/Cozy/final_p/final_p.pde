import processing.serial.*;

PFont myFont;
PImage img;
PImage gate;
//String serialVal = "";
int sendVal;
String val = null; 
float bNumber = 1;
int x = 0;
float brightness;
float numValue;

Serial myConnection;


void setup() {

  size(450, 800);
  //smooth(1);

   //printArray(Serial.list());
  myConnection = new Serial(this, Serial.list()[1], 9600);
}

void draw() {
  
  // INPUT: mouse tracking, movement, etc.
  // - mouse track the TV knob
  // • mouse tracking for the sign
  // - drop gate when this happens
  // OUTPUT: text, images, graphics, etc. (done)
  // • mouse to LED 
  // - mouseclick or typing, etc. 
  // - wall hit in processing and it sends out something to an LED
  // • sign changes with mouse tracking
  // One-way serial communication between Arduino and Processing
  
     while (myConnection.available() > 0) {
    val = myConnection.readStringUntil('\n');
   

    if (val != null) {
      
      numValue = float(val);
      println(val);
      brightness = numValue;
      brightness = map(numValue, 0, 800, 0, 100);
      
      //println(numValue);
    }
  }
   
     // printArray(Serial.list()); – we run on 1
  
  
  
  img = loadImage("1.png");
  background(img);
  
  //image(gate, width/2, height/2);
   
  // blendMode(EXCLUSION); //looks dope af
  
   fill(129, 139, 149);
  
  rect(width/4, 0, 15, 125, 0, 0, 0, 0);
  rect(width/1.4, 0, 15, 125, 0, 0, 0, 0);
  
 
  rect(0, 700, 450, 100);
  
  //cozy black sign ellipse
  
  fill(0, 0, 0);
  ellipse(width/2, 110, 400, 125);
  noStroke();
  
  //cozy red ellipse
  
  fill(246, 76, 79, 72);
  ellipse(width/2, 110, 345, 100);
  noStroke();
  
  //cozy white ellipse
  
  fill(255, 255, 255, 15);
  ellipse(width/2, 110, 345, 100);
  noStroke();

  myFont = createFont("Neoneon", 60);
  textFont(myFont);
  textAlign(CENTER, CENTER);
  smooth();
  brightness = map(numValue, 0, 800, 0, 100);
  fill(255, 33.15, 33.15, 100);
  
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
  colorMode(HSB, 360, 100, 100);
  fill(360, 100, numValue);
  colorMode(RGB, 255, 255, 255);
  rect(70, 600, 190, 130, 10, 10, 10, 10);
  
  
  myFont = createFont("Eina01-Bold", 60);
  textFont(myFont);
  fill(255, 255, 255, 255);
  smooth();
  text("SALE", 160, 660);
  
  // make this correspond with a sensor to make the screen flicker

  //bottom knob
  fill(0, 0, 0); //sensorValue[3];
  circle(width/1.58, 702, 22);

  // top knob
  // make this correspond with to the potentiometer to change channels
  
  //fill(0, 0, 0);
  //circle(width/1.58, 635, 22);
  
  
  push();
  float rotationAngle = map(mouseX, 0.0, 1023.0, 0.0, 1.5-PI);
  translate(width/1.58 , 4*height/5);
  rotate(-rotationAngle);
  noStroke();
  fill(0);
  circle(0, 0, 22);
  stroke(204);
  strokeWeight(10);
  line(0, 0, 10, 2);
  pop();
  
  
//if ("1".equals(val)) {
   
//  fill(0, 0, 0);
//    rect(70, 600, 190, 130, 10, 10, 10, 10);
//    delay(5);
//  }
//  else{
//    fill(255, 0, 0);
//    rect(70, 600, 190, 130, 10, 10, 10, 10);
//  }
  

}

void mouseMoved(){
if(mouseX > 0 && mouseX < width){
  myFont = createFont("Neoneon", 60);
  textFont(myFont);
  textAlign(CENTER, CENTER);
  smooth();
  fill(255, 33.15, 33.15, 100);
  // make this correspond with a sensor to make the light flicker
  text("Cozy Crew", width/2, 105);
 myConnection.write(sendVal);
}
}
