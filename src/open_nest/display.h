#ifndef drd_display_h
#define drd_display_h

#include <Adafruit_LEDBackpack.h>
#include <Adafruit_GFX.h>

typedef struct {
  Adafruit_8x8matrix low;
  Adafruit_8x8matrix high;
} matrix_display;

void display_init();
void display_number(char *number);
void display_single(Adafruit_8x8matrix m, char digit);

#endif
