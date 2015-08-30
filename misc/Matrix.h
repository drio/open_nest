#ifndef Matrix_h
#define Matrix_h

#include <Wire.h>

#include "Adafruit_GFX.h"
#include "Adafruit_LEDBackpack.h"

class Matrix
{
  /*
  Adafruit_8x8matrix low;
  Adafruit_8x8matrix high;
  */

  public:
    Matrix(void);
    void doIt(void);

  private:
    void doSomethingSecret(void);
};

#endif

