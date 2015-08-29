#include <Wire.h>
#include "drd_matrix.h"

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  //drd_matrices_init();
}

void loop() {
  drd_matrices_init();
}
