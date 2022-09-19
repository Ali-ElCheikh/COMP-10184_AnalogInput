#include <Arduino.h> 

/**
 * I, Ali El Cheikh Ali, student number 000760145, certify that what I am submitting is my own work;
 * that I have not copied it from any other source. I also certify that I have not allowed my work to be copied by others
 */

void setup() { 

  // configure the USB serial monitor 
  Serial.begin(115200); 
} 
 
  float map(int x, int in_min, int in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
void loop() { 
  int iVal; 
  float temp;
  float tempChange;
  String tempFeeling;
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0); 
  
  float voltage = map(iVal, 0, 1024, 0, 3.3);
 
  tempChange = (voltage*50) / 3.3;
  // Temprature 
  temp = tempChange;

  if (temp <= 10 ){
      tempFeeling =  "Cold!";
  }

  else if  (temp > 10 && temp <= 15) {
      tempFeeling =  "Cool";
  }
  else if  (temp > 15 && temp <= 25) {
      tempFeeling =  "Perfect";
  }
  else if  (temp > 25 && temp <= 30) {
      tempFeeling =  "Warm";
  }
  else if  (temp > 30 && temp <= 35) {
      tempFeeling =  "Hot";
  }
  else {
      tempFeeling =  "Too Hot!";
  }
  

  // print value to the USB port 
  Serial.println("Digitized Value =  " + String(iVal) + " is Equivalent to an Analog Voltage = " + String(voltage) + "V"); 

 
  Serial.println("Digitized output of " + String(iVal)  + " is equivalent to a temprature input of " + String(tempChange) + " deg. C, which is " + String(tempFeeling));


 
  // wait 0.5 seconds (500 ms) 
  delay(2000); 
} 