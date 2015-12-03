/************************* GLOBALS *************************/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

/***********************************************************/


/************************* GLOBALS *************************/

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *leftMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
Adafruit_DCMotor *rightMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Adafruit Motorshield v2 - setting up!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  leftMotor->setSpeed(0);
  rightMotor->setSpeed(0);
  // turn on motor
  leftMotor->run(RELEASE);
  rightMotor->run(RELEASE);
}

/***********************************************************/

/************************** MAIN ***************************/

void loop() {
  // Will be useful later. For gradually increasing and decreasing speed
  uint8_t i;
  boolean accel;
  
  // If there is anything in the serial channel
  if(Serial.available()) {
    // Instruction from computer
    String instr = Serial.readString();
    // Both sides move forward at the same rate
    // Speed set at moderate, not maximum
    if(instr.equals("FORWARD")) {
      leftMotor->setSpeed(100);
      rightMotor->setSpeed(100);
      leftMotor->run(FORWARD);
      rightMotor->run(FORWARD);
    }

    // Turns on the tank thread principle
    // One side moves forward, the other side moves backward
    // Turning is set at a slower speed for precision
    else if(instr.equals("LEFT")) {
      leftMotor->setSpeed(20);
      rightMotor->setSpeed(20);
      leftMotor->run(BACKWARD);
      rightMotor->run(FORWARD);
    }

    // Turns on the tank thread principle
    // One side moves forward, the other side moves backward
    // Turning is set at a slower speed for precision
    else if(instr.equals("RIGHT")) {
      leftMotor->setSpeed(20);
      rightMotor->setSpeed(20);
      leftMotor->run(FORWARD);
      rightMotor->run(BACKWARD);
    }

    // Comes to a stop
    // Speed comes to zero
    else if(instr.equals("STOP")) {
      leftMotor->setSpeed(0);
      rightMotor->setSpeed(0);
      leftMotor->run(RELEASE);
      rightMotor->run(RELEASE);
    }
  }
}
/***********************************************************/
