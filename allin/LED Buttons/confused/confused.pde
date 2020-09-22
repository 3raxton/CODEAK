import processing.serial.*;

Serial myPort;

int numberOfButtons = 3;
PVector [] buttonPositions = new PVector[numberOfButtons];
color [] buttonColors = new color [numberOfButtons];
boolean [] buttonStates = new boolean [numberOfButtons];
int buttonRadius = 50;


void setup(){
  size(150, 500);
  
  colorMode(HSB, 360, 100, 255);
  
  printArray(Serial.list());
  myPort = new Serial(this, Serial.list()[3], 115200);
  
  //for loop normal structure - start with 0 go to length and add the amount
  for(int i = 0; i < numberOfButtons; i++){
    //for the buttonPositions in the array ie 1 then 2 then 3 till it gets to 7
    //i + 1 keeps from starting at the top
    buttonPositions[i] = new PVector(width/3, 100*(i + 1));
    buttonColors[i] = color(10, 100, 255 - (255/numberOfButtons)*i);
    buttonStates[i] = false;
  }
  
}

void draw(){
  background (175);
  
  //for each loop
  for(int i = 0; i < numberOfButtons; i++){
    fill(buttonColors[i]);
    if(buttonStates[i] == false){
      strokeWeight(3);
      rect(buttonPositions[i].x + 2, buttonPositions[i].y + 2, buttonRadius, buttonRadius);
      strokeWeight(1);
    }
    else {
      rect(buttonPositions[i].x, buttonPositions[i].y, buttonRadius, buttonRadius);
    }
    
  }
}

void mouseClicked(){
  for(int i = 0; i < numberOfButtons; i++){
    if(dist(buttonPositions[i].x, buttonPositions[i].y, mouseX, mouseY) < buttonRadius){
      if(!buttonStates[i]){
      //temporary float to just extract the brightness value but only gives float not int
      float thisBrightness = brightness(buttonColors[i]);
      //this converts brightness to an int
      int valToSend = int(thisBrightness);
      println(thisBrightness);
      myPort.write(valToSend);
      }
      else{
       myPort.write(0); 
      }
      
      buttonStates[i] = buttonStates[i];
    }
    
    else {
    
      buttonStates[i] = false;
    
    }
    
  }
} 
