#ifndef drd_led_h
#define drd_led_h

#define PIN_RED        7
#define PIN_GREEN      6
#define PIN_BLUE       5

#define STATUS_AC_ON   0
#define STATUS_HEAT_ON 1
#define STATUS_OFF     2

#define COLOR_BLUE   0,0,255
#define COLOR_ORANGE 255,165,0
#define COLOR_GREEN  0,255,0

void led_init();
void led_color(int r, int g, int b);
void led_blue();
void led_orange();
void led_green();
void led_off();

void led_status(int status);

#endif

