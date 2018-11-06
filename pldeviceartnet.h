#ifndef PLDEVICEARTNET_H
#define PLDEVICEARTNET_H

#include <string>

#include "pldevice.h"

namespace PlanktonLighting
{
  class PLDeviceArtnet : public PLDevice
  {
  public:
    PLDeviceArtnet();
    ~PLDeviceArtnet();

    bool initDevice(std::string args);
    bool closeDevice();

    bool sendDMX(PlanktonLighting::PLUniverse *universe);
    std::string sendMSG(std::string args);
  private:
    bool processArgs(std::string args);
  };
}

#endif //PLDEVICEARTNET_H
