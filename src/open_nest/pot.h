#ifndef drd_pot_h
#define drd_pot_h

#include <Arduino.h>
#include "pot.h"

#define PIN_POT A0
#define POT_MAX 1023
#define POT_MIN 0
#define POT_TEMP_MIN 18
#define POT_TEMP_MAX 30
#define POT_STEP ((POT_MAX - POT_MIN) / (POT_TEMP_MAX - POT_TEMP_MIN))

int pot_read_temperature();
float pot_read_voltage();

#endif

