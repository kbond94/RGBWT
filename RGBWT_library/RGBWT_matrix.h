#ifndef RGBWT_matrix_h
#define RGBWT_matrix_h
#include "Arduino.h"
#include <Adafruit_Protomatter.h>

class RGBWT_matrix {
	public:
    static uint8_t rgbPins[6];
    static uint8_t addrPins[3];
    static uint8_t clockPin; // Must be on same port as rgbPins
    static uint8_t latchPin;
    static uint8_t oePin;

    static Adafruit_Protomatter m;
    /*32,          // Width of matrix (or matrix chain) in pixels
    4,           // Bit depth, 1-6
    1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
    3, addrPins, // # of address pins (height is inferred), array of pins
    clockPin, latchPin, oePin, // Other matrix control pins
    false
    );*/

    static int matrixMap [32][16];
    uint16_t color565(uint8_t r, uint8_t b, uint8_t g); 
    RGBWT_matrix();
    void setup();

		
	private:
		
};


#endif