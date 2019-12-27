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

#ifndef PLDEVICE_H
#define PLDEVICE_H

#include <cstdio>
#include <string>

#include "pluniverse.h"

namespace PlanktonLighting{
  class PLDevice{
  public:
    PLDevice();
    ~PLDevice();

    virtual bool initDevice(std::string args);
    virtual bool closeDevice();

    virtual bool sendDMX(PlanktonLighting::PLUniverse *universe);
    virtual bool sendDMX(PlanktonLighting::PLUniverse *universe,
            std::string args);
    virtual std::string sendMSG(std::string args);
  };
}

#endif //PLDEVICE_H
