#include <Wire.h>
#include "drd_matrix.h"
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#include "Test.h"

Test myTest = Test(2);
Adafruit_8x8matrix low = Adafruit_8x8matrix();
Adafruit_8x8matrix high = Adafruit_8x8matrix();


void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  low.begin(0x70);  // pass in the address
  high.begin(0x71);  // pass in the address
}

void loop() {
  myTest.doSomething();

  low.clear();
  low.setCursor(0,0);
  low.print("1");
  low.writeDisplay();
  delay(100);

  high.clear();
  high.setCursor(0,0);
  high.print("2");
  high.writeDisplay();
  delay(100);

  //drd_matrices_init();
}
