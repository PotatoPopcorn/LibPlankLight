#ifndef PLENTTECUTILITIES_H
#define PLENTTECUTILITIES_H

#include <cstdio>
#include <cstring>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/thread/thread.hpp>

#include "ftd2xx.h"

namespace PlanktonLighting
{
  class PLEnttecUtilities
  {
  public:
    PLEnttecUtilities();
    ~PLEnttecUtilities();

    static int sendData(int label, unsigned char *data, int length, FT_HANDLE &handle);
    static int recieveData(int label, unsigned char *data, int length, FT_HANDLE &handle);

    static bool initPro(int devNum, FT_HANDLE &handle, int readTimeout, int writeTimeout, DWORD rxBufferSize, DWORD txBufferSize);
    static bool startUni2(FT_HANDLE &handle);
    static bool closePro(FT_HANDLE &handle);

    static int countDevices();
    static bool isProDevice(int devNum);
    static int getProVersionNum(int devNum);
  };
}

#endif //PLENTTECUTILITIES_H
