#include "Arduino.h"
#include "RGBWT_matrixMap.h"
#include "RGBWT.h"

RGBWT::RGBWT(): display(), input(), matrix(bw, bd, cc, rgbPins, ac, addrPins, clockPin, latchPin, oePin, false) {
  //
}

void RGBWT::init(){
  colourInit();
  setMapColour();
  weatherInit();
  mapInit();
}

void RGBWT::inputInit(int i,int m, int x, int y){
  //
}
int RGBWT::getInput(String ops[4]){
  int dispOption;
  int option;
  while (1){
    display.displayBottom(ops[dispOption]);
    dispOption ++;
    if (dispOption == 4){
      dispOption = 1;
    }
    if (input.button > 0){
      option = input.button;
      break;
    }
  }
  return option - 1;
}

void RGBWT::weather(){
  //
}
void RGBWT::startup(){
  //run menu
  //get map
  //get weather
}

//set all struct initialisation
void RGBWT::weatherInit(){
  setWeather(rain, "Rain", 532, 300, colour.Red);
  setWeather(thunder, "Thunder", 233, 200, colour.Purple);
  setWeather(snow, "Snow", 623, 600, colour.White);
  setWeather(cloud, "Clouds", 805, 801, colour.Grey);
}
void RGBWT::mapInit(){
  coord lat;
  coord lon;

  setCoord(lat, 57.5, 51, 33);
  setCoord(lon, 0.5, -4.5, 17);
  setMap(unitedKingdom, "United Kingdom", lat, lon, oldMatrixMap);

  setCoord(lat, 58.673473, 49.953292, 33);
  setCoord(lon, 1.798398, -6.793360, 17);
  setMap(greatBritain, "Great Britain", lat, lon, defaultMatrixMap);

  setCoord(lat, 55.37210, 51.45317, 33);
  setCoord(lon, -5.46974, -10.08949, 17);
  setMap(scotland, "Scotland", lat, lon, scotMatrixMap);

  setCoord(lat, 59.371243, 54.640675, 33);
  setCoord(lon, -1.677607, -7.524203, 17);
  setMap(ireland, "Ireland", lat, lon, irishMatrixMap);

  setCoord(lat, 53.445960, 53.330666, 33);
  setCoord(lon, -2.922317, -3.228324, 17);
  setMap(merseyside, "Merseyside", lat, lon, merseyMatrixMap);


}
void RGBWT::screenInit(){
  setScreen(startScreen, "Hello There", "Starting up...");
  setScreen(wifiConnScreen, "Wifi Status:", "");
  setScreen(statusScreen, "Map: ", "Weather: ");

  setScreen(mapMenuScreen, "Select Map:", "A: GB", "B: UK", "C: Ireland", "D: Scotland");
  setScreen(weatherMenuScreen, "Select Weather:", "A = Clouds", "B = Thunder", "C = Snow", "D = Rain");
  setScreen(optionScreen, "Select Option:", "A = Weather", "B = Map", "C = All", "D = Undo");
}
void RGBWT::colourInit(){
  colour.Red = matrix.color565(red[0],red[1],red[2]);
  colour.Green = matrix.color565(green[0],green[1],green[2]);
  colour.Blue = matrix.color565(blue[0],blue[1],blue[2]);
  colour.White = matrix.color565(50,50,50);
  colour.Purple = matrix.color565(50,blue[1],50);
  colour.Yellow = matrix.color565(50,50,red[2]);
  colour.Grey = matrix.color565(255,140,0);
  colour.Off = matrix.color565(0,0,0);
}
uint16_t RGBWT::getColour(uint8_t red, uint8_t green, uint8_t blue) {
  return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
}

//set individual struct initialization
void RGBWT::setMapColour(){
  landColour = colour.Green;
  waterColour = colour.Blue;
}
void RGBWT::setScreen(screen s, String t, String b){
  s.top = t;
  s.Bottom = b;
}
void RGBWT::setScreen(screen s, String t, String opOne, String opTwo, String opThree, String opFour){
  s.top = t;
  String options[4] = {opOne, opTwo, opThree, opFour};
  for (int i = 0; i < 4; i++){
    s.option[i] = options[i];
  }
}
void RGBWT::setMap(map m, String n, coord la, coord lo, int mm[32][16]){
  m.displayName = n;
  m.lat = la;
  m.lon = lo;
  memcpy(m.displayMap, mm, sizeof(m.displayMap));
}
void RGBWT::setCoord(coord c, float mx, float mn, float md){
  c.max = mx;
  c.min = mn;
  c.mod = md;
  c.diff = c.max - c.min;
  c.inc = c.diff / c.mod;
}
void RGBWT::setWeather(weather w, String n, int ma, int mi, uint16_t c){
  w.displayName = n;
  w.idMax = ma;
  w.idMin = mi;
  w.displayColour = c;
}

//menu display and user input functions
void RGBWT::selectMap(){
  map mapList[4] = {unitedKingdom, greatBritain, scotland, ireland};
  display.displayTop(mapMenuScreen.top);
  currentMap = mapList[getInput(mapMenuScreen.option)];
  input.button = 0;
}
void RGBWT::selectWeather(){
  weather WeatherList[4] = {rain, thunder, snow, cloud};
  display.displayTop(weatherMenuScreen.top);
  currentWeather = WeatherList[getInput(weatherMenuScreen.option)];
  input.button = 0;
}
void RGBWT::selectOption(){
  display.displayTop(optionScreen.top);
  int select = getInput(optionScreen.option);
  switch (select){
    case 1:
      selectWeather();
      break;
    case 2:
      selectMap();
      break;
    case 3:
      selectWeather();
      selectMap();
      break;
    case 4:
      break;
  }
}



void RGBWT::checkMap(int a, int b, uint16_t lc){
  uint16_t mc;
  if (currentMap.displayMap[a][b] == 1){
    mc = lc;
  }
  else{
    mc = waterColour;
  }
  pixelColour = mc;
}

void RGBWT::drawMap(){
  for (int x = 0; x < 32; x++){
    for (int y = 15; y > -1; y--){
      checkMap(x, -(y-15), landColour);
      matrix.drawPixel(x, y, pixelColour);
    }
  }
  matrix.show();
}



void RGBWT::checkWeather(int id, int a, int b){
  if (id >= currentWeather.idMin && id < currentWeather.idMax) { 
    checkMap(a, -(b-15), currentWeather.colour);
  } else {
    checkMap(a,-(b-15), land);
  }

}