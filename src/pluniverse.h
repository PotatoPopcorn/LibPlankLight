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

#ifndef PLUNIVERSE_H
#define PLUNIVERSE_H

#include <cstdio>

namespace PlanktonLighting{
  //Creates a universe structure that can be used to send data to devices
  class PLUniverse{
  public:
    PLUniverse();
    ~PLUniverse();

    int getChan(int chanNum);
    void setChan(int chanNum, int value);

    void blackout();
    void whiteout();
    void setAll(int value);

  private:
    int channels[512];
  };
}

#endif //PLUNIVERSE_H
