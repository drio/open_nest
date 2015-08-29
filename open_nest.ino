/***************************************************
  This is a library for our I2C LED Backpacks

  Designed specifically to work with the Adafruit LED Matrix backpacks
  ----> http://www.adafruit.com/products/872
  ----> http://www.adafruit.com/products/871
  ----> http://www.adafruit.com/products/870

  These displays use I2C to communicate, 2 pins are required to
  interface. There are multiple selectable I2C addresses. For backpacks
  with 2 Address Select pins: 0x70, 0x71, 0x72 or 0x73. For backpacks
  with 3 Address Select pins: 0x70 thru 0x77

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

void do_it(Adafruit_8x8matrix matrix) {
  matrix.setTextSize(1);
  matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  matrix.setTextColor(LED_ON);

  for (int i=0; i<9; ++i) {
    matrix.clear();
    matrix.setCursor(0,0);
    matrix.print(i);
    matrix.writeDisplay();
    delay(1000);
  }

  matrix.setRotation(0);
}

Adafruit_8x8matrix low_matrix = Adafruit_8x8matrix();
Adafruit_8x8matrix high_matrix = Adafruit_8x8matrix();

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  low_matrix.begin(0x70);
  high_matrix.begin(0x71);
}

void loop() {
  do_it(low_matrix);
  do_it(high_matrix);
}
