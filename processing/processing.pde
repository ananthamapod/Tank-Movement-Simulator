/*********************************** IMPORTS ***********************************/
import processing.serial.*;

/*******************************************************************************/


/*********************************** GLOBALS ***********************************/
Serial myPort;

/*******************************************************************************/

/************************************ MAIN *************************************/


void setup() {
  // Assign the serial port
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);

  println("begin");
  
  // need a frame just for the user to have something to interact with for keypressed to be recorded
  size(200, 200);
  frameRate(30);
}

void draw() {
  background(204);
}

// Called whenever keys are pressed
void keyPressed() {
  if(key == CODED) {
    // Only arrow key presses do anything
    // Writes to the serial port based on the arrow key, straightforward enough
    if(keyCode == UP) {
      myPort.write("FORWARD");
      println("FORWARD");
    } else if(keyCode == LEFT) {
      myPort.write("LEFT");
      println("LEFT");
    } else if(keyCode == RIGHT) {
      myPort.write("RIGHT");
      println("RIGHT");
    } else if(keyCode == DOWN) {
      myPort.write("STOP");
      println("STOP");
    }
  }
}