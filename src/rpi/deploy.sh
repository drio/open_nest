#!/bin/bash
PI_DIR="/home/pi/open_nest"
RF24_REPO="https://github.com/TMRh20/RF24.git"

cd RF24RaspberryCommunicator
[ ! -d RF24 ] && git clone $RF24_REPO
echo "Compiling"
g++ -Ofast -mfpu=vfp  \
  -mfloat-abi=hard -march=armv6zk \
  -mtune=arm1176jzf-s -Wall \
  -I./RF24/RPi/RF24/ \
  -lrf24-bcm remote.cpp -o remote
ls -lacd remote
