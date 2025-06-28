#include "RGBWT_screen.h"
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

RGBWT_screen::RGBWT_screen(){
  lcd(address, 16, 2);

}

void  RGBWT_screen::displayTop(String mt){
  lcd.setCursor(0,0);
  lcd.print("                ");  
  lcd.setCursor(0,0);
  lcd.print(mt);
}

void RGBWT_screen::displayBottom(String mb){
  lcd.setCursor(0,1);
  lcd.print("                ");  
  lcd.setCursor(0,1);
  lcd.print(mb); 
}

void RGBWT_screen::clear(){
  lcd.clear();
}

void RGBWT_screen::setup(){
  lcd.init();
  lcd.clear();     
  lcd.backlight();
}

int RGBWT_screen::check(){
  Wire.beginTransmission(address);
  int conn = Wire.endTransmission();
  int check = 1;
  if (conn == 2){
    check = 0;
  }
  return check;
}

/*
void lcdSetup(){
  lcd.init();
  lcd.clear();     
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello There");
  lcd.setCursor(0,1);
  lcd.print("Starting up...");
  delay(2000);
  lcd.clear();
}

void dispStatus(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Map: " + ms);
  lcd.setCursor(0, 1);
  lcd.print("Weather: " + ws);
}
*/