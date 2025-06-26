#ifndef RGBWT_nenu_h
#define RGBWT_menu_h
#include <Arduino.h>
//#include <RGBWT_screen.h>

class RGBWT_menu{
  public:
    String top[4];
    String bottom[4];
    RGBWT_menu(String[] t, String[] b);
    RGBWT_menu();
    String[] getTop();
    String[] getBottom();
    //void set(String[] list, String[] section);
    
};


#endif