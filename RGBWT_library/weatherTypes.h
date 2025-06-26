#ifndef weatherTypes_h
#define weatherTypes_h
#include <Arduino.h>
#include "weather.h"

weather rain("Rain", 532, 300, Red);
weather thunder("Thunder", 233, 200, Purple);
weather snow("Snow", 623, 600, White);
weather cloud("Clouds", 805, 801, Grey);

#endif
