#include "pldevices.h"

//Returns every type of device supported by the current library
std::vector<std::string> PlanktonLighting::PLDevices::getSupportedTypes()
{
    std::vector<std::string> types;
    types.push_back("dummy");
    types.push_back("artnet");
    types.push_back("enttecpro");
    return types;
}

//Returns all devices that are avaliable for use
std::vector<std::string> PlanktonLighting::PLDevices::getAvailableDevices()
{
    std::vector<std::string> devices;

    //Handle enttecpro
    PlanktonLighting::PLEnttecUtilities entUtils;
    int numEntDevs = entUtils.countDevices();
    for(int i = 0; i < numEntDevs; ++i)
    {
        std::string deviceIdent = "enttecpro ";
        deviceIdent.append(std::to_string(i));
        devices.push_back(deviceIdent);
    }

    return devices;
}
