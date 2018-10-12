#ifndef PLENTTECUTILITIES_H
#define PLENTTECUTILITIES_H

#include <cstdio>
#include <cstring>
#include <string>

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

    static int countDevices();
    static bool isProDevice(int devNum);
    static int getProVersionNum(int devNum);
  };
}

#endif //PLENTTECUTILITIES_H
