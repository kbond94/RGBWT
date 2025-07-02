#include "Arduino.h"
#include "RGBWT_matrixMap.h"
#include "RGBWT.h"

RGBWT::RGBWT(): display(), input(), client(), wifi(), matrix(bw, bd, cc, rgbPins, ac, addrPins, clockPin, latchPin, oePin, false) {
  //
}

void RGBWT::init(){
  inputInit();
  matrixInit();
  colourInit();
  setMapColour();
  weatherInit();
  mapInit();
}

void RGBWT::inputInit(){
  inputInit(35, 34, 39, 4);
}
void RGBWT::inputInit(int i,int m, int x, int y){
  input.init(i, m, x, y);
}
int RGBWT::getInput(String ops[4]){
  int dispOption;
  int option;
  input.button = 0;
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
  if (wifi.status() == 1){
    lat_f = currentMap.lat.max;
    row = 0;
    col = 0;
    col_i = -1;
    while (lat_f > currentMap.lat.min + currentMap.lat.inc) {
      col_i++;
      lat_f = lat_f - currentMap.lat.inc;
      String Lat = String(lat_f, 5);
      row_i = 16;
      lon_f = currentMap.lon.min;
      while (lon_f <= currentMap.lon.max - currentMap.lon.inc) {

        if (input.button == 4) {
          //reset = 0;
          selectOption();
        }

        row_i--;
        lon_f = lon_f + currentMap.lon.inc;
        String Lon = String(lon_f, 5);

        String Add = genAddress(Lat,Lon);
        client.begin(Add);
        int httpCode = client.GET();
        if (httpCode > 0){
          //apply json fix!
          String weather_data = client.getString();
		      int id_no = getIdValue(weather_data);
          matrix.drawPixel(col_i, row_i, currentWeather.displayColour);
          matrix.show();
          checkWeather(id_no, col_i, row_i);
          delay(100);
          matrix.drawPixel(col_i, row_i, pixelColour);
          matrix.show();
        }
      }
    }
    //matrix.show();
    delay(5000);
    client.end();
    drawMap();
    delay(10000);
  }
}
void RGBWT::start(){
  selectMap();
  selectWeather();
  //run menu
  //get map
  //get weather
}

//set all struct initialisation
void RGBWT::matrixInit(){
  ProtomatterStatus status = matrix.begin();
  Serial.print("Protomatter begin() status: ");
  Serial.println((int)status);
  if(status != PROTOMATTER_OK) {
    for(;;);
  }
}
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
void RGBWT::setWeather(weatherType w, String n, int ma, int mi, uint16_t c){
  w.displayName = n;
  w.idMax = ma;
  w.idMin = mi;
  w.displayColour = c;
}

void RGBWT::setWifi(const char *usr, const char *psd, const char *ssid, void (*function)()){
  wifi.init(usr, psd, ssid, function);
}
void RGBWT::setWifi(const char *ssid, const char *psd, void (*function)()){
  wifi.init(ssid, psd, function);
}

//menu display and user input functions
void RGBWT::selectMap(){
  map mapList[4] = {unitedKingdom, greatBritain, scotland, ireland};
  display.displayTop(mapMenuScreen.top);
  currentMap = mapList[getInput(mapMenuScreen.option)];
  input.reset();
}
void RGBWT::selectWeather(){
  weatherType WeatherList[4] = {rain, thunder, snow, cloud};
  display.displayTop(weatherMenuScreen.top);
  currentWeather = WeatherList[getInput(weatherMenuScreen.option)];
  input.reset();
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
    checkMap(a, -(b-15), currentWeather.displayColour);
  } else {
    checkMap(a,-(b-15), landColour);
  }

}

String RGBWT::genAddress(String La, String Lo){
 String webAdd = "http://api.openweathermap.org/data/2.5/weather?lat=";
 webAdd = webAdd + La;
 webAdd = webAdd + "&lon=";
 webAdd = webAdd + Lo;
 webAdd = webAdd + "&appid=";
 webAdd = webAdd + API_key;

 return webAdd;
}

int RGBWT::getIdValue(String data){
  StaticJsonDocument<400> doc;
  StaticJsonDocument<200> filter;
  filter["weather"][0]["id"]= true;

  DeserializationError error = deserializeJson(doc, data, DeserializationOption::Filter(filter));

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return 0;
  }

  JsonObject weather = doc["weather"][0];
  JsonObject main = doc["main"];

  int id = weather["id"]; 
  
  return id;

}

void RGBWT::setApi(String api){
  API_key = api;  
}