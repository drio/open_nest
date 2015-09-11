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

RF24 radio(9,10);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

void setup() {
  //Serial.begin(9600);
  led_init();
  display_init();
  temp_init();
  relay_init();

  Serial.begin(57600);
  printf_begin();
  printf("\nRemote Switch Arduino\n\r");

  radio.begin();
  radio.setRetries(15,15);

  radio.openWritingPipe(pipes[1]);
  radio.openReadingPipe(1,pipes[0]);
  radio.startListening();
  radio.printDetails();
}

void loop() {
  static int wait = 0;

  if (radio.available()) {
    printf("Radio ... %d\n", radio.available());
    unsigned short rawMessage;
    radio.read( &rawMessage, sizeof(unsigned long) );
    printf("Got message %d...",rawMessage);

    //performAction(rawMessage);
    desiredTemp = (int) rawMessage;
    display_number(desiredTemp);

    //send back
    radio.stopListening();
    unsigned short answer = 27;
    radio.write(&answer, sizeof(unsigned short) );
    printf("Sent response.\n\r");
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
