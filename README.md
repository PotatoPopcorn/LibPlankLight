# LibPlankLight
This is a library that is designed to make it easier to support multiple lighting devices and formats. Currently only output is supported.

## Currently Supported:
+ Enttec DMX USB Pro (Untested) [1,2]
+ Enttec DMX USB Pro Mk2 [2]

See notes at the bottom

## Required Libraries
+ Boost (https://www.boost.org/)
+ FTD2xx Drivers (https://www.ftdichip.com/Drivers/D2XX.htm)

Note: Currently only built on Linux.

## Install Instructions
1. Download and install the required prerequisites
2. Download and extract the repository
3. Make the library `sudo make shared`
4. Link to library using `-L/usr/lib/ -lplanklight`
5. OPTIONAL: build tests

## Included tests
**EnttecOff:**  
Sets all channels on universe 1 to zero

**EnttecOcean:**  
Uses the EnttecPro Device and generates a 255 on channels 3 and 9 while 2 and 8 are random, generating a ocean like effect.

**EnttecLoading:**  
Uses the EnttecPro device to switch between channels 1, 2 and 3 while 4 is faded on and off.

## Known Issues
**LibFTDI Conflict**  
Connecting to EnttecPro will fail if the libftdi driver is running. It can be stopped using the following command:
```
sudo rmmod ftdi_sio
sudo rmmod usbserial
```

## Notes
[1]: Tested with Mk2, should work with Mk1 but hasn't been tested. Trying to initialise port 2 on Mk1 may fail,  
[2]: MIDI not supported.
