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

  led_status(STATUS_AC_ON);
  display_number("21");
  delay(2000);

  led_status(STATUS_HEAT_ON);
  display_number("22");
  delay(2000);

  led_status(STATUS_OFF);
  display_number("23");
  delay(2000);
}
