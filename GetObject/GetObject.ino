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

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  
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
}

void loop() {
  int sensorVal = digitalRead(2);
  //Serial.print(cap.filteredData(4)); Serial.print("\t"); 
  
  Serial.print("Sensor Readings:");
  Serial.print(cap.baselineData(3)); Serial.print(",");
  Serial.print(cap.baselineData(4)); Serial.print(",");
  Serial.print(cap.baselineData(5)); Serial.print(",");
  Serial.print(cap.baselineData(6)); Serial.print(",");
  Serial.print(cap.baselineData(7)); Serial.print(",");
  Serial.print(cap.baselineData(8)); Serial.print(",");
  Serial.println();
  
   
   if (sensorVal == HIGH) {
      delay(10);
      Serial.print("https://classify-object.bluesea-6dc94308.westus.azurecontainerapps.io/classify?s1=");
      Serial.print(cap.baselineData(3)); Serial.print("&s2="); Serial.print(cap.baselineData(4));  
      Serial.print("&s3="); Serial.print(cap.baselineData(5));
      Serial.print("&s4="); Serial.print(cap.baselineData(6)); Serial.print("&s5="); Serial.print(cap.baselineData(7)); 
      Serial.print("&s6="); Serial.print(cap.baselineData(8));
      Serial.println();
      while (sensorVal == HIGH){
        
      }
      Serial.print("https://classify-object.bluesea-6dc94308.westus.azurecontainerapps.io/classify?s1=");
      Serial.print(cap.baselineData(3)); Serial.print("&s2="); Serial.print(cap.baselineData(4));  
      Serial.print("&s3="); Serial.print(cap.baselineData(5));
      Serial.print("&s4="); Serial.print(cap.baselineData(6)); Serial.print("&s5="); Serial.print(cap.baselineData(7)); 
      Serial.print("&s6="); Serial.print(cap.baselineData(8));
      Serial.println();

  } 
  
  // put a delay so it isn't overwhelming
  delay(100);
}
