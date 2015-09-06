#include "pot.h"

/*
 * Given the potentiometer measurement in volts, convert
 * that to a temperature value (celcious) in between a range
 * the range [POT_TEMP_MIN, POT_TEMP_MAX]
 */
int fromVoltToTemp(int voltage) {
  int i, j;

  for (i=POT_MIN, j=0; i<=POT_MAX; i=i+POT_STEP, ++j)
    if (i >= voltage)
      break;

  return POT_TEMP_MIN + j;
}

int pot_read() {
  return fromVoltToTemp(analogRead(PIN_POT));
}
