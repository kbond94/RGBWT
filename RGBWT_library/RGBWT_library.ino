/*Version 1 RGB LED Weather tracker Written by Keith Bond
Credits; 
Aaron Glover, Ayanfeolu Fataki, Charlotte Mitchell, Skye McConville for original led weather tracker, parts of original code is still used in this version
William Hickmott for finding new matrix and mapping concept, Thomas Hankinson for pcb and cad tutorials
Dr Ian Sandall and Dr Waleed Al Nuaimy for support in development of kit*/

#include "RGBWT.h"

RGBWT track;

//Api key
//String API_Key = "a3a2c5e3d6b202bcd09a5557e383fb49";

//move colours above land and water options, delete default values
/*uint16_t land = Green;
uint16_t water = Blue;*/


//main functions
void setup() {
  /*lcdSetup(); 
  Serial.begin(115200);
  pinMode(2,OUTPUT);
  pinMode(35,INPUT);
  pinMode(34,INPUT);
  pinMode(39,INPUT);
  pinMode(4,INPUT);
  
  ProtomatterStatus status = matrix.begin();
  Serial.print("Protomatter begin() status: ");
  Serial.println((int)status);
  if(status != PROTOMATTER_OK) {
    for(;;);
  }
  track.wifi(ssid, password, blinky);
  //wifiSetup();
  screen_check();
  Serial.println(allow_input);
  if (allow_input == 1){
    attachInterrupt(digitalPinToInterrupt(35), a, RISING);
    attachInterrupt(digitalPinToInterrupt(34), b, RISING);
    attachInterrupt(digitalPinToInterrupt(39), c, RISING);
    attachInterrupt(digitalPinToInterrupt(4), d, RISING);
    startUp(); 
  }*/
}

void loop() {
  /*// put your main code here, to run repeatedly:
  if (WiFi.status() == WL_CONNECTED)
  {
    HTTPClient http;
    Lat_f = Lat_Max;
    row = 0;
    col = 0;
    col_i = -1;
    while (Lat_f > Lat_Min + Lat_Inc) 
    {
      col_i++;
      Lat_f = Lat_f - Lat_Inc;
      String Lat = String(Lat_f, 5);
      row_i = 16;
      Lon_f = Lon_Min;
      while (Lon_f <= Lon_Max - Lon_Inc) 
      {

        if (reset == 4) {
          reset = 0;
          resetTracker();
        }

        row_i--;
        Lon_f = Lon_f + Lon_Inc;
        String Lon = String(Lon_f, 5);

        String Add = webAdd(Lat,Lon);
        http.begin(Add);
        int httpCode = http.GET();
        if (httpCode > 0)
        {

          //apply json fix!
          String weather_data = http.getString();
        
          //String id = weather_data.substring(56, 59);
          //int id_no = id.toInt();
		      int id_no = getIdValue(weather_data);
          matrix.drawPixel(col_i, row_i, condColour);
          matrix.show();
          checkWeather(id_no, col_i, row_i);
          delay(100);
          matrix.drawPixel(col_i, row_i, colour);
          matrix.show();
        }
      }
    }
    //matrix.show();
    delay(5000);
    http.end();
    drawMap();
    delay(10000);
      //draw map here
  }*/
}


