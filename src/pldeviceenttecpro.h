//Copyright 2019 PotatoPopcorn (Tony Kerr)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// See LICENCE

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
