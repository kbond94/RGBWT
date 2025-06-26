#include <Arduino.h>
#include "RGBWT_http.h"

void RGBWT_http::RGBWT_http(String api){
  API_key = api;
}

void RGBWT_http::RGBWT_http(){

}

String RGBWT_http::address(String La, String Lo){
 String webAdd = "http://api.openweathermap.org/data/2.5/weather?lat=";
 webAdd = webAdd + La;
 webAdd = webAdd + "&lon=";
 webAdd = webAdd + Lo;
 webAdd = webAdd + "&appid=";
 webAdd = webAdd + API_Key;

 return webAdd;
}