//additional functions
/*void setMap(int option){
  switch(option) {
    case 1:
      ms = "Default";
      setMatrixMap(defaultMatrixMap);
      setMapCoord(1);
      break;
    case 2:
      ms = "UK";
      setMatrixMap(oldMatrixMap);
      setMapCoord(2);
      break;
    case 3:
      ms = "Ireland";
      setMatrixMap(irishMatrixMap);
      setMapCoord(3);
      break; 
    case 4:
      ms = "Scotland";
      setMatrixMap(scotMatrixMap);
      setMapCoord(4);
      break;
    case 5:
      ms = "Merseyside";
      setMatrixMap(merseyMatrixMap);
      setMapCoord(5);
      break;     
  }
}

void setMatrixMap(int map[32][16]){
  for (int c = 0; c < 32; c++){
    for (int d = 15; d > -1; d--){
      matrixMap [c][d] = map [c][d];
    }
  }  
}

void setMapCoord(int check){
  switch(check){
    case 1:
      Lat_Max =  57.5;
      Lat_Min =  51;
      Lon_Max = 0.5;
      Lon_Min = -4.5;
      break;
    case 2:
      Lat_Max = 58.673473;
      Lat_Min = 49.953292;
      Lon_Max = 1.798398;
      Lon_Min = -6.793360;
      break;
    case 3:
      Lat_Max = 55.37210;
      Lat_Min = 51.45317;
      Lon_Max = -5.46974;
      Lon_Min = -10.08949;
      break;
    case 4:
      Lat_Max = 59.371243;
      Lat_Min = 54.640675;
      Lon_Max = -1.677607;
      Lon_Min = -7.524203;
      break;
    case 5:
      Lat_Max = 53.445960;
      Lat_Min = 53.330666;
      Lon_Max = -2.922317;
      Lon_Min = -3.228324;
      break;
  }
  Lat_Diff = Lat_Max - Lat_Min;
  Lat_Inc = (Lat_Diff) / 33;
  Lon_Diff = Lon_Max - Lon_Min;
  Lon_Inc = (Lon_Diff) / 17;

}

void checkMap(int a, int b, uint16_t lc){
  if (matrixMap[a][b] == 1){
    mapColour = lc;
  }
  else{
    mapColour = water;
  }
  colour = mapColour;
  return;
}

void drawMap(){
  for (int x = 0; x < 32; x++){
    for (int y = 15; y > -1; y--){
      checkMap(x, -(y-15), land);
      matrix.drawPixel(x, y, colour);
    }
  }
  matrix.show();
}

void blinky(){
  digitalWrite(2,HIGH);
  delay(300);
  digitalWrite(2,LOW);
  delay(300);
}

void wifiSetup(){

  lcd.setCursor(0,0);
  lcd.print("Wifi Status:");

  WiFi.begin(ssid, password);  // tell esp12e to begin wifi connection

  //WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_USERNAME, EAP_PASSWORD);
  int i = -1;
  //Serial.print("Connecting to WiFi. ");

  //needs putting into separate function
  while (WiFi.status() != WL_CONNECTED) 
  {

    if (i == 17){
      lcd.setCursor(0,1);
      lcd.print("                ");
      i = 0;
    }
    i = i + 1;
    lcd.setCursor(i,1);
    lcd.print(".");

    Serial.print(".");
    //blinky();
  }
  digitalWrite(2,HIGH);
  Serial.println(ssid);  // print the name of the wifi it connected to

  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Connected!");

  delay(1000);
}

void setCondition(int x){
  switch (x) {
    case 1:
      ws = "Rain";
      idMin = 300;
      idMax = 532;
      condColour = Red;
      break;
    case 2:
      ws = "Thunder";
      idMin = 200;
      idMax = 233;    
      condColour = Purple;
      break;
    case 3:
      ws = "Snow";
      idMin = 600;
      idMax = 623;    
      condColour = White;
      break;
    case 4:
      ws = "Clouds";
      idMin = 801;
      idMax = 805;    
      condColour = Grey;
      break;
  }
}

void checkWeather(int id, int a, int b){
  if (id >= idMin && id < idMax) { 
    checkMap(a, -(b-15), condColour);
  } else {
    checkMap(a,-(b-15), land);
  }

  /*if (id >= idMin && id < idMax) { 
    checkMap(a, -(b-15), condColour);
  } 
  else if (id == 0){
    checkMap(a, -(-b-15), Off);
  }
  else {
    checkMap(a,-(b-15), land);
  }*//*

}

String webAdd(String la, String Lo){
 String webAdd = "http://api.openweathermap.org/data/2.5/weather?lat=";
 webAdd = webAdd + la;
 webAdd = webAdd + "&lon=";
 webAdd = webAdd + Lo;
 webAdd = webAdd + "&appid=";
 webAdd = webAdd + API_Key;

 return webAdd;

}

void d(){
  reset = 4;  
}

void b(){
  reset = 2;
}

void c(){
  reset = 3;
}

void a(){
  reset = 1;
}

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

void screen_check(){
  Wire.beginTransmission(add);
  int error = Wire.endTransmission();
  Serial.println(error);
  if (error == 2){
    setMap(5);
    setCondition(4);
    drawMap();
    delay(2000);    
  }
  else {
    allow_input = 1;
  }
}

void startUp(){
  getMap();
  getWeather();
  dispStatus();
  drawMap();
  delay(2000);      
}

void resetTracker(){
  reset = 0;
  lcd.clear();
  String option [4] = {"A = Weather", "B = Map", "C = All", "D = Undo"};
  dispMsgTop("Select Option:");
  int i = 0;
  while (1){
    if (reset > 0 && reset < 4){
      resetCoord();
    }    
    if (reset > 0){
      break;
    }
    dispMsgBottom(option [i]);
    i = i + 1;
    if (i == 4){
      i = 0;
    }
    delay(1000);
  }
  switch (reset){
    case 1:
      getWeather();
      drawMap();
      break;
    case 2:
      getMap();
      drawMap();
      break;
    case 3:
      getWeather();
      getMap();
      drawMap();
      break;
    case 4:
      break;
  }
  reset = 0;
  dispStatus();
}

void resetCoord(){
  Lat_f = Lat_Max;
  row = 0;
  col = 0;
  col_i = -1;
  row_i = 16;
  Lon_f = Lon_Min;
}

void dispMsgTop(String text){
  lcd.setCursor(0,0);
  lcd.print("                ");  
  lcd.setCursor(0,0);
  lcd.print(text);  
}

void dispMsgBottom(String txt){
  lcd.setCursor(0,1);
  lcd.print("                ");  
  lcd.setCursor(0,1);
  lcd.print(txt);  
}

void getMap(){
  reset = 0;
  lcd.clear();
  String option [4] = {"A = Default", "B = UK", "C = Ireland", "D = Scotland"};
  dispMsgTop("Select Map:");
  int i = 0;
  //needs removing once more maps added
  while (1){   
    if (reset > 0){
      break;
    }
    dispMsgBottom(option [i]);
    i = i + 1;
    if (i == 4){
      i = 0;
    }
    delay(1000);
  }
  switch (reset){
    case 1:
      setMap(1);
      break;
    case 2:
      setMap(2);
      break;
    case 3:
      setMap(3);
      break;
    case 4:
      setMap(4);
      break;
  }
  reset = 0;
}

void getWeather(){
  reset = 0;
  lcd.clear();
  dispMsgTop("Select Weather:");
  String option [4] = {"A = Clouds", "B = Thunder", "C = Snow", "D = Rain"};
  int i = 0;
  while (1){
    if (reset > 0){
      break;
    }
    dispMsgBottom(option [i]);
    i = i + 1;
    if (i == 4){
      i = 0;
    }
    delay(1000);
  }
  switch (reset){
    case 1:
      setCondition(4);
      break;
    case 2:
      setCondition(2);
      break;
    case 3:
      setCondition(3);
      break;
    case 4:
      setCondition(1);
      break;      
  }
  reset = 0;
}

int getIdValue(String data){
  StaticJsonDocument<400> doc;
  StaticJsonDocument<200> filter;
  //filter["name"]= true;
  filter["weather"][0]["id"]= true;
  //filter["main"]["temp"] = true;

  DeserializationError error = deserializeJson(doc, data, DeserializationOption::Filter(filter));

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return 0;
  }

  JsonObject weather = doc["weather"][0];
  JsonObject main = doc["main"];

  int id = weather["id"];
  //float temp = main["temp"];
  //const char* name = doc["name"];
  //String name = doc["name"];
  /*if (name.length()> 12){
    name = name.substring(0, name.indexOf(' '));
  }*//*

  Serial.println(id);
  //Serial.println(temp);
  //Serial.print(name + ", ");  
  
  return id;

}*/

