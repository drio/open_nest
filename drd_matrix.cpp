#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "drd_matrix.h"

void drd_matrices_init() {
  Adafruit_8x8matrix low_matrix = Adafruit_8x8matrix();
  Adafruit_8x8matrix high_matrix = Adafruit_8x8matrix();

  low_matrix.begin(0x70);
  high_matrix.begin(0x71);

  low_matrix.clear();
  high_matrix.clear();

  low_matrix.setTextSize(1);
  low_matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  low_matrix.setTextColor(LED_ON);

  high_matrix.setTextSize(1);
  high_matrix.setTextWrap(false);  // we dont want text to wrap so it scrolls nicely
  high_matrix.setTextColor(LED_ON);



//void drd_matrices_doit(Adafruit_8x8matrix matrix) {
    low_matrix.clear();
    low_matrix.setCursor(0,0);
    low_matrix.print(1);
    low_matrix.writeDisplay();
    delay(1000);

    high_matrix.clear();
    high_matrix.setCursor(0,0);
    high_matrix.print(3);
    high_matrix.writeDisplay();
    delay(1000);

    high_matrix.clear();
    low_matrix.clear();
    delay(10000);

  //matrix.setRotation(0);
}
