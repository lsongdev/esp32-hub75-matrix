#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <U8g2_for_Adafruit_GFX.h>

#define ESP32_LED_BUILTIN 2
#define PANEL_WIDTH 64
#define PANEL_HEIGHT 64

MatrixPanel_I2S_DMA *display = nullptr;
U8G2_FOR_ADAFRUIT_GFX u8g2;

const char *message = "欢迎使用";

void setup()
{
  HUB75_I2S_CFG mxconfig(PANEL_WIDTH, PANEL_HEIGHT, 1);
  mxconfig.gpio.e = 18;
  // BRG
  // mxconfig.gpio.r1 = 27;
  // mxconfig.gpio.r2 = 13;
  // mxconfig.gpio.g1 = 25;
  // mxconfig.gpio.g2 = 14;
  // mxconfig.gpio.b1 = 26;
  // mxconfig.gpio.b2 = 12;
  mxconfig.clkphase = false;
  
  display = new MatrixPanel_I2S_DMA(mxconfig);
  display->begin();
  display->setBrightness8(50);
  display->clearScreen();
  display->setTextSize(1); // size 1 == 8 pixels high
  display->setTextWrap(false);
  display->setCursor(0, 0);
  display->setTextColor(display->color444(15, 15, 15));
  display->println("LED MATRIX!");

  // print each letter with a fixed rainbow color
  display->setTextColor(display->color444(0, 8, 15));
  display->print('6');
  display->setTextColor(display->color444(15, 4, 0));
  display->print('4');
  display->setTextColor(display->color444(15, 15, 0));
  display->print('x');
  display->setTextColor(display->color444(8, 15, 0));
  display->print('6');
  display->setTextColor(display->color444(8, 0, 15));
  display->print('4');

  // Jump a half character
  display->setCursor(34, 24);
  display->setTextColor(display->color444(0, 15, 15));
  display->print("*");
  display->setTextColor(display->color444(15, 0, 0));
  display->print('R');
  display->setTextColor(display->color444(0, 15, 0));
  display->print('G');
  display->setTextColor(display->color444(0, 0, 15));
  display->print("B");
  display->setTextColor(display->color444(15, 0, 8));
  display->println("*");
  delay(3000);
  display->clearScreen();
  display->setTextColor(display->color444(255, 0, 0));

  u8g2.begin(*display);
  u8g2.setFont(u8g2_font_wqy16_t_gb2312);
  u8g2.setForegroundColor(display->color444(255, 0, 0));
  u8g2.setCursor(1, 14);
  u8g2.print(message);
  u8g2.setForegroundColor(display->color444(0, 255, 0));
  u8g2.setCursor(1, 30);
  u8g2.print(message);
  u8g2.setForegroundColor(display->color444(0, 0, 255));
  u8g2.setCursor(1, 46);
  u8g2.print(message);
  u8g2.setForegroundColor(display->color444(255, 255, 0));
  u8g2.setCursor(1, 62);
  u8g2.print(message);
}

void loop()
{

}