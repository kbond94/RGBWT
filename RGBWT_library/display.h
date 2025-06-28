#include "RGBWT_display.h"

RGBWT_display startUp("Hello There", "Starting up...");
RGBWT_display status("Map: ", "Weather: ");
RGBWT_display wifi("Wifi Status:", );


String list[4];
list = {"A: GB", "B: UK", "C: Ireland", "D: Scotland"};
RGBWT_display mapMenu("Select Map:", list[0], list[1], list[2], list[3]);
list = {"A = Clouds", "B = Thunder", "C = Snow", "D = Rain"}
RGBWT_display weatherMenu("Select Weather:", list[0], list[1], list[2], list[3]);
list = {"A = Weather", "B = Map", "C = All", "D = Undo"}
RGBWT_display pauseMenu("Select Option:", list[0], list[1], list[2], list[3]);
