#ifndef PLDEVICEENTTECPRO_H
#define PLDEVICEENTTECPRO_H

#include <string.h>

#include "ftd2xx.h"

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

    bool sendDMX(PlanktonLighting::PLUniverse *universe);
    std::string sendMSG(std::string args);
  private:
    //Settings:
    int readTimeout = 120;
    int writeTimeout = 100;
    DWORD rxBufferSize = 40960;
    DWORD txBufferSize = 40960;

    FT_HANDLE handle;

    int sendData(int label, unsigned char *data, int length);

  };
}

#endif //PLDEVICEENTTECPRO_H
