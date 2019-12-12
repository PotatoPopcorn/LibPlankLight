#ifndef PLDEVICEENTTECPRO_H
#define PLDEVICEENTTECPRO_H

#include <cstring>
#include <sstream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/thread/thread.hpp>

#include "ftd2xx.h"

#include "pldevice.h"
#include "plenttecutilities.h"

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

    int devNum = 0;
    int outputUniverse = 1;

    FT_HANDLE handle;

    PlanktonLighting::PLEnttecUtilities utils;

    bool processArgs(std::string args);

  };
}

#endif //PLDEVICEENTTECPRO_H
