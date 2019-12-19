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

#ifndef PLDEVICES_H
#define PLDEVICES_H

#include <string>
#include <vector>

#include "plenttecutilities.h"

namespace PlanktonLighting{
  class PLDevices{
  public:
      std::vector<std::string> getSupportedTypes();
      std::vector<std::string> getAvailableDevices();
  };
}

#endif //PLDEVICES_H
