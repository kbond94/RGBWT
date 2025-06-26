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
    int matrixMap[32][16];
    RGBWT_mapClass(uint16_t land, uint16_t sea, float lat[], float lon[]);
    RGBWT_mapClass();
    float getMaxLatitude();
    float getMinLatitude();
    float getMaxLongitude();
    float getMinLongitude();
    uint16_t getLandColour();
    uint16_t getSeaColour();
    void setMapColour(uint16_t l, uint16_t s);
    void setLatCoord(float laMax, float laMin);
    void setLonCoord(float loMax, float loMin);
};


#endif