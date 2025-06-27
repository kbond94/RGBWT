#ifndef RGBWT_nenu_h
#define RGBWT_menu_h
#include <Arduino.h>
//#include <RGBWT_screen.h>

class RGBWT_menu{
  public:
    char top[4];
    char bottom[4];
    RGBWT_menu(char* t, char* b);
    RGBWT_menu();
    //void set(String[] list, String[] section);
    
};


#endif