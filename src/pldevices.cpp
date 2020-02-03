//Copyright 2020 PotatoPopcorn (Tony Kerr)

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

#include "pldevices.h"

//Returns every type of device supported by the current library
std::vector<std::string> PlanktonLighting::PLDevices::getSupportedTypes()
{
    std::vector<std::string> types;
    types.push_back("dummy");
    types.push_back("artnet");
    types.push_back("enttecpro");
    types.push_back("opendmx");
    return types;
}

//Returns all devices that are avaliable for use
std::vector<std::string> PlanktonLighting::PLDevices::getAvailableDevices()
{
    std::vector<std::string> devices;

    //Handle enttecpro
    PlanktonLighting::PLEnttecUtilities entUtils;
    int numEntDevs = entUtils.countDevices();
    for(int i = 0; i < numEntDevs; ++i)
    {
        if(entUtils.isProDevice(i))
        {
            std::string deviceIdent = "enttecpro ";
            deviceIdent.append(std::to_string(i));
            devices.push_back(deviceIdent);
        }
        else
        {
            std::string deviceIdent = "ftdi ";
            deviceIdent.append(std::to_string(i));
            devices.push_back(deviceIdent);
        }
    }

    return devices;
}
