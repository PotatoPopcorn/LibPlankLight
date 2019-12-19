//Copyright 2019 PotatoPopcorn (Tony Kerr)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// See LICENCE

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
