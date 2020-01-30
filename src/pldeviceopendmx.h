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

#ifndef PLDEVICEOPENDMX_H
#define PLDEVICEOPENDMX_H

#include <string>

#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include <boost/algorithm/string.hpp>

#include "ftd2xx.h"

#include "pldevice.h"
#include "pluniverse.h"

namespace PlanktonLighting
{
    class PLDeviceOpenDMX : public PLDevice{
    public:
        PLDeviceOpenDMX();
        ~PLDeviceOpenDMX();

        bool initDevice(std::string args);
        bool closeDevice();

        bool sendDMX(PlanktonLighting::PLUniverse *universe);
        bool sendDMX(PlanktonLighting::PLUniverse *universe, std::string args);
        std::string sendMSG(std::string args);

    private:
        int devNum = 0;
        int frequency = 25;
        unsigned int packetsSent = 0;
        bool mainLoopAlive;
        char uni[513];

        FT_HANDLE handle;

        boost::thread_group m_tgroup;
        boost::mutex updateDMXMutex;

        bool processArgs(std::string args);
        void keepAlive();
    };
}

#endif //PLDEVICEOPENDMX_H
