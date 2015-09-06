#include <Arduino.h>
#include "relay.h"

void relay_ac_on()  { digitalWrite(PIN_RELAY_1, LOW); }
void relay_ac_off() { digitalWrite(PIN_RELAY_1, HIGH); }

void relay_heat_on()  { digitalWrite(PIN_RELAY_2, LOW); }
void relay_heat_off() { digitalWrite(PIN_RELAY_2, HIGH); }

void relay_init() {
  pinMode(PIN_RELAY_1, OUTPUT);
  pinMode(PIN_RELAY_2, OUTPUT);
}
