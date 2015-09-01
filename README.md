Foo: bar
---
### Open Nest

This project tries to replicate most of the [nest](www.nest.com) functionality
using [arduino](https://www.arduino.cc) hardware.

The hardware I am using for the prototyping is:

- arduino uno board
- breadboard
- adafruit's backpack [matrix](https://www.adafruit.com/products/872)
- potentiometer
- rgb led
- resistors
- thermometer
- ???

The questions marks are for the hardware I will use to communicate remotely with the
device. Currently I am exploring two options:

- Adafruit's [CC3000](https://www.adafruit.com/products/1469)
- nRF24L01+ 2.4GHz Wireless [Transceiver](http://www.amazon.com/nRF24L01-Wireless-Transceiver-Arduino-Compatible/dp/B00E594ZX0/ref=sr_1_1?ie=UTF8&qid=1441073822&sr=8-1&keywords=arduino+wireless)

The first one provides full wifi capabilities while the second one is much more
limited. I will expand on that on the posts sections as I work more with them.

I am inclined to go for the nRF24L01. The CC3000 is overkill considering we just
want to send small bits of data back and forth between our open nest and a server.
This server can be a Rasberry PI. But most importantly, the nRF24L01 chips are
cheap. If you want to start adding more of this devices around your home, things
can start getting pretty expensive. Also, there is the concern of power consumption.
We want our nest to run for months on a couple of AAA batteries.

### Questions and Feedback

I'd love to get feedback and help people to implement their own version of this. Please
open a ticket if you want to start any discussion.

### TODO

Misc:
  - [ ] Add schematics
Standalone mode:
  - [ ] Solve the thermometer readings issue
  - [ ] Implement the main logic that triggers AC/Head on and off.
Remote mode:
  - [ ] do basic testing of the nRF24L01. Does it serve well for our purpose
  - [ ] write webapp that will run in the PI to receive data and control the device

Build a more compact solution:
  - [ ] Prototype migration to arduino uno
  - [ ] Add batteries and calculate expected battery life.
  - [ ] Explore case [options](http://blog.particle.io/2014/01/17/open-source-thermostat/).
