import processing.serial.*;

float[] sensorValues = new float [3];

Serial myConnection;
float mouseXpos;
PVector position, speed;
float ballRadius = 100;

void setup(){
  size(800, 800);
  
  myConnection = new Serial(this, Serial.list()[3], 9600);
  
  position = new PVector(width/2, height/2);
  
  speed = new PVector(random(10), random(10));
}

void draw(){
  background(0);
  
  int brightness = int( map(position.x, 0, width, 0, 255) );
  myConnection.write(brightness);
  
  float mouseXpos = mouseX+(sensorValues[0])+(1);
  
  println(mouseXpos);
  
  if(position.x - ballRadius/2 <= 0 || position.x + ballRadius/2 >= width){
    speed.x = speed.x * -1;
    
  }
  
  if(position.y - ballRadius/2 <= 0 || position.y + ballRadius/2 >= height){
    speed.y *= -1;
  }
  
  position.add(speed);
  
  fill(255, 255, 255);
  ellipseMode(CENTER);
  ellipse(position.x, position.y, ballRadius, ballRadius);
  
} 
