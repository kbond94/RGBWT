#ifndef map_h
#define map_h
#include "Arduino.h"
#include "RGBWT_matrixMap.h"
#include "RGBWT_mapClass.h"
//#include "RGBWT_matrixMap.h"
//#include "RGBWT_matrixMap.h"


class map{
  public:
    RGBWT_mapClass unitedKingdom;
    RGBWT_mapClass greatBritain;
    RGBWT_mapClass scotland;
    RGBWT_mapClass ireland;
    RGBWT_mapClass merseyside;
    RGBWT_mapClass currentMap;
    map();
};
#endif