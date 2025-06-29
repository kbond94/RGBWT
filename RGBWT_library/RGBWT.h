#ifndef RGBWT_h
#define RGBWT_h
#include "Arduino.h"
//#include "map.h"
#include "RGBWT_input.h"
#include "RGBWT_matrix.h"
#include "RGBWT_screen.h"
//#include "RGBWT_matrixMap.h"
//#include <WiFi.h>
//#include "esp_wpa2.h"

class RGBWT{
  public:
    uint8_t red[3] = {25, 0, 0};
    uint8_t blue[3] = {0, 0, 25};
    uint8_t green[3] = {0, 25, 0};

    RGBWT_input input;
    RGBWT_screen display;

    typedef struct weather{
		  String displayName = "";
      int idMax;
      int idMin;
      uint16_t displayColour;
    } weather;
    weather rain;
    weather thunder;
    weather snow;
    weather cloud;
    weather currentWeather;

    typedef struct coord {
      float max;
      float min;
      float diff;
      float inc;
      float mod;
    } coord;

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
    uint16_t seaColour;

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

    //RGBWT_matrix matrix();
    RGBWT();
    void init();
    void wifi(const char *usr, const char *psd, const char *ssid, void (*)());
    void wifi(const char *ssid, const char *psd, void (*)());
    void http(String a);
    void inputInit(int i,int m, int x, int y);
    int getInput(String ops[4]);
    void track();
    void startup();
    void weatherInit();
    void mapInit();
    void colourInit();
    void screenInit();
    uint16_t getColour(uint8_t red, uint8_t green, uint8_t blue);
    void setWeather(weather w, String n, int ma, int mi, uint16_t c);
    void setCoord(coord c, float mx, float mn, float md);
    void setMap(map m, String n, coord la, coord lo, int mm[32][16]);
    void setMapColour();
    void setMapColour(uint16_t lc, uint16_t sc);
    void setScreen(screen s, String t, String b);
    void setScreen(screen s, String t, String opOne, String opTwo, String opThree, String opFour);
    void selectWeather();
    void selectMap();
    void selectOption();
  private:
};

#endif 