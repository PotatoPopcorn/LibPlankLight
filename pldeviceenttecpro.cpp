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
  FT_STATUS status;
  status = FT_Open(0, &handle);
  if(status == FT_OK)
  {
    FT_SetTimeouts(&handle,readTimeout,writeTimeout);
		FT_SetUSBParameters(&handle,rxBufferSize,txBufferSize);
    FT_Purge (&handle,FT_PURGE_RX);
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
}

std::string PlanktonLighting::PLDeviceEnttecPro::sendMSG(std::string args)
{

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
