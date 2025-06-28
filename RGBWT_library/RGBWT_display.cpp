#include "Arduino.h"
#include "RGBWT_display.h"

RGBWT_display::RGBWT_display(){

}
RGBWT_display::RGBWT_display(String t, String b){
  top = t;
  bottom = b;
}
RGBWT_display::RGBWT_display(String t, String bo1, String bo2, String bo3, String bo4){
  top = t;
  String l[4]={bo1, bo2, bo3, bo4};
  bottomList = l;
}
void RGBWT_display::changeTop(String nt){
  top = nt;
}
void RGBWT_display::changeBottom(String nb){
  bottom = nb;
}