#ifndef RGBWT_input_h
#define RGBWT_input_h
#include "Arduino.h"


class RGBWT_input {
	public:
    int pinA;
    int pinB;
    int pinC;
    int pinD;

    static int button;

    
    RGBWT_input();
    void init(int a, int b, int c, int d);
    static void aPressed();
    static void bPressed();
    static void cPressed();
    static void dPressed();

    void interuptSetup();
    void reset();
    
		
	private:
		
};


#endif