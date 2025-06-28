#ifndef RGBWT_h
#define RGBWT_h
#include "Arduino.h"
#include "map.h"
#include "RGBWT_matrix.h"
//#include <WiFi.h>
//#include "esp_wpa2.h"

class RGBWT{
  public:

    //RGBWT_matrix matrix();
    RGBWT();
    void wifi(const char *usr, const char *psd, const char *ssid, void (*)());
    void wifi(const char *ssid, const char *psd, void (*)());
    void http(String a);
    void input(int i,int m, int x, int y);
    void track();
    void startup();

};

#endif 