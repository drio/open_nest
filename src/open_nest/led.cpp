#include <Arduino.h>
#include "led.h"

void led_init() {
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
  pinMode(PIN_BLUE, OUTPUT);
}

void led_color(int r, int g, int b) {
  analogWrite(PIN_RED, r);
  analogWrite(PIN_GREEN, g);
  analogWrite(PIN_BLUE, b);
}

void led_status(int status) {
  if (status == STATUS_AC_ON)   led_color(0,0,255);
  if (status == STATUS_HEAT_ON) led_color(255,0,0);
  if (status == STATUS_OFF)     led_color(0,0,0);
}

