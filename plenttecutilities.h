#ifndef PLENTTECUTILITIES_H
#define PLENTTECUTILITIES_H

#include <string>

#include "ftd2xx.h"

namespace PlanktonLighting
{
  class PLEnttecUtilities
  {
  public:
    PLEnttecUtilities();
    ~PLEnttecUtilities();

    int countDevices();
    bool isProDevice(int devNum);
    int getProVersionNum(int devNum);
  };
}

#endif //PLENTTECUTILITIES_H
