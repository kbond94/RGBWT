#include "Arduino.h"
#include "RGBWT_WiFi.h"
#include <WiFi.h>
#include "esp_wpa2.h"
//#include <LiquidCrystal_I2C.h>
//#include "RGBWT_lcd.h"

RGBWT_WiFi::RGBWT_WiFi(const char *user, const char *pswd, const char *apName, void (*function)()) {
  username = user;
  password = pswd;
  #define EAP_ANONYMOUS_IDENTITY username
  #define EAP_IDENTITY username
  #define EAP_PASSWORD password
  #define EAP_USERNAME username
  ssid = apName;

  setup(1, function);
}

RGBWT_WiFi::RGBWT_WiFi(const char *apName, const char *pswd, void (*function)()){
  ssid = apName;
  password = pswd;
  setup(0, function);
}

RGBWT_WiFi::RGBWT_WiFi(){

}

void RGBWT_WiFi::setup(int aptype, void (*function)()){

  //lcd.setCursor(0,0);
  //lcd.print("Wifi Status:");
  if (aptype == 0){
    WiFi.begin(ssid, password);  // tell esp12e to begin wifi connection
  }
  else{
    WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);
  }
  int i = -1;
  //Serial.print("Connecting to WiFi. ");

  //needs putting into separate function
  while (WiFi.status() != WL_CONNECTED) 
  {

    if (i == 17){
    //lcd.setCursor(0,1);
      //lcd.print("                ");
      i = 0;
    }
    i = i + 1;
    //lcd.setCursor(i,1);
    //lcd.print(".");

    Serial.print(".");
    (*function)();
    //blinky();
  }
  digitalWrite(2,HIGH);
  Serial.println(ssid);  // print the name of the wifi it connected to

  //lcd.setCursor(0,1);
  //lcd.print("                ");
  //lcd.setCursor(0,1);
  //lcd.print("Connected!");

  delay(1000);

}
