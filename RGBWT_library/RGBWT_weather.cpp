#include "RGBWT_weather.h"
#include "Arduino.h"

RGBWT_weather::RGBWT_weather(String name, int max, int min, uint16_t col){
  setName(name);
  setIdMax(max);
  setIdMin(min);
  setColour(col);
}

String RGBWT_weather::getName(){
  return typeName;
}

int RGBWT_weather::getIdMax(){
  return idMax;
}

int RGBWT_weather::getIdMin(){
  return idMin;
}

uint16_t RGBWT_weather::getColour(){
  return colour;
}

void RGBWT_weather::setName(String n){
  typeName = n;
}

void RGBWT_weather::setIdMax(int ma){
  idMax = ma;
}

void RGBWT_weather::setIdMin(int mi){
  idMin = mi;
}

void RGBWT_weather::setColour(uint16_t co){
  colour = co;
}