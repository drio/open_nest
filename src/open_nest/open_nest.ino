#include <Wire.h>
#include <Arduino.h>

#include "led.h"
#include "display.h"

#define PIN_POT        A0
#define PIN_TEMP       A1

void setup() {
  Serial.begin(9600);
  led_init();
  display_init();
}

void loop() {
  char msg[3] = "71";
  display_number(msg);

  led_status(STATUS_AC_ON);
  delay(2000);
  led_status(STATUS_HEAT_ON);
  delay(2000);
  led_status(STATUS_OFF);
  delay(2000);
}
