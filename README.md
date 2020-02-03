# LibPlankLight
This is a library that is designed to make it easier to support multiple lighting devices and formats. Currently only output is supported.

## Currently Supported
+ Artnet
+ Enttec DMX USB Pro Mk2 [1, 2]
+ Enttec OpenDMX USB   

See notes at the bottom

### Coming Soon
+ sACN / E1.31

## Required Libraries and Tools
+ CMake (https://cmake.org/)
+ Boost (https://www.boost.org/) [3, 4]
+ FTD2xx Drivers (https://www.ftdichip.com/Drivers/D2XX.htm) [5]

Note: Currently only built on Linux, it should work on Windows if boost can be found (I will add instructions soon). No clue about MacOS.

## Install Instructions
### Linux
1. Download and install the required prerequisites
2. Download and extract the repository
3. Open in CMake and Configure, fixing any issues that appear
4. Generate the CMake files
5. Find navigate to where the CMake files were generated
3. Make the library using `make`
4. Install the library using `sudo make install`
5. Link to library using `-L/path/from/cmake/lib -lplanklight`
6. OPTIONAL: build tests within the tests folder, using `make`. Tests require library to be installed.

## Included tests
Tests are included in the `tests` folder. Tests can be run using the device name (`enttecpro`, `opendmx`, `artnet`, or `dummy`) and the relevant init variables which are shown in the wiki.  
e.g. `test-[name] enttecpro 0 1`

**Devices**  
Used to test the devices class and see what is connected.

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

## Licence
This project is released under the GNU LGPL v3. The full licence is available in LICENCE. The tests are an exception to this and can be used under the licence at the top of the file.

## Notes
[1]: Mk 1 may work with the code, it has never been tested and the results may not be stable  
[2]: MIDI not supported.  
[3]: Must be at least version 1.68 (requires `io_context` to be in `boost_asio`),  
[4]: The library uses `-lboost_thread -lboost_system -lboost_chrono`   
[5]: You will need `ftd2xx.h` and `WinTypes.h` from the FTD2xx drivers to be included
