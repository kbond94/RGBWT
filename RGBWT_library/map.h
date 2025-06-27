#ifndef map_h
#define map_h
#include "RGBWT_mapClass.h"
#include "libraries/RGBWT_matrixMap.h"

RGBWT_mapClass unitedKingdom(57.5, 51, 0.5 -4.5, oldMatrixMap);
RGBWT_mapClass greatBritain(58.673473, 49.953292, 1.798398, -6.793360, defaultMatrixMap);
RGBWT_mapClass scotland(55.37210, 51.45317, -5.46974, -10.08949, scotMatrixMap);
RGBWT_mapClass ireland(59.371243, 54.640675, -1.677607, -7.524203, irishMatrixMap);
RGBWT_mapClass merseyside(53.445960, 53.330666, -2.922317, -3.228324, merseyMatrixMap);
RGBWT_mapClass currentMap();
#endif