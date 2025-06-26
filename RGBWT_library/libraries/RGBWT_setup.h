//lcd setup
;uint8_t add = 0x27;
LiquidCrystal_I2C lcd(add, 16, 2);

//input check
int allow_input = 0;

//matrix setup
uint8_t rgbPins[]  = {25, 26, 27, 19, 15, 23};
uint8_t addrPins[] = {12, 16, 17};
uint8_t clockPin   = 5; // Must be on same port as rgbPins
uint8_t latchPin   = 32;
uint8_t oePin      = 33;

Adafruit_Protomatter matrix(
  32,          // Width of matrix (or matrix chain) in pixels
  4,           // Bit depth, 1-6
  1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
  3, addrPins, // # of address pins (height is inferred), array of pins
  clockPin, latchPin, oePin, // Other matrix control pins
  false
); 

int matrixMap [32][16];

//coordinate setup

volatile float Lat_f;
volatile int row;
volatile int col;
volatile int col_i;
volatile int row_i;
volatile float Lon_f;

uint16_t mapColour;
uint16_t colour;

float Lat_Max;
float Lat_Min;
float Lat_Diff;
float Lat_Inc;
float Lon_Max;
float Lon_Min;
float Lon_Diff;      
float Lon_Inc;

String m = "";
String ms = "";

//8 bit colour
volatile uint8_t red [3] = {25, 0, 0};
volatile uint8_t blue [3] = {0, 0, 25};
volatile uint8_t green [3] = {0, 25, 0};

//weather variables
uint16_t weatherColour;


volatile int condition = 0;
int idMin = 300;
int idMax = 532;
uint16_t condColour;
String w = "";
String ws = "";

//input variable
volatile int reset;

//eduroam setup
/*define EAP_ANONYMOUS_IDENTITY wifiUsername
define EAP_IDENTITY wifiUsername
define EAP_PASSWORD wifiPassword
define EAP_USERNAME wifiUsername*/