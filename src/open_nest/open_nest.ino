#include <Wire.h>
#include <Arduino.h>

#include "led.h"
#include "display.h"
#include "pot.h"

#define PIN_TEMP  A1

void setup() {
  Serial.begin(9600);
  led_init();
  display_init();
}

void loop() {
  char msg[10];
  //led_status(STATUS_AC_ON);
  itoa(pot_read(), msg, 10);
  Serial.println(pot_read());
  display_number(msg);
  delay(1000);
}
