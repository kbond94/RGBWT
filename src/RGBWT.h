#ifndef RGBWT_h
#define RGBWT_h
#include "Arduino.h"
#include "RGBWT_input.h"
#include "RGBWT_WiFi.h"
#include "RGBWT_screen.h"
#include <Adafruit_Protomatter.h>
#include <ArduinoJson.h>
#include <HTTPClient.h> 

class RGBWT{
  public:
    //RGB matrix pin and class
    uint8_t rgbPins[6]={25, 26, 27, 19, 15, 23};
    uint8_t addrPins[3]={12, 16, 17};
    uint8_t clockPin=5; // Must be on same port as rgbPins
    uint8_t latchPin=32;
    uint8_t oePin=33;
    uint16_t bw = 32;
    uint8_t bd = 4;
    uint8_t cc = 1;
    uint8_t ac = 3;
    Adafruit_Protomatter matrix;


    uint8_t red[3] = {25, 0, 0};
    uint8_t blue[3] = {0, 0, 25};
    uint8_t green[3] = {0, 25, 0};

    RGBWT_input input;
    RGBWT_screen display;
    RGBWT_WiFi wifi;
    HTTPClient client;

    String API_key;

    //weather struct
    typedef struct weatherType{
		  String displayName = "";
      int idMax;
      int idMin;
      uint16_t displayColour;
    } weatherType;
    weatherType rain;
    weatherType thunder;
    weatherType snow;
    weatherType cloud;
    weatherType currentWeather;

    //coordinate struct used in map struct
    typedef struct coord {
      float max;
      float min;
      float diff;
      float inc;
      float mod;
    } coord;

    //map struct, used in storing map coordinates and map array
    typedef struct map{
      String displayName = "";
      coord lat;
      coord lon;
      int displayMap[32][16];
    } map;
    map unitedKingdom;
    map greatBritain;
    map scotland;
    map ireland;
    map merseyside;
    map currentMap;

    //colour struct to hold and call colours used in matrix
    typedef struct colours{
      uint16_t Red;
      uint16_t Green;
      uint16_t Blue;
      uint16_t White;
      uint16_t Purple;
      uint16_t Yellow;
      uint16_t Grey;
      uint16_t Off;
    } colours;
    colours colour;
    uint16_t landColour;  
    uint16_t waterColour;
    uint16_t pixelColour;

    //screen struct and variables
    typedef struct screen{
      String top;
      String Bottom;
      String option[4];
    } screen;
    screen startScreen;
    screen wifiConnScreen;
    screen statusScreen;

    screen weatherMenuScreen;
    screen mapMenuScreen;
    screen optionScreen;

    float lat_f;
    float lon_f;
    int col;
    int col_i;
    int row;
    int row_i;

    RGBWT();
    void init();
    int getInput(String ops[4]);

    void weather();
    void start();

    void inputInit();
    void inputInit(int i,int m, int x, int y);
    void matrixInit();
    void weatherInit();
    void mapInit();
    void colourInit();
    void screenInit();

    void setWifi(const char *usr, const char *psd, const char *ssid, void (*)());
    void setWifi(const char *ssid, const char *psd, void (*)());
    void setWeather(weatherType w, String n, int ma, int mi, uint16_t c);
    void setCoord(coord c, float mx, float mn, float md);
    void setMap(map m, String n, coord la, coord lo, int mm[32][16]);
    void setMapColour();
    void setMapColour(uint16_t lc, uint16_t sc);
    void setScreen(screen s, String t, String b);
    void setScreen(screen s, String t, String opOne, String opTwo, String opThree, String opFour);
    
    void selectWeather();
    void selectMap();
    void selectOption();

    void drawMap();
    void checkMap(int a, int b, uint16_t lc);
    void checkWeather(int id, int a, int b);

    int getIdValue(String data);
    void setApi(String api);
    String genAddress(String La, String Lo);
  private:
};

#endif 