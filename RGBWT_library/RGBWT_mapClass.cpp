#include "RGBWT_map.h"
#include <Arduino.h>

RGBWT_mapClass(){

}

RGBWT_mapClass(uint16_t land, uint16_t sea, float lat[], float lon[]){
  
}

float RGBWT_mapClass::getMaxLatitude(){
  return Lat_Max;
}
float RGBWT_mapClass::getMinLatitude(){
  return Lat_Min;
}
float RGBWT_mapClass::getMaxLongitude(){
  return Lon_Max;
}
float RGBWT_mapClass::getMinLongitude(){
  return Lon_min;
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