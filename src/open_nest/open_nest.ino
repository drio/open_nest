#include <Wire.h>
#include <Arduino.h>
#include <SPI.h>

#include "nRF24L01.h"
#include "RF24.h"
#include "printf.h"

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

// Instanciate class to deal with RF24 hardware
RF24 radio(9,10);
// Addresses for the pipes to read and write
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
// This is what we will send back to the remote RF24
typedef struct {
  int16_t desired_temp;
  int16_t current_temp;
  int16_t current_humidity;
} paquet;


void setup() {
  //Serial.begin(9600);
  led_init();
  display_init();
  temp_init();
  relay_init();

  // Setup the RF24 radio and start listening.
  Serial.begin(57600);
  printf_begin();
  radio.begin();
  radio.setRetries(15,15); // Delay, Count
  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1, pipes[0]);
  radio.startListening();
  radio.printDetails();
}

void loop() {
  static int wait = 0;
  static unsigned short remoteTemp;

  if (radio.available()) {
    bool done = false;
    while (!done) {
      done = radio.read(&remoteTemp, sizeof(remoteTemp));
    }
    printf("Requested temperature: %d\n", remoteTemp);

    // only process reasonable temperatures
    if (remoteTemp >= 18 && remoteTemp <= 30) {
      desiredTemp = (int) remoteTemp;
      display_number(desiredTemp);
    }

    // Send a confirmation back.
    paquet answer;
    answer.desired_temp     = desiredTemp;
    answer.current_temp     = temp_read().temperature;
    answer.current_humidity = temp_read().humidity;
    radio.stopListening();
    radio.write(&answer, sizeof(answer));
    printf("Sent response.\n");
    radio.startListening();

    delay(10);
  }

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
