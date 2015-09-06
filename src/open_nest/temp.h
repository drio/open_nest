#ifndef drd_temp_h
#define drd_temp_h

typedef struct {
  float temperature;
  float humidity;
} termomether;

termomether temp_read();
void temp_init();

#endif


