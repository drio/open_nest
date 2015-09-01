This weekend and started prototyping the first version of the thermostat.

Everything went smoothly with the exception of the development part. I wanted
to build some abstractions for the different components of the system, starting
by separating my code and vendor's code. Something like
[this](http://arduino.stackexchange.com/a/579).

Unfortunately I run into fundamental issues when trying to move vendor's
libraries from the main project directory. What is worse, the only way I could
successfully use the library that abstracts the interactions with the backpacks
(displays) was by instantiating an object in the global space. That was very
annoying. Any attempt to move away from that was a failure. I couldn't even
instantiate within a function without getting compilation errors.

I will eventually move away from the Arduino IDE and run things from the
command line.  I am coding in vim and running the arduino IDE fromt here using
[this](http://usevim.com/2015/05/25/hardy/) plugin.

The other complication was computing the current temperature from the
thermometer output.  The voltage values are reasonable but the statements to
compute the Celsius temperature end up generating very different values for
small voltage value changes. I have to investigate further. Also, I am going to
receive soon a more powerful
[thermometer](https://www.adafruit.com/products/1899) with humidity support on
it.

-drd
