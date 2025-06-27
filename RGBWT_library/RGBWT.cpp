#include <Arduino.h>
#include "RGBWT_WiFi.h"
#include "RGBWT.h"

RGBWT::RGBWT() {

}

void RGBWT::wifi(const char *usr, const char *psd, const char *ssid, void (*function)()){
  wifi(usr, psd, ssid, function);
}
void RGBWT::wifi(const char *ssid, const char *psd, void (*function)()){
  wifi(ssid, psd, function);
}
void RGBWT::http(String a){
  http(a);
}

void RGBWT::input(int i,int m, int x, int y){

}
void RGBWT::track(){

}
void RGBWT::startup(){
  //run menu
  //get map
  //get weather
}