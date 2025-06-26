#include <Arduino.h>
#include "RGBWT_WiFi.h"
#include "RGBWT.h"

RGBWT::RGBWT() {

}

void RGBWT::wifi(const char *usr, const char *psd, const char *ssid, void (*function)()){
  RGBWT_WiFi wifi(usr, psd, ssid, function);
}
void RGBWT::wifi(const char *ssid, const char *psd, void (*function)()){
  RGBWT_WiFi wifi(ssid, psd, function);
}