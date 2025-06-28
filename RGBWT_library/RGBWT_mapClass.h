#ifndef RGBWT_map_h
#define RGBWT_map_h
#include "Arduino.h"
#include "colourRef.h"


class RGBWT_mapClass {
	public:
    typedef struct coord {
      float max;
      float min;
      float diff;
      float inc;
    } coord;
    coord lat;
    coord lon;
    uint16_t landColour;
    uint16_t seaColour;
    int matrixMap[32][16];
    RGBWT_mapClass();
    RGBWT_mapClass(uint16_t land, uint16_t sea, float latMa, float latMi, float lonMa, float lonMi, int mm[32][16]);
    uint16_t getLandColour();
    uint16_t getSeaColour();
    void setMapColour(uint16_t l, uint16_t s);
    void setCoord(coord c ,float max, float min, float d);
};


#endif