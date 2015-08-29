#include <Arduino.h>
#include "Test.h"
#include "HardwareSerial.h"

Test::Test(int givenValue)
{
  // initialize this instance's variables
  value = givenValue;

  // do whatever is required to initialize the library
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void Test::doSomething(void)
{
  Serial.print("value is ");
  Serial.println(value);

  doSomethingSecret();
}

void Test::doSomethingSecret(void)
{
  digitalWrite(13, HIGH);
  delay(200);
  digitalWrite(13, LOW);
  delay(200);
}

