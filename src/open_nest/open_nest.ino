#include <Wire.h>
#include <Arduino.h>

#include "led.h"
#include "display.h"
#include "pot.h"
#include "temp.h"
#include "relay.h"

enum systemMode { AC, HEAT };

systemMode mode = AC;
int lastChantedPot = -80;
int desiredTemp = 0;
int currentTemp = 0;

void setup() {
  Serial.begin(9600);
  led_init();
  display_init();
  temp_init();
  relay_init();
}

void loop() {
  static int wait = 0;

  if (!wait)  { // sample current temperature
    wait = 1000;
    currentTemp = temp_read().temperature;
  }

  int pot_voltage = pot_read_voltage();
  if (fabsf(pot_voltage - lastChantedPot) > 64) { // No significant move in the pot
    desiredTemp = pot_read_temperature();
    display_number(desiredTemp);
    lastChantedPot = pot_voltage;
  }

  if (mode == AC) {
    if (desiredTemp < currentTemp) {
      relay_ac_on();
      led_blue();
    }
    else {
      relay_ac_off();
      led_green();
    }
  }
  else {
    if (desiredTemp > currentTemp)
      relay_heat_on();
    else
      relay_heat_off();
  }

  --wait;
}
