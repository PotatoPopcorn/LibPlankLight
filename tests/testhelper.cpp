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
    return false;
}
