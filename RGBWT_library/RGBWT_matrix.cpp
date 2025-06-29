#include "Arduino.h"
#include <Adafruit_Protomatter.h>
#include "RGBWT_matrix.h"

RGBWT_matrix::RGBWT_matrix() : m(bw, bd, cc, rgbPins, ac, addrPins, clockPin, latchPin, oePin, false) { 
  
}

/*uint16_t RGBWT_matrix::color565(uint8_t r, uint8_t b, uint8_t g){
  uint16_t c = m.color565(r,g,b);
  return c;
}*/
