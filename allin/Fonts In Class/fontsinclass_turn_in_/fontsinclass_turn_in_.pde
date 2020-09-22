import processing.serial.*;

float size;
float[] sensorValues = new float [3];

float temp;

Serial myConnection;

PFont myFont;
PImage img;
int i;

ArrayList<PFont> myFontSet = new ArrayList<PFont>();


void setup(){
  
  size(800, 800);
  //smooth(1);
  printArray(PFont.list());
  img = loadImage("tom.png");
  
  String portName = Serial.list()[3];
  myConnection = new Serial(this, portName, 9600);
  
  for(int itr = 0; itr < PFont.list().length-10; itr = itr + 10){
    
    PFont tempFont = createFont(PFont.list()[itr], 70);
     myFontSet.add(tempFont); 
  
  }
  
  myFont = createFont(PFont.list()[18], 200); // 48 = size  18 = font number in list
  //myFont = loadFont("fonts/ArialMT-48.vlw") 
  // obviously that is a line of code for windows so specify the full path to pull a font
  
}

void draw(){
  
  background(255, temp, 255);
  
    if (myConnection.available() > 0) {
    String value = myConnection.readStringUntil('\n');
    if (value != null) {
      String[] valueArray = split(value, '\t');
      // The positions are determined in Arduino
      printArray(valueArray);
      if (valueArray.length ==3) {
        sensorValues[0] = float(valueArray[0]);  //converting potentiometer    
        sensorValues[1] = float(valueArray[1]);  //converting sound
        sensorValues[2] = float(valueArray[2]);  //converting temperature
      }
      float numValue = float(value);
      //use as needed (size for example)
      size =numValue;
    }
  }
  
  temp = map(sensorValues[2], 22, 30, 1, 255);

  background(255, 255, 255);
  image(img, sensorValues[1], sensorValues[2], sensorValues[0], sensorValues[1]);
  image(img, sensorValues[0], sensorValues[2], sensorValues[0], sensorValues[0]);
  image(img, sensorValues[1], sensorValues[1], sensorValues[1], sensorValues[0]);
  image(img, sensorValues[0], sensorValues[0], sensorValues[0], sensorValues[1]);
  image(img, sensorValues[1], sensorValues[0], sensorValues[1], sensorValues[0]);
  image(img, sensorValues[0], sensorValues[1], sensorValues[0], sensorValues[0]);
  image(img, sensorValues[1], sensorValues[0], sensorValues[0], sensorValues[1]);
  
  //textFont(myFont);
  
  fill(0,0,0); 
  textAlign(CENTER, CENTER);
  textSize(200);
  myFont = myFontSet.get(i);
  
  //myFont = createFont(PFont.list()[i], 100);
  
  textFont(myFont);
  text("LMAO YOU A\nSIMP", sensorValues[1], sensorValues[0]);
  
  
  //for (int i = 0; i < PFont.list().length; i++){
  //myFont = createFont(PFont.list()[i], 200);
  //textFont(myFont);
  //text("TYPE", width/2, height/2);
  
  
  //if(i < PFont.list().length-1){
    
   if(i < myFontSet.size() -sensorValues[0]){
    
    i++;
  
  }
  
  else {
  
    i = 0;
    
  }
  
  delay(80);
}
