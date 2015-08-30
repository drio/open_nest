#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_8x8matrix matrix_low = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix_high = Adafruit_8x8matrix();

void display_single(Adafruit_8x8matrix m, char digit) {
  m.clear();
  m.setCursor(0,0);
  m.print(digit);
  m.writeDisplay();
}

void display_number(char *number) {
  display_single(matrix_low, number[1]);
  display_single(matrix_high, number[0]);
}

void display_init() {
  matrix_low.begin(0x70);
  matrix_high.begin(0x71);
}

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  display_init();
  display_number("39");
}

void loop() {

  int voltage = analogRead(A0) * (5.0 / 1023.0);

  char buf[12];
  itoa(voltage, buf, 10);
  display_number();

  Serial.println(analogRead(A0));
  Serial.println(voltage);
  Serial.println(buf);
  Serial.println("--");

  delay(2000);
  //display.doIt();
}
