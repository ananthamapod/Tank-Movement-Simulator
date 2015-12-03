# Sonar Graph

Simulate thread locomotion using VEX Motors, an Arduino Uno, and a motor shield.

![Motors](Motors.jpg)

## Introduction

So I wanted to play around with motors. I've used simple 5 V DC motors before, but controlling them with Arduino? This was the first time. I decided to use an Adafruit motor shield and VEX Robotics motors.

Essentially, the idea was to replicate the movement pattern of a tank, the key difference between that and the movement of a normal car being that the tank can turn in place (ie. turning radius of zero).

## Design

#### Behaviors

In order to implement thread movement, you really only need two motors. The turning behavior can be implemented as follows: To turn left, the left motor would run backward at the same rate that the right motor runs forward. To turn right, the opposite motors would run forward or backward respectively.

#### Functionality

The behavior of the tank can be controlled through the arrow keys of the keyboard on a computer.

* UP --> Forward movement
* RIGHT --> Turning RIGHT
* LEFT --> Turning LEFT
* DOWN --> Stop

## Implementation

* Uses Processing 3 to capture keyboard inputs

* Uses Serial connection for sending data back and forth from Arduino to computer

* Uses the Adafruit Motor Shield v2.3 to connect to the motors

## License
See [LICENSE](LICENSE)
