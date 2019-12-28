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

#include "pldeviceopendmx.h"

//Empty constructor
PlanktonLighting::PLDeviceOpenDMX::PLDeviceOpenDMX()
{

}

//Empty destructor
PlanktonLighting::PLDeviceOpenDMX::~PLDeviceOpenDMX()
{

}

bool PlanktonLighting::PLDeviceOpenDMX::initDevice(std::string args)
{
    if(!processArgs(args))
    {
      return false;
    }
    FT_STATUS status;
    status = FT_Open(devNum, &handle);
    if(status != FT_OK)
    {
        printf("Error opening OpenDMX device, FTDI Error: %u\n", status);
        return false;
    }
    status = FT_SetBaudRate(handle, 250000);
    status = FT_SetDataCharacteristics(handle, FT_BITS_8, FT_STOP_BITS_2,
            FT_PARITY_NONE);
    status = FT_Purge (handle, FT_PURGE_RX | FT_PURGE_TX);
    status = FT_ClrRts(handle);
    // TODO Create Thread
}

bool PlanktonLighting::PLDeviceOpenDMX::closeDevice()
{
    // TODO: Kill Thread
    if(handle != NULL)
    {
      FT_STATUS status;
      status = FT_Close(handle);
      if(status == FT_OK)
      {
        return true;
      }
      else
      {
        printf("Error Disconnecting From OpenDMX. FTDI Error: %i\n", status);
        return false;
      }
    }
    return false;
}

bool PlanktonLighting::PLDeviceOpenDMX::sendDMX(PlanktonLighting::PLUniverse *uni)
{

}

bool PlanktonLighting::PLDeviceOpenDMX::sendDMX(PlanktonLighting::PLUniverse *uni, std::string args)
{
    sendDMX(uni);
}

std::string PlanktonLighting::PLDeviceOpenDMX::sendMSG(std::string args)
{
    return "";
}

bool PlanktonLighting::PLDeviceOpenDMX::processArgs(std::string args)
{

}
