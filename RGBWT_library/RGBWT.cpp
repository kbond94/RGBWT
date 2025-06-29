#include "Arduino.h"
#include "RGBWT_matrix.h"
#include "RGBWT_matrixMap.h"
#include "RGBWT.h"

RGBWT::RGBWT() {
  colourInit();
  setMapColour();
  weatherInit();
  mapInit();
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

void RGBWT::setMap(map m, String n, coord la, coord lo, int mm[32][16]){
  m.displayName = n;
  m.lat = la;
  m.lon = lo;
  memcpy(m.displayMap, mm, sizeof(m.displayMap));
}

void RGBWT::setCoord(coord c, float mx, float mn, float md){
  c.max = mx;
  c.min = mn;
  c.mod = md;
  c.diff = c.max - c.min;
  c.inc = c.diff / c.mod;
}

void RGBWT::mapInit(){
  coord lat;
  coord lon;

  setCoord(lat, 57.5, 51, 33);
  setCoord(lon, 0.5, -4.5, 17);
  setMap(unitedKingdom, "United Kingdom", lat, lon, oldMatrixMap);

  setCoord(lat, 58.673473, 49.953292, 33);
  setCoord(lon, 1.798398, -6.793360, 17);
  setMap(greatBritain, "Great Britain", lat, lon, defaultMatrixMap);

  setCoord(lat, 55.37210, 51.45317, 33);
  setCoord(lon, -5.46974, -10.08949, 17);
  setMap(scotland, "Scotland", lat, lon, scotMatrixMap);

  setCoord(lat, 59.371243, 54.640675, 33);
  setCoord(lon, -1.677607, -7.524203, 17);
  setMap(ireland, "Ireland", lat, lon, irishMatrixMap);

  setCoord(lat, 53.445960, 53.330666, 33);
  setCoord(lon, -2.922317, -3.228324, 17);
  setMap(merseyside, "Merseyside", lat, lon, merseyMatrixMap);


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

void RGBWT::setMapColour(){
  landColour = colour.Green;
  seaColour = colour.Blue;
}