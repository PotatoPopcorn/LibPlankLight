#ifndef PLDEVICEENTTECPRO_H
#define PLDEVICEENTTECPRO_H

#include "pldevice.h"

namespace PlanktonLighting
{
  class PLDeviceEnttecPro : public PLDevice
  {
  public:
    PLDeviceEnttecPro();
    ~PLDeviceEnttecPro();

    bool initDevice(std::string args);
    bool closeDevice();

    bool sendDMX(PlanktonLighting::PLUniverse universe);
    std::string sendMSG(std::string args);
  private:

  };
}

#endif //PLDEVICEENTTECPRO_H
