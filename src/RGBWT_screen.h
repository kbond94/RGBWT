#ifndef RGBWT_screen_h
#define RGBWT_screen_h
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

class RGBWT_screen{
  public:
    uint8_t address = 0x27;
    LiquidCrystal_I2C lcd;
    //LiquidCrystal_I2C lcd(0x27, 16, 2);
    RGBWT_screen();
    void setup();
    void displayTop(String mt);
    void displayBottom(String mb);
    void clear();
    int check();
};

#endif