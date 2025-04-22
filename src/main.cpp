#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>
#include <U8g2_for_Adafruit_GFX.h>

#define ESP32_LED_BUILTIN 2
#define PANEL_WIDTH 64
#define PANEL_HEIGHT 64
#define SCROLL_SPEED 50

MatrixPanel_I2S_DMA *display = nullptr;
U8G2_FOR_ADAFRUIT_GFX u8g2;

const char *message = "欢迎使用LED矩阵显示屏，这是一个中文滚动显示的示例。";
int16_t scrollPosition = PANEL_WIDTH;

void setup()
{
  HUB75_I2S_CFG mxconfig(64, 64, 1);
  mxconfig.gpio.e = 18;
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

  u8g2.begin(*display);
  u8g2.setFont(u8g2_font_wqy16_t_gb2312);
}

void loop()
{
  display->clearScreen();
  int16_t textWidth = u8g2.getUTF8Width(message);
  u8g2.setForegroundColor(display->color444(255, 0, 255));
  u8g2.setCursor(scrollPosition, 32);
  u8g2.print(message);

  scrollPosition--;

  if (scrollPosition < -textWidth)
  {
    scrollPosition = PANEL_WIDTH;
  }

  delay(40);
}