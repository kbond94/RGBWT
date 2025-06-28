#include "Arduino.h"
#include <Adafruit_Protomatter.h>
#include "RGBWT_matrix.h"

RGBWT_matrix::RGBWT_matrix(){
  rgbPins[6]  = {25, 26, 27, 19, 15, 23};
  addrPins[3] = {12, 16, 17};
  clockPin   = 5; // Must be on same port as rgbPins
  latchPin   = 32;
  oePin      = 33;  
  m(
    32,          // Width of matrix (or matrix chain) in pixels
    4,           // Bit depth, 1-6
    1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
    3, addrPins, // # of address pins (height is inferred), array of pins
    clockPin, latchPin, oePin, // Other matrix control pins
    false
  );
}

uint16_t RGBWT_matrix::color565(uint8_t r, uint8_t b, uint8_t g){
  uint16_t c = m.color565(r,g,b);
  return c;
}