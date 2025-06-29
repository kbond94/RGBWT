#include "Arduino.h"
#include <Adafruit_Protomatter.h>
#include "RGBWT_matrix.h"

RGBWT_matrix::RGBWT_matrix() : m(bw, bd, cc, rgbPins, ac, addrPins, clockPin, latchPin, oePin, false) { 
  
}

/*uint16_t RGBWT_matrix::color565(uint8_t r, uint8_t b, uint8_t g){
  uint16_t c = m.color565(r,g,b);
  return c;
}*/

uint16_t RGBWT_matrix::color565(uint8_t red, uint8_t green, uint8_t blue) {
  return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
}