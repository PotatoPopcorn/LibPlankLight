#include "pldevices.h"

std::vector<std::string> PlanktonLighting::PLDevices::getSupportedTypes()
{
    std::vector<std::string> types;
    types.push_back("dummy");
    types.push_back("artnet");
    types.push_back("enttecpro");
    return types;
}

std::vector<std::string> PlanktonLighting::PLDevices::getAvailableDevices()
{
    std::vector<std::string> devices;
    
    return devices;
}
