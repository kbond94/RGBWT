#ifndef RGBWT_matrix_h
#define RGBWT_matrix_h
#include <Arduino.h>
#include <Adafruit_Protomatter.h>

class RGBWT_matrix {
	public:
    uint8_t rgbPins[6]  = {25, 26, 27, 19, 15, 23};
    uint8_t addrPins[3] = {12, 16, 17};
    uint8_t clockPin   = 5; // Must be on same port as rgbPins
    uint8_t latchPin   = 32;
    uint8_t oePin      = 33;

    Adafruit_Protomatter m();
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