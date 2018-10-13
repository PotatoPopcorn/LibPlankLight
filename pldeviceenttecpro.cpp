#include "pldeviceenttecpro.h"

PlanktonLighting::PLDeviceEnttecPro::PLDeviceEnttecPro()
{

}
PlanktonLighting::PLDeviceEnttecPro::~PLDeviceEnttecPro()
{

}

//Adapted from ENTTEC Sample Code
bool PlanktonLighting::PLDeviceEnttecPro::initDevice(std::string args)
{
  if(!processArgs(args))
  {
    return false;
  }
  FT_STATUS status;
  status = FT_Open(0, &handle);
  if(status == FT_OK)
  {
    FT_SetTimeouts(&handle,readTimeout,writeTimeout);
		FT_SetUSBParameters(&handle,rxBufferSize,txBufferSize);
    FT_Purge (&handle,FT_PURGE_RX);
    if(outputUniverse == 2)
    {
      if(!startUni2())
      {
        printf("Failed to start second universe \n");
        return false;
      }
    }
    return true;
  }
  else
  {
    printf("Error Connecting to ENTTEC DMX Pro. FTDI Error: %i\n", status);
    return false;
  }
}

//Adapted from ENTTEC Sample Code
bool PlanktonLighting::PLDeviceEnttecPro::closeDevice()
{
  if(handle != NULL)
  {
    FT_Close(&handle);
    return true;
  }
  return false;
}


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

std::string PlanktonLighting::PLDeviceEnttecPro::sendMSG(std::string args)
{
  return "";
}


// [Device Number] [Universe Number (1/2)]
bool PlanktonLighting::PLDeviceEnttecPro::processArgs(std::string args)
{
  //Turn args into a vector and check all required have been parsed
  std::vector<std::string> argVec;
  boost::split(argVec, args, boost::is_any_of(" "), boost::token_compress_on );
  if(argVec.size() < 2)
  {
    printf("Too few arguments sent to Enttec Pro\n");
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

bool PlanktonLighting::PLDeviceEnttecPro::startUni2()
{
  unsigned char apiKey[] = {0xC9, 0xA4, 0x03, 0xE4};
  unsigned char* myKey = apiKey;
  uint8_t portSet[] = {1,1};
  unsigned int res = 0;
  FT_Purge (handle,FT_PURGE_TX);
	FT_Purge (handle,FT_PURGE_RX);
  utils.sendData(13, myKey, 4, handle);
  boost::this_thread::sleep(boost::posix_time::milliseconds(200));
  utils.sendData(147, portSet, 2, handle);

  return true;
}
