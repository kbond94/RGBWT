#include "RGBWT_input.h"
#include <Arduino.h>

RGBWT_input::RGBWT_input(int a, int b, int c, int d){
  pinA = a;
  pinB = b;
  pinC = c;
  pinD = d;
  pinMode(pinA,INPUT);
  pinMode(pinB,INPUT);
  pinMode(pinC,INPUT);
  pinMode(pinD,INPUT);
  interuptSetup();
}
RGBWT_input::RGBWT_input(){

}
void RGBWT_input::interuptSetup(){
  attachInterrupt(digitalPinToInterrupt(pinA), RGBWT_input::aPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(pinB), RGBWT_input::bPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(pinC), RGBWT_input::cPressed, RISING);
  attachInterrupt(digitalPinToInterrupt(pinD), RGBWT_input::dPressed, RISING);
}

void RGBWT_input::aPressed(){
  button = 1;
}

void RGBWT_input::bPressed(){
  button = 2;
}

void RGBWT_input::cPressed(){
  button = 3;
}

void RGBWT_input::dPressed(){
  button = 4;
}