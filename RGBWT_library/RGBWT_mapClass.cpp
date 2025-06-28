#include "RGBWT_mapClass.h"
#include "Arduino.h"
#include "colourRef.h"

RGBWT_mapClass::RGBWT_mapClass(){

}

RGBWT_mapClass::RGBWT_mapClass(uint16_t land, uint16_t sea, float latMA, float latMI, float lonMA, float lonMI, int mm[][16]){
  setMapColour(land, sea);
  setLatCoord(latMA, latMI);
  setLonCoord(lonMA, lonMI);
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
void RGBWT_mapClass::setLatCoord(float laMax, float laMin){
  Lat_Max = laMax;
  Lat_Min = laMin;
  Lat_Diff = Lat_Max - Lat_Min;
  Lat_Inc = (Lat_Diff) / 33;
}
void RGBWT_mapClass::setLonCoord(float loMax, float loMin){
  Lon_Max = loMax;
  Lon_Min = loMin;
  Lon_Diff = Lon_Max - Lon_Min;
  Lon_Inc = (Lon_Diff) / 17;
}