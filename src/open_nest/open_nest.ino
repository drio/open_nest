#include <Wire.h>
#include <Arduino.h>
#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>
#include "led.h"

#define PIN_POT        A0
#define PIN_TEMP       A1

Adafruit_8x8matrix matrix_low = Adafruit_8x8matrix();
Adafruit_8x8matrix matrix_high = Adafruit_8x8matrix();

void display_single(Adafruit_8x8matrix m, char digit) {
  m.clear();
  m.setCursor(0,0);
  m.print(digit);
  m.writeDisplay();
}

void display_number(char *number) {
  display_single(matrix_low, number[1]);
  display_single(matrix_high, number[0]);
}

void display_init() {
  matrix_low.begin(0x70);
  matrix_high.begin(0x71);
}

float current_temp() {
  float voltage, celsius, fahrenheit;
  voltage    = analogRead(PIN_TEMP);
  voltage    = (voltage * 5.0) / 1024.0;
  celsius    = (voltage - 0.5) * 100.0;
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;

  Serial.print("Volts: "); Serial.println(voltage);
  Serial.print("Celsius: "); Serial.println(celsius);
  Serial.print("fahrenheit: "); Serial.println(fahrenheit);
  Serial.println("");
  return celsius;
}

void setup() {
  Serial.begin(9600);
  Serial.println("8x8 LED Matrix Test");

  led_init();
  display_init();
}

void loop() {
  char msg[2] = "5";
  display_number(msg);

  change_status(STATUS_AC_ON);
  delay(2000);
  change_status(STATUS_HEAT_ON);
  delay(2000);
  change_status(STATUS_OFF);
  delay(2000);
}
