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

#include "pldeviceenttecpro.h"

//Empty constructor
PlanktonLighting::PLDeviceEnttecPro::PLDeviceEnttecPro()
{

}

//Empty destructor
PlanktonLighting::PLDeviceEnttecPro::~PLDeviceEnttecPro()
{

}

//Start Enttec Device using plenttecutilities
bool PlanktonLighting::PLDeviceEnttecPro::initDevice(std::string args)
{
  if(!processArgs(args))
  {
    return false;
  }
  if(!utils.initPro(devNum, handle, readTimeout, writeTimeout, rxBufferSize, txBufferSize))
  {
    return false;
  }

  if(outputUniverse == 2)
  {
    return utils.startUni2(handle);
  }
  return true;
}

//Stop Enttec Device using plenttecutilities
bool PlanktonLighting::PLDeviceEnttecPro::closeDevice()
{
  return utils.closePro(handle);
}

//Send DMX to Enttec Device using plenttecutilities
bool PlanktonLighting::PLDeviceEnttecPro::sendDMX(PlanktonLighting::PLUniverse *universe)
{
  unsigned char dmxBuffer[513];
  memset(dmxBuffer,0,sizeof(dmxBuffer));
  for(int i = 1; i < 513; i++)
  {
    dmxBuffer[i] = universe->getChan(i);
  }
  if(outputUniverse == 1)
  {
    utils.sendData(6, dmxBuffer, 513, handle);
  }
  else if (outputUniverse == 2)
  {
    utils.sendData(202, dmxBuffer, 513, handle);
  }
  else
  {
    printf("OutputUniverse misconfigured\n");
  }
  return true;

}

// Ignored, might be implemented later
std::string PlanktonLighting::PLDeviceEnttecPro::sendMSG(std::string args)
{
  return "";
}

// Processes arguments that are parsed to the initdevice
// [Device Number] [Universe Number (1/2)]
bool PlanktonLighting::PLDeviceEnttecPro::processArgs(std::string args)
{
  //Turn args into a vector and check all required have been parsed
  std::vector<std::string> argVec;
  boost::split(argVec, args, boost::is_any_of(" "), boost::token_compress_on );
  if(argVec.size() != 2)
  {
    printf("Incorrect number of arguments sent to Enttec Pro\n");
    return false;
  }

  //Parse the device number
  devNum = atoi(argVec[0].c_str());

  //Parse outputUniverse
  if(argVec[1] == "1"){
    outputUniverse = 1;
  }
  else if (argVec[1] == "2")
  {
    outputUniverse = 2;
  }
  else
  {
    printf("Invalid arguments sent to Enttec Pro: Invalid Universe\n");
    return false;
  }
  return true;
}
