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

/*

IMPORTANT: This class should never be used as an output device, it exists only to be overridden by other devices
*/

#include "pldevice.h"

//Empty constructor and destructor
PlanktonLighting::PLDevice::PLDevice()
{

}

PlanktonLighting::PLDevice::~PLDevice()
{

}

//Generic function for stating the device
bool PlanktonLighting::PLDevice::initDevice(std::string args)
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

//Generic function for stopping the device
bool PlanktonLighting::PLDevice::closeDevice()
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

//Generic function for sending DMX to the device
bool PlanktonLighting::PLDevice::sendDMX(PlanktonLighting::PLUniverse *universe)
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

//Generic function for sending DMX to the device
bool PlanktonLighting::PLDevice::sendDMX(PlanktonLighting::PLUniverse *universe,
        std::string args)
{
  return sendDMX(universe);
}

//Generic function for sending control messages to the device
std::string PlanktonLighting::PLDevice::sendMSG(std::string args)
{
  printf("Warn: PLDevice does not exist\n");
  return "";
}
