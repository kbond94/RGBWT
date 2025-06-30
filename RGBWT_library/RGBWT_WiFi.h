#ifndef RGBWT_WiFi_h
#define RGBWT_WiFi_h
#include "Arduino.h"
#include <WiFi.h>
#include "esp_wpa2.h"
//#include <LiquidCrystal_I2C.h>
//#include "RGBWT_lcd.h"

class RGBWT_WiFi{
  public: 
    const char *username = "";
    const char *password = ""; 
    const char *ssid = "";
    RGBWT_WiFi(const char *user, const char *pswd, const char *ssid, void (*)());
    RGBWT_WiFi(const char *ssid, const char *pswd, void (*)());
    RGBWT_WiFi();
    void setup(int aptype, void (*)());
    //void
  private:
};

#endif 
