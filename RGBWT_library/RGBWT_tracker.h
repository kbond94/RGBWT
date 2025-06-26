#ifndef RGBWT_tracker_h
#define RGBWT_tracker_h
#include <Arduino.h>
#include "RGBWT_map.h"

class RGBWT_tracker{
  public:
    volatile float Lat_f;
    volatile int row;
    volatile int col;
    volatile int col_i;
    volatile int row_i;
    volatile float Lon_f;
    RGBWT_map mapToTrack();
    RGBWT_tracker(RGBWT_map map);
    void setMap(RGBWT_map m);
    void setValues();
    String getMapToTrackName();

}
