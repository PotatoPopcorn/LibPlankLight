#include "pldeviceenttecpro.h"

PlanktonLighting::PLDeviceEnttecPro::PLDeviceEnttecPro()
{

}
PlanktonLighting::PLDeviceEnttecPro::~PLDeviceEnttecPro()
{

}

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

bool PlanktonLighting::PLDeviceEnttecPro::closeDevice()
{
  if(handle != NULL)
  {
    FT_Close(&handle);
    return true;
  }
  return false;
}

bool PlanktonLighting::PLDeviceEnttecPro::sendDMX(PlanktonLighting::PLUniverse universe)
{

}

std::string PlanktonLighting::PLDeviceEnttecPro::sendMSG(std::string args)
{

}
