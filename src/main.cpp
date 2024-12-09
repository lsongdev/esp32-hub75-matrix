#include <Arduino.h>
#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

#define ESP32_LED_BUILTIN 2

MatrixPanel_I2S_DMA *display = nullptr;

void setup()
{
  HUB75_I2S_CFG mxconfig(64, 64, 1);
  // Swap Blue and Green pins because the panel is RBG instead of RGB.
  // mxconfig.gpio.b1 = 26;
  // mxconfig.gpio.b2 = 12;
  // mxconfig.gpio.g1 = 27;
  // mxconfig.gpio.g2 = 13;
  // mxconfig.gpio.e = 18;
  // mxconfig.clkphase = false;
  // Display Setup
  display = new MatrixPanel_I2S_DMA(mxconfig);
  display->begin();
  display->setBrightness8(50);
  display->clearScreen();
  // draw text with a rotating colour
  display->setTextSize(1);     // size 1 == 8 pixels high
  display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
  display->setCursor(0, 0);    // start at top left, with 8 pixel of spacing
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
}

void loop()
{
}