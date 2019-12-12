#ifndef TESTS_TESTHELPER_H
#define TESTS_TESTHELPER_H

#include <cstdio>
#include <cstring>

#include <string>

#include "../src/pldeviceartnet.h"
#include "../src/pldeviceenttecpro.h"
#include "../src/pluniverse.h"

class TestHelper
{
public:
    bool connectDevice(int argc, char **argv);
    bool disconnectDevice();

    bool sendDMX(PlanktonLighting::PLUniverse *universe);

private:
    std::string deviceMode;
    PlanktonLighting::PLDeviceEnttecPro *enttecProDevice;
    PlanktonLighting::PLDeviceArtnet *artnetDevice;
};

#endif //TESTS_TESTHELPER_H
