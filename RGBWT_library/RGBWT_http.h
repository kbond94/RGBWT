#ifndef RGBWT_http_h
#define RGBWT_http_h
#include "Arduino.h"
#include <ArduinoJson.h>
#include <HTTPClient.h> 


class RGBWT_http{
  public:
    HTTPClient client;
    String API_key = "";
    int code;
    String address(String La, String Lo);
    RGBWT_http(String api);
    RGBWT_http();
    int getIdValue(String data);
};

#endif