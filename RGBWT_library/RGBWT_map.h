#ifndef RGBWT_map_h
#define RGBWT_map_h
#include <Arduino.h>


class RGBWT_map {
	public:
    float Lat_Max;
    float Lat_Min;
    float Lat_Diff;
    float Lat_Inc;
    float Lon_Max;
    float Lon_Min;
    float Lon_Diff;      
    float Lon_Inc;
    uint16_t landColour;
    uint16_t seaColour;
    int mm[32][16];
    RGBWT_map(uint16_t land, uint16_t sea);
    RGBWT_map();
    void setMapColour(uint16_t l, uint16_t s);
    uint16_t viewLancColour();
    uint16_t viewSeaColour();
    void setLatCoord(float laMax, float laMin, float laDi, float laIn);
    void setLonCoord(float loMax, float loMin, float loDi, float loIn);
    
	private:
		
};


#endif