#ifndef drd_led_h
#define drd_led_h

#define PIN_RED        7
#define PIN_GREEN      6
#define PIN_BLUE       5

#define STATUS_AC_ON   0
#define STATUS_HEAT_ON 1
#define STATUS_OFF     2

void led_init();
void led_color(int r, int g, int b);
void led_status(int status);

#endif

