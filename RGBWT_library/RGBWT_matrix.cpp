#include <Arduino.h>
#include "RGBWT_matrix.h"

RGBWT_matrix::RGBWT_matrix(){
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