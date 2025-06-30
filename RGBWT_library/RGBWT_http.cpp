#include "Arduino.h"
#include "RGBWT_http.h"

RGBWT_http::RGBWT_http(String api){
  API_key = api;
}

RGBWT_http::RGBWT_http(){

}

String RGBWT_http::address(String La, String Lo){
 String webAdd = "http://api.openweathermap.org/data/2.5/weather?lat=";
 webAdd = webAdd + La;
 webAdd = webAdd + "&lon=";
 webAdd = webAdd + Lo;
 webAdd = webAdd + "&appid=";
 webAdd = webAdd + API_key;

 return webAdd;
}

int RGBWT_http::getIdValue(String data){
  StaticJsonDocument<400> doc;
  StaticJsonDocument<200> filter;
  filter["weather"][0]["id"]= true;

  DeserializationError error = deserializeJson(doc, data, DeserializationOption::Filter(filter));

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return 0;
  }

  JsonObject weather = doc["weather"][0];
  JsonObject main = doc["main"];

  int id = weather["id"]; 
  
  return id;

}