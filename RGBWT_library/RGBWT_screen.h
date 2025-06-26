#ifndef RGBWT_screen_h
#define RGBWT_screen_h
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

class RGBWT_screen{
  public:
    static uint8_t address = 0x27;
    LiquidCrystal lcd(add,16,2);
    RGBWT_screen();
    void displayTop(String msg[]);
    void displayBottom(String msg[]);
    void clear();
};

#endif