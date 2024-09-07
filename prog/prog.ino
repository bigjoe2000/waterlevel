/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
#include "NewPing.h"

const int RED_LED = 5;

#define TRIGGER_PIN 9
#define ECHO_PIN 10

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400 

// Water is approaching empty if more than this many cm away from sensor
#define EMPTY_DISTANCE 10

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;
int iterations = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
};

// the loop function runs over and over again forever
void loop() {
  // Send ping, get distance in cm
  duration = sonar.ping_median(iterations);  

  int distance = sonar.convert_cm(duration);
  
  // Send results to Serial Monitor
  Serial.print(" cm:");
  Serial.println(distance);

  if (distance > EMPTY_DISTANCE) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
  }
  delay(250);
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(250);                       // wait for a second
//  digitalWrite(RED_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//  digitalWrite(RED_LED, LOW);    // turn the LED off by making the voltage LOW
//  delay(250);                       // wait for a second
//  digitalWrite(GREEN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(500);                       // wait for a second
//  digitalWrite(GREEN_LED, LOW);    // turn the LED off by making the voltage LOW
//  delay(500);                       // wait for a second
//  digitalWrite(BLUE_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(250);                       // wait for a second
//  digitalWrite(BLUE_LED, LOW);    // turn the LED off by making the voltage LOW
//  delay(250);                       // wait for a second
}
