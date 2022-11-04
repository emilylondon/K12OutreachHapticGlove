/*********************************************************
This is a library for the MPR121 12-channel Capacitive touch sensor

Designed specifically to work with the MPR121 Breakout in the Adafruit shop 
  ----> https://www.adafruit.com/products/

These sensors use I2C communicate, at least 2 pins are required 
to interface

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistribution
**********************************************************/

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons are 'released'
uint16_t lasttouched = 0;
uint16_t currtouched = 0;
int led_pin = 6;
int dataValue = 0;
SoftwareSerial mySerial(7, 6); // RX, TX for ESP-01

void setup() {
  Serial.begin(9600);

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
  Serial.println("sensor1 ,sensor2 ,sensor3,sensor4 ,sensor5 ,sensor6 ,object");
}

void loop() {
  // Get the currently touched pads
  
  
  //Serial.print(cap.filteredData(4)); Serial.print("\t"); 
  Serial.print(cap.baselineData(4)); Serial.print("\t");
  Serial.println();
  dataValue = cap.baselineData(4);
  if (dataValue > 230){
    analogWrite(led_pin, 0);
  }
  else if (dataValue >= 220){
    analogWrite(led_pin, (10-(dataValue-220))/10*255);
  }
  else {
    analogWrite(led_pin, 255);
  }
  // put a delay so it isn't overwhelming
  delay(100);
}
