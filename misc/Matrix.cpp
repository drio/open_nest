#include <Arduino.h>

#include "Matrix.h"

#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

Matrix::Matrix(void)
{
  /*
  low  = Adafruit_8x8matrix();
  high = Adafruit_8x8matrix();

  low.begin(0x70);
  high.begin(0x71);

  low.setTextSize(1);
  low.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  low.setTextColor(LED_ON);

  high.setTextSize(1);
  high.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  high.setTextColor(LED_ON);
  */
}

void Matrix::doIt()
{
  /*
    low.clear();
    low.setCursor(0,0);
    low.print("1");
    low.writeDisplay();
    delay(100);
  */
}

void Matrix::doSomethingSecret(void)
{
  //private method
}

