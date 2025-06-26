#ifndef RGBWT_h
#define RGBWT_h
#include <Arduino.h>
#include "RGBWT_WiFi.h"
#include "RGBWT_http.h"
#include "RGBWT_input.h"
#include "RGBWT_map.h"
#include "RGBWT_matrix.h"
#include "RGBWT_screen.h"
#include "RGBWT_tracker.h"
#include "RGBWT_weather.h"
#include "weatherTypes.h"
//#include <WiFi.h>
//#include "esp_wpa2.h"

class RGBWT{
  public:
    //RGBWT(const char *usr, const char *psd, const char *ssid);
    //RGBWT(const char *ssid, const char *psd)
    RGBWT_WiFi wifi;
    RGBWT_http http;
    RGBWT_input input;
    RGBWT_map map;
    RGBWT_matrix matrix;
    RGBWT_screen screen;
    RGBWT_tracker tracker;
    RGBWT_weather currentWeather;
    RGBWT();
    void wifi(const char *usr, const char *psd, const char *ssid, void (*)());
    void wifi(const char *ssid, const char *psd, void (*)());
    void http(String a);
    void input(int i,int m, int x, int y);
    void track();
    void startup();

};

#endif 