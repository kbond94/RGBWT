#include "Arduino.h"
#include "RGBWT_matrix.h"
#include <Adafruit_Protomatter.h>

uint8_t red[3] = {25, 0, 0};
uint8_t blue[3] = {0, 0, 25};
uint8_t green[3] = {0, 25, 0};
uint16_t Red = RGBWT_matrix.color565(red[0],red[1],red[2]);
uint16_t Green = RGBWT_matrix.color565(green[0],green[1],green[2]);
uint16_t Blue = RGBWT_matrix.color565(blue[0],blue[1],blue[2]);
uint16_t White = RGBWT_matrix.color565(50,50,50);
uint16_t Purple = RGBWT_matrix.color565(50,blue[1],50);
uint16_t Yellow = RGBWT_matrix.color565(50,50,red[2]);
uint16_t Grey = RGBWT_matrix.color565(255,140,0);
uint16_t Off = RGBWT_matrix.color565(0,0,0);