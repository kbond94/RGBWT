#include "RGBWT_input"
#include <Arudino.h>

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
  attachInterrupt(digitalPinToInterrupt(pinA), a, RISING);
  attachInterrupt(digitalPinToInterrupt(pinB), b, RISING);
  attachInterrupt(digitalPinToInterrupt(pinC), c, RISING);
  attachInterrupt(digitalPinToInterrupt(pinD), d, RISING);
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