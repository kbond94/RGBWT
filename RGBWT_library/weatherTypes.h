#ifndef weatherTypes_h
#define weatherTypes_h
#include "Arduino.h"
#include "RGBWT_weather.h"
#include "colourRef.h"

RGBWT_weather rain("Rain", 532, 300, Red);
RGBWT_weather thunder("Thunder", 233, 200, Purple);
RGBWT_weather snow("Snow", 623, 600, White);
RGBWT_weather cloud("Clouds", 805, 801, Grey);
RGBWT_weather currentWeather();
#endif
