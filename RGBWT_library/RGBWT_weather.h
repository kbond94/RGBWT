#ifndef RGBWT_weather_h
#define RGBWT_weather_h
#include <Arduino.h>


class RGBWT_weather {
	public:
		String typeName = "";
    int idMax;
    int idMin;
    RGBWT_weather(String name, int idMa, int Mi, String api, String url);
    int getIdMax();
    int getIdMin();
    void set IdMax();
    void set IdMin();
	private:
		
};


#endif