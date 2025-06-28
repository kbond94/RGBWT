#ifndef RGBWT_matrix_h
#define RGBWT_matrix_h
#include "Arduino.h"
#include <Adafruit_Protomatter.h>

class RGBWT_matrix {
	public:
    uint8_t rgbPins[6]={25, 26, 27, 19, 15, 23};;
    uint8_t addrPins[3]={12, 16, 17};
    uint8_t clockPin=5; // Must be on same port as rgbPins
    uint8_t latchPin=32;
    uint8_t oePin=33;
    uint16_t bw = 32;
    uint8_t bd = 4;
    uint8_t cc = 1;
    uint8_t ac = 3;

    Adafruit_Protomatter m;

    static int matrixMap [32][16];
    static uint16_t color565(uint8_t red, uint8_t green, uint8_t blue); 
    RGBWT_matrix();
    void setup();

		
	private:
		
};


#endif