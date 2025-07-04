# RGBWT
Arduino library designed to track weather using open weather api and outputting to a 32x16 rgb matrix. Users can track and switch between various weather types and maps using a rudimentary menu system display on a lcd screen and controlled with input buttons. 
## Features
- displays area currently tracked as rudimentary map, differentiating between land and water.
- currently stores 4 types of weather and 4 maps
- allows switching weather type, map or both during tracking
- overloaded wifi class allows connecting to standard access point or one requiring username and password(specifically eduroam access points, other ap's have not been tested)
- easy to use interface to call functions to initialise and run
## Important notices
- Requires openWeather account to obtain api key.
- at this version, this library only works with the esp32 dev module.
- it is a work in progress, it does work but the wiki is currently in the works to provide instructions and more versions and more supported board may come in the future.
## Background
The RGBWT (RGB Weather Tracker) started as an undergraduate 2nd year project with the purpose of creating an activty for applicant days. Originally working as a 2x4 red dot matrix using an esp8266 as its controller, the project as it currently stands is now using a 32x16 rgb matrix, with a 16x2 lcd screen and 4 input buttons, using an esp32 as its controller.
## Usage
### Hardware
#### Parts
- esp32 dev module
- 32 x 16 rgb matrix (current version is tested and working with dfrobot version)
- lcd 1602 display with i2c controller
- 4 input buttons 
### Software
Below is a basic example to get library working (this will change)
```cpp
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

