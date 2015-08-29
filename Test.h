#ifndef Test_h
#define Test_h

#include <Wire.h>

// library interface description
class Test
{
  public:
    Test(int);
    void doSomething(void);

  private:
    int value;
    void doSomethingSecret(void);
};

#endif

