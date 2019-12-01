# LibPlankLight
This is a library that is designed to make it easier to support multiple lighting devices and formats. Currently only output is supported.

## Currently Supported:
+ Artnet
+ Enttec DMX USB Pro (Untested) [1,2]
+ Enttec DMX USB Pro Mk2 [2]

See notes at the bottom

## Required Libraries
+ Boost (https://www.boost.org/) [3]
+ FTD2xx Drivers (https://www.ftdichip.com/Drivers/D2XX.htm)

Note: Currently only built on Linux.

## Install Instructions
1. Download and install the required prerequisites
2. Download and extract the repository
3. Make the library `make`
4. Install the library `sudo make install`
5. Link to library using `-L/usr/lib/ -lplanklight`
6. OPTIONAL: build tests within the tests folder, using `make`. Tests require library to be installed.

## Included tests
Tests are included in the `tests` folder  

**Full Off**  
Black out the specified device

**Full On**  
White out the specified devices

**Set All**  
Sets all the channels on the specified device to a value

## Known Issues
**LibFTDI Conflict**  
Connecting to EnttecPro will fail if the libftdi driver is running. It can be stopped using the following command:
```
sudo rmmod ftdi_sio
sudo rmmod usbserial
```

**Ubuntu Boost Incompatibility**  
When installing, please make sure that your version of boost is later than 1.68, at time of writing the Ubuntu repositories use version 1.65 which will not work since there are changes with the `asio` library.  
The latest version of boost can be downloaded from [the boost website](https://www.boost.org/).

## Notes
[1]: Tested with Mk2, should work with Mk1 but hasn't been tested. Trying to initialise port 2 on Mk1 may fail,  
[2]: MIDI not supported.  
[3]: Must be at least version 1.68 (requires `io_context` to be in `boost_asio`),  
