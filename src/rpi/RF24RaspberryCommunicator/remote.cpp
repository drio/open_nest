#include <string>
#include <getopt.h>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <RF24/RF24.h>

using namespace std;

RF24 radio(RPI_V2_GPIO_P1_22, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);
const uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };

// This models what we will recieve from the arduino
typedef struct{
  int16_t desired_temp;
  int16_t current_temp;
  int16_t current_humidity;
} paquet;

// https://github.com/TMRh20/RF24/issues/46
paquet answer;

void setup(void){
	//Prepare the radio module
	printf("\nPreparing interface\n");
	radio.begin();
	radio.setRetries(15, 15);

	radio.printDetails();
	radio.openWritingPipe(pipes[0]);
	radio.openReadingPipe(1, pipes[1]);
}

bool sendMessage(unsigned int temperature){
	radio.stopListening();
  unsigned long copyTemp = temperature;

	printf("Now sending temperature: %lu\n", copyTemp);
	bool ok = radio.write(&copyTemp, sizeof(unsigned long));
	if (ok) {
		printf("ok.\n");
	}
  else {
		printf(":( failed.\n");
	}

	radio.startListening();
	unsigned long start = millis();
	bool timeout = false;
	while (!radio.available() && !timeout) {
		if (millis() - start > 1000 )
			timeout = true;
	}

	if (timeout) {
		printf("Timeout waiting for response.\n");
		return false;
	}
  else {
    radio.read(&answer, sizeof(answer));
		printf("{");
		printf("\"desired\": %d,", answer.desired_temp);
		printf("\"current\": %d,", answer.current_temp);
		printf("\"humidity\": %d", answer.current_humidity);
		printf("}\n");
		return true;
	}
}

int main(int argc, char **argv) {
  unsigned int temperature;
	bool switched = false;
	int counter = 0;

  getopt(argc, argv, "t:");
  temperature = atoi(optarg);
  if (temperature < 0 || temperature > 30) {
    printf("Usage: ./remote -t <temp>\n");
    printf("temp has to be an integer between 0 and 30.\n");
    return 1;
  }

	setup();
  printf("Sending request to set temperature to: %d\n", temperature);
  while(switched == false && counter < 1) {
    switched = sendMessage(atoi(optarg));
    counter++;
    //sleep(1);
  }

  if (counter < 5) {
    return 0;
  }
  else {
    return 1;
  }
}
