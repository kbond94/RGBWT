#include "RGBWT.h"

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