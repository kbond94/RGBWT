#include <Arduino.h>
#include "RGBWT_menu.h"


RGBWT_menu::RGBWT_menu(String[] t, String[] b) {
  top = t;
  bottom = b;
}

RGBWT_menu::RGBWT_menu(){
  
}

String[] getTop(){
  return top;
}

String[] getBottom(){
  return bottom;
}
