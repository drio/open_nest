#!/bin/bash

name=$1

if [ ".$name" == "." ];then
  echo "Need class name"
  exit 1
fi

echo "\
#include <Arduino.h>
// other includes here

$name::$name(void)
{

}

void $name::doSomething(void)
{

}

void $name::doSomethingSecret(void)
{

}
" > ${name}.cpp

echo "\
#ifndef ${name}_h
#define ${name}_h

#include <Wire.h>

class $name
{
  public:
    $name();
    void doSomething(void);

  private:
    int value;
    void doSomethingSecret(void);
};

#endif
" > ${name}.h
