#include "RGBWT_mapClass.h"
#include "Arduino.h"
#include "colourRef.h"

RGBWT_mapClass::RGBWT_mapClass(){

}

RGBWT_mapClass::RGBWT_mapClass(uint16_t land, uint16_t sea, float latMa, float latMi, float lonMa, float lonMi, int mm[][16]){
  setMapColour(land, sea);
  setCoord(lat, latMa, latMi, 17);
  setCoord(lon, lonMa, lonMi, 33);
  memcpy(matrixMap, mm, sizeof(matrixMap));
}
uint16_t RGBWT_mapClass::getLandColour(){
  return landColour;
}
uint16_t RGBWT_mapClass::getSeaColour(){
  return seaColour;
}
void RGBWT_mapClass::setMapColour(uint16_t l, uint16_t s){
  landColour = l;
  seaColour = s;
}
void RGBWT_mapClass::setCoord(coord c, float max, float min, float d){
  c.max = max;
  c.min = min;
  c.diff = c.max - c.min;
  c.inc = (c.diff) / d;
}