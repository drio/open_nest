#include <Wire.h>
#include <Arduino.h>

#include "led.h"
#include "display.h"
#include "pot.h"
#include "temp.h"
#include "relay.h"


void setup() {
  Serial.begin(9600);
  led_init();
  display_init();
  temp_init();
  relay_init();
}

void loop() {
  display_number(pot_read());
  Serial.println(temp_read().temperature);
  Serial.println(temp_read().humidity);
  relay_heat_on();
  relay_ac_on();
  delay(4000);

  relay_heat_off();
  relay_ac_off();
  delay(4000);
}
