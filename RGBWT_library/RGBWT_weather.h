#ifndef RGBWT_weather_h
#define RGBWT_weather_h
#include <Arduino.h>


class RGBWT_weather {
	public:
		String typeName = "";
    int idMax;
    int idMin;
    uint16_t colour;
    RGBWT_weather(String name, int max, int min, uint16_t col);
    String getName();
    int getIdMax();
    int getIdMin();
    uint16_t getColour();
    void setName(String n)
    void setIdMax(int ma);
    void setIdMin(int mo);
    void setColour(uint16_t co);

	private:
		
};


#endif