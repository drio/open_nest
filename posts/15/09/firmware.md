Over the weekend I polished the firmware in the arduino and the piece of software
that communicates with the arduino to send a struct that contains the status of
the thermostat. So from the rpi I can do:

```
$ remote -t 22
{
 desired: 22,
 current: 30,
 humidity: 55
}
```

or

```
$ remote -t 0
{
 desired: 0,
 current: 30,
 humidity: 55
}
```

To get an status but to not set the temperature.

After that, I have setup the node.js server that will run in the rpi and will serve
the little web app which we will use to control and check the status of the thermostat.
It uses socket.io and receives temp messages from the client. It then spawns a fork of
remote and sends the json back to the client.

In the client side I have to add the events to the +/- elements in the view so we send
a socket io message to the server.

Almost there for the full first version of the prototype.

Code here: https://github.com/drio/open_nest/tree/master/src


