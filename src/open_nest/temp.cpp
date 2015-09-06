#include <Adafruit_HTU21DF.h>
#include "temp.h"

Adafruit_HTU21DF htu;
termomether _t;

termomether temp_read() {
  _t.temperature = htu.readTemperature();
  _t.humidity    = htu.readHumidity();
  return _t;
}

void temp_init() {
  htu = Adafruit_HTU21DF();
  htu.begin();
}
