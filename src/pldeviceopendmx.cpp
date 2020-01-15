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
    memset(uni, 0, 513);
    // TODO Create Thread
    mainLoopAlive = true;
  	m_tgroup.create_thread(boost::bind(&PlanktonLighting::PLDeviceOpenDMX::keepAlive, this));

}

bool PlanktonLighting::PLDeviceOpenDMX::closeDevice()
{
    mainLoopAlive = false;
  	m_tgroup.join_all();
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

bool PlanktonLighting::PLDeviceOpenDMX::sendDMX(PlanktonLighting::PLUniverse *universe)
{
    updateDMXMutex.lock();
    for(int i = 1; i <= 512; i++)
    {
        uni[i] = universe->getChan(i);
    }
    updateDMXMutex.unlock();
    return true;
}

bool PlanktonLighting::PLDeviceOpenDMX::sendDMX(PlanktonLighting::PLUniverse *universe, std::string args)
{
    sendDMX(universe);
}

std::string PlanktonLighting::PLDeviceOpenDMX::sendMSG(std::string args)
{
    return "";
}

bool PlanktonLighting::PLDeviceOpenDMX::processArgs(std::string args)
{

}

void PlanktonLighting::PLDeviceOpenDMX::keepAlive()
{
    FT_STATUS status;
    while(mainLoopAlive)
    {
        updateDMXMutex.lock();
        status = FT_SetBreakOn(handle);
        status = FT_SetBreakOff(handle);
        status = FT_Write(handle, uni, 513, &packetsSent);
        updateDMXMutex.unlock();
    }
    boost::this_thread::sleep_for(boost::chrono::milliseconds(1000/frequency));

}
