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
  display->setCursor(0, 0);
  display->setTextColor(display->color444(0, 0, 255));
  display->println("Hello");
}

void loop()
{
}