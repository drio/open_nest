- client:
  - io messages
    + get temp
    + set temp

- server:
  - process messages:
    + temp: swap process, get results and return it to client (maybe cache)
    + temp(number): swap process, set temp and return status to client.
    NOTE:

Action items:

- modify remote so it dumps json
- implement temp in server. When there is number, pass it, if not set it to 0 to indicate
  you want to get a current temperature status.
  We will spawn a remote process and capture its output.

- in the client app, when loading, send a status request and create a module based
  on the curren temp.
- when clicking in +/-, send a io message to set temp. Ampersand will update the
  view once we get the data back from the server.
