#ifndef RGBWT_matrix_h
#define RGBWT_matrix_h
#include <Arduino.h>
#include <Adafruit_Protomatter.h>



class RGBWT_matrix {
	public:
    static uint8_t rgbPins[]  = {25, 26, 27, 19, 15, 23};
    static uint8_t addrPins[] = {12, 16, 17};
    static uint8_t clockPin   = 5; // Must be on same port as rgbPins
    static uint8_t latchPin   = 32;
    static uint8_t oePin      = 33;

    static Adafruit_Protomatter m(
    32,          // Width of matrix (or matrix chain) in pixels
    4,           // Bit depth, 1-6
    1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
    3, addrPins, // # of address pins (height is inferred), array of pins
    clockPin, latchPin, oePin, // Other matrix control pins
    false
    );

    static int matrixMap [32][16];
    
    matrix();
    void setup();

		
	private:
		
};


#endif