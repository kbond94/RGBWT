#ifndef RGBWT_h
#define RGBWT_h
#include <Arduino.h>
#include "RGBWT_WiFi.h"
//#include <WiFi.h>
//#include "esp_wpa2.h"

class RGBWT{
  public:
    //RGBWT(const char *usr, const char *psd, const char *ssid);
    //RGBWT(const char *ssid, const char *psd)
    RGBWT();
    void wifi(const char *usr, const char *psd, const char *ssid, void (*)());
    void wifi(const char *ssid, const char *psd, void (*)());
};

#endif 