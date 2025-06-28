#ifndef RGBWT_map_h
#define RGBWT_map_h
#include "Arduino.h"
#include "colourRef.h"


class RGBWT_mapClass {
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
    int matrixMap[32][16];
    RGBWT_mapClass();
    RGBWT_mapClass(uint16_t land, uint16_t sea, float latMA, float latMI, float lonMA, float lonMI, int mm[][16]);
    uint16_t getLandColour();
    uint16_t getSeaColour();
    void setMapColour(uint16_t l, uint16_t s);
    void setLatCoord(float laMax, float laMin);
    void setLonCoord(float loMax, float loMin);
};


#endif