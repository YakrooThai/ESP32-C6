
#include <FS.h>
#include <SD.h>
#include <SPI.h>

#include "DFRobot_GDL.h"
#include "DFRobot_Picdecoder_SD.h"

//SD CARD pins
#define SCK    23
#define MISO   21
#define MOSI   22
#define SS     9

DFRobot_Picdecoder_SD decoder;

#define TFT_DC  8
#define TFT_CS  1
#define TFT_RST 14
#define TFT_SD  9

DFRobot_ST7789_240x320_HW_SPI screen(/*dc=*/TFT_DC,/*cs=*/TFT_CS,/*rst=*/TFT_RST);

void setup()
{
   Serial.begin(9600);
   SPI.begin(SCK, MISO, MOSI, SS);
   //Initialize screen
   screen.begin();
  //Initialize the SD card, wait until the initialization is successful
   if (!SD.begin(SS, SPI, 40000000)) {
    Serial.println("Card Mount Failed");
    return;
  }
  Serial.println("Card Mounted");
  Serial.println("SD Card OK");   
}

void loop()
{
  screen.fillScreen(COLOR_RGB565_BLACK);
  screen.setTextSize(2);
  screen.setFont(&FreeMono9pt7b);
  screen.setCursor(/*x=*/12,/*y=*/24);
  screen.setTextColor(COLOR_RGB565_LGRAY);
  screen.setTextWrap(true);
  screen.print("PhotoFrame");
  delay(500);
  
  decoder.drawPicture("/ss1.bmp",50,80,207,208,screenDrawPixel);

  for(;;)
    delay(1000);
}

//For decoding function calling, the function of this function is to draw a pixel on the screen
void screenDrawPixel(int16_t x, int16_t y, uint16_t color)
{
  //Draw a point on the screen
  screen.writePixel(x,y,color);
}
