#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define TMP A3  

void setup() {
  Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever    
  }
 // clear the display buffer.
  display.clearDisplay();
 
 display.setTextSize(1);   // text size = 1
  display.setTextColor(WHITE, BLACK);  // set text color to white and black background
  display.setCursor(15, 0);            // move cursor to position (15, 0) pixel
 
  display.display();        // update the display
  display.setTextSize(2);   // text size = 2
}
 
int  tCelsius, tFahrenheit;
char _buffer[8];
 
void loop()
{    
  // read analog voltage ( = tenths degree Celsius)
  //   9.3 = 1023/(1.1*100)
  tCelsius = 10 * analogRead(TMP)/9.3;
 
 
  tFahrenheit = tCelsius * 9/5 + 320 ; // convert tenths °C to tenths °Fahrenheit
 
  // print temperature in degree Celsius
  if (tCelsius >= 1000)    // if temperature >= 100.0 °C
    sprintf(_buffer, "%03u.%1u C", tCelsius / 10, tCelsius % 10);
  else
    sprintf(_buffer, " %02u.%1u C", tCelsius / 10, tCelsius % 10);
  display.setCursor(23, 10);
  display.print(_buffer);
    delay(2000);
  // print temperature in degree Fahrenheit
  if (tFahrenheit >= 1000)     // if temperature >= 100.0 °F
    sprintf(_buffer, "%03u.%1u F", tFahrenheit / 10, tFahrenheit % 10);
  else
    sprintf(_buffer, " %02u.%1u F", tFahrenheit / 10, tFahrenheit % 10);
  display.setCursor(23, 30);
  display.print(_buffer);
   
  delay(2000);
 
  // print degree symbols ( ° )
  display.drawCircle(88, 12, 2, WHITE);
  display.drawCircle(88, 32, 2, WHITE);
 
  // update the display
  display.display();
 
  delay(1000);  // wait a second
 
}
