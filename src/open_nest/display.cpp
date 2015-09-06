#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>
#include "display.h"

matrix_display display = {
  Adafruit_8x8matrix(),
  Adafruit_8x8matrix()
};

void display_single(Adafruit_8x8matrix m, char digit) {
  m.clear();
  m.setCursor(0,0);
  m.print(digit);
  m.writeDisplay();
}

void display_number(int number) {
  char buff[6];
  itoa(number, buff, 10);
  display_single(display.high, buff[0]);
  display_single(display.low, buff[1]);
}

void display_init() {
  display.low.begin(0x70);
  display.high.begin(0x71);
}

