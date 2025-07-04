#include "Arduino.h"
#include "RGBWT_WiFi.h"
#include <WiFi.h>
#include "esp_wpa2.h"

RGBWT_WiFi::RGBWT_WiFi(){
  //
}

void RGBWT_WiFi::init(const char *user, const char *pswd, const char *apName, void (*function)()) {
  username = user;
  password = pswd;
  ssid = apName;

  setup(1, function);
}

void RGBWT_WiFi::init(const char *apName, const char *pswd, void (*function)()){
  ssid = apName;
  password = pswd;
  setup(0, function);
}

void RGBWT_WiFi::setup(int aptype, void (*function)()){

  //lcd.setCursor(0,0);
  //lcd.print("Wifi Status:");
  WiFi.disconnect();
  if (aptype == 0){
    WiFi.begin(ssid, password);
  }
  else{
    //WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);
    WiFi.begin(ssid, WPA2_AUTH_PEAP, username, username, password);
    //WiFi.begin(ssid);
  }
  int i = -1;
  Serial.print("Connecting to WiFi. ");

  //needs putting into separate function
  while (WiFi.status() != WL_CONNECTED) 
  {

    /*if (i == 17){
    //lcd.setCursor(0,1);
      //lcd.print("                ");
      i = 0;
    }*/
    //i = i + 1;
    //lcd.setCursor(i,1);
    //lcd.print(".");

    Serial.print(".");
    function();
    //blinky();
  }
  digitalWrite(2,HIGH);
  Serial.println(ssid);  // print the name of the wifi it connected to

  //lcd.setCursor(0,1);
  //lcd.print("                ");
  //lcd.setCursor(0,1);
  //lcd.print("Connected!");

  delay(2000);

}
int RGBWT_WiFi::status(){
  int status;
  if (WiFi.status() == WL_CONNECTED){
    status = 1;
  }
  return status;
}