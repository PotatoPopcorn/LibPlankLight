// Copyright (C) 2019 by PotatoPopcorn (Tony Kerr)
//

// NOTE: Only the tests are subject to the following licence, The main source
// code is licenced under the GNU LGPL, plese see the README for more
// information

// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
// OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include "testhelper.h"

bool TestHelper::connectDevice(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("TestWarn: Too few arguments\n");
        return false;
    }

    if(!strcmp(argv[1], "enttecpro"))
    {
        if(argc < 4)
        {
            printf("TestWarn: Too few arguments for Enttec Pro\n");
            return false;
        }
        deviceMode = "enttecpro";
        enttecProDevice = new PlanktonLighting::PLDeviceEnttecPro();
        std::string args = "";
        args.append(argv[2]);
        args.append(" ");
        args.append(argv[3]);
        enttecProDevice->initDevice(args);
        return true;
    }
    else if (!strcmp(argv[1], "artnet"))
    {
        printf("Launching Artnet\n");
        deviceMode = "artnet";
        artnetDevice = new PlanktonLighting::PLDeviceArtnet;
        std::string args = argv[2];
        for(int i = 0; i < 5; ++i)
        {
            args.append(" ");
            args.append(argv[3 + i]);
        }
        artnetDevice->initDevice(args);
        return true;
    }
    else if (!strcmp(argv[1], "opendmx"))
    {
        printf("LaunchingOpenDMX\n");
        deviceMode = "opendmx";
        opendmxDevice = new PlanktonLighting::PLDeviceOpenDMX;
        std::string args = "";
        args.append(argv[2]);
        args.append(" ");
        args.append(argv[3]);
        opendmxDevice->initDevice(args);
        return true;
    }
    else if (!strcmp(argv[1], "dummy"))
    {
        printf("Launching Dummy\n");
        deviceMode = "dummy";
        return true;
    }
    else
    {
        printf("TestWarn: Invalid Device\n");
        return false;
    }
}

bool TestHelper::disconnectDevice()
{
    printf("Device Was %s\n", deviceMode.c_str());
    if(deviceMode == "dummy")
    {
        return true;
    }
    else if(deviceMode == "enttecpro")
    {
        enttecProDevice->closeDevice();
        return true;
    }
    else if(deviceMode == "artnet")
    {
        artnetDevice->closeDevice();
        return true;
    }
    else if(deviceMode == "opendmx")
    {
        opendmxDevice->closeDevice();
    }
    return false;
}

bool TestHelper::sendDMX(PlanktonLighting::PLUniverse *universe)
{
    if(deviceMode == "dummy")
    {
        return true;
    }
    else if(deviceMode == "enttecpro")
    {
        return enttecProDevice->sendDMX(universe);
    }
    else if(deviceMode == "artnet")
    {
        return artnetDevice->sendDMX(universe);
    }
    else if(deviceMode == "opendmx")
    {
        return opendmxDevice->sendDMX(universe);
    }
    return false;
}
