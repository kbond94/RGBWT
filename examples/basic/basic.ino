/*Version 1 RGB LED Weather tracker Written by Keith Bond
Credits; 
Aaron Glover, Ayanfeolu Fataki, Charlotte Mitchell, Skye McConville for original led weather tracker, parts of original code is still used in this version
William Hickmott for finding new matrix and mapping concept, Thomas Hankinson for pcb and cad tutorials
Dr Ian Sandall and Dr Waleed Al Nuaimy for support in development of kit*/

#include "RGBWT.h"
#include <WiFi.h>

RGBWT track;

//Api key
String api = "";

//wifi ap details
const char *ssid = "";
const char *user = "";
const char *password = "";

void blinky();
//main functions
void setup() {
  Serial.begin(115200);
  track.setWifi(ssid, password,  blinky);
  //track.setWifi(user, password, ssid, blinky);
  pinMode(2,OUTPUT);
  track.setApi(api);
  track.init();
  track.start();
}
void loop() {
  track.weather();
}
void blinky(){
  digitalWrite(2,HIGH);
  delay(300);
  digitalWrite(2,LOW);
  delay(300);
}