#ifndef RGBWT_input_h
#define RGBWT_input_h
#include <Arduino.h>


class RGBWT_input {
	public:
    int pinA;
    int pinB;
    int pinC;
    int pinD;

    int button;

    RGBWT_input(int a, int b, int c, int d);
    int aPressed();
    int bPressed();
    int cPressed();
    int dPressed();

    void interuptSetup();
    
		
	private:
		
};


#endif