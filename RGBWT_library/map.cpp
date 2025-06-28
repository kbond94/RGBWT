#include "map.h"
#include "Arduino.h"
#include "Arduino.h"
#include "RGBWT_mapClass.h"
#include "libraries/RGBWT_matrixMap.h"

map::map(): unitedKingdom(Green, Blue, 57.5, 51, 0.5 -4.5, oldMatrixMap), greatBritain(Green, Blue, 58.673473, 49.953292, 1.798398, -6.793360, defaultMatrixMap), scotland(Green, Blue, 55.37210, 51.45317, -5.46974, -10.08949, scotMatrixMap), ireland(Green, Blue, 59.371243, 54.640675, -1.677607, -7.524203, irishMatrixMap), merseyside(Green, Blue, 53.445960, 53.330666, -2.922317, -3.228324, merseyMatrixMap) currentMap(){

}