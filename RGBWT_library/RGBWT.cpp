#include "Arduino.h"
#include "RGBWT.h"

RGBWT::RGBWT() {
  colourInit();
  weatherInit();
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

void RGBWT::weatherInit(){
  setWeather(rain, "Rain", 532, 300, colour.Red);
  setWeather(thunder, "Thunder", 233, 200, colour.Purple);
  setWeather(snow, "Snow", 623, 600, colour.White);
  setWeather(cloud, "Clouds", 805, 801, colour.Grey);
}

void RGBWT::setWeather(weather w, String n, int ma, int mi, uint16_t c){
  w.displayName = n;
  w.idMax = ma;
  w.idMin = mi;
  w.displayColour = c;
}

void RGBWT::colourInit(){
  colour.Red = getColour(red[0],red[1],red[2]);
  colour.Green = getColour(green[0],green[1],green[2]);
  colour.Blue = getColour(blue[0],blue[1],blue[2]);
  colour.White = getColour(50,50,50);
  colour.Purple = getColour(50,blue[1],50);
  colour.Yellow = getColour(50,50,red[2]);
  colour.Grey = getColour(255,140,0);
  colour.Off = getColour(0,0,0);
}

uint16_t RGBWT::getColour(uint8_t red, uint8_t green, uint8_t blue) {
  return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
}