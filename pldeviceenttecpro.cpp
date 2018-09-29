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
  sendData(6, dmxBuffer, 513);
  return true;

}

std::string PlanktonLighting::PLDeviceEnttecPro::sendMSG(std::string args)
{
  return "";
}

//Adapted from ENTTEC Sample Code
int PlanktonLighting::PLDeviceEnttecPro::sendData(int label, unsigned char *data, int length)
{
  unsigned char startCode =0x7E;
  unsigned char endCode = 0xE7;
  DWORD bytes_written = 0;

  FT_STATUS status;

  unsigned char header[4];
  header[0] = startCode;
  header[1] = label;
  header[2] = length & 0xFF;
	header[3] = length >> 8;
  status = FT_Write(handle,(unsigned char *)header,4,&bytes_written);
  status = FT_Write(handle,(unsigned char *)data,length,&bytes_written);
  status = FT_Write(handle,(unsigned char *)&endCode,1,&bytes_written);
  FT_Purge (handle,FT_PURGE_TX);
	FT_Purge (handle,FT_PURGE_RX);
  if(status == FT_OK)
  {
    return 0;
  }
  else
  {
    printf("ERROR: %i\n", status);
    return 1;
  }
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
  sendData(13, myKey, 4);
  boost::this_thread::sleep(boost::posix_time::milliseconds(200));
  sendData(147, portSet, 2);

  return true;
}
