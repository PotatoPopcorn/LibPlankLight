#include "plenttecutilities.h"

PlanktonLighting::PLEnttecUtilities::PLEnttecUtilities()
{

}

PlanktonLighting::PLEnttecUtilities::~PLEnttecUtilities()
{

}

int PlanktonLighting::PLEnttecUtilities::sendData(
  int label, unsigned char *data, int length, FT_HANDLE &handle)
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
int PlanktonLighting::PLEnttecUtilities::recieveData(
  int label, unsigned char *data, int exLength, FT_HANDLE &handle)
{
  unsigned char startCode =0x7E;
  unsigned char endCode = 0xE7;

  FT_STATUS status;
  unsigned char byte = 0;
  DWORD length = 0;
  DWORD bytes_read = 0;
  char buffer[600];

  while(byte != label)
  {
    while(byte != startCode)
    {
      status = FT_Read(handle, (unsigned char *) &byte, 1, &bytes_read);
      if(bytes_read == 0)
      {
        return 1;
      }
    }
    status = FT_Read(handle, (unsigned char *) &byte, 1, &bytes_read);
    if(bytes_read == 0)
    {
      return 1;
    }
  }
  status = FT_Read(handle, (unsigned char *) &byte, 1, &bytes_read);
  if(bytes_read == 0)
  {
    return 1;
  }
  length = byte;
  status = FT_Read(handle, (unsigned char *) &byte, 1, &bytes_read);
  if(bytes_read == 0)
  {
    return 1;
  }
  length +=((uint32_t)byte) << 8;
  if(length > 600)
  {
    return 2;
  }
  status = FT_Read(handle, buffer, length, &bytes_read);
  if(bytes_read != length)
  {
    return 3;
  }
  status = FT_Read(handle, (unsigned char *)&byte,1,&bytes_read);
  if(bytes_read == 0 || byte != endCode)
  {
    return 4;
  }
  memcpy(data, buffer, exLength);
  return 0;
}

bool PlanktonLighting::PLEnttecUtilities::initPro(int devNum, FT_HANDLE &handle, int readTimeout, int writeTimeout, DWORD rxBufferSize, DWORD txBufferSize)
{
  FT_STATUS status;
  status = FT_Open(devNum, &handle);
  if(status == FT_OK)
  {
    FT_SetTimeouts(handle,readTimeout,writeTimeout);
		FT_SetUSBParameters(handle,rxBufferSize,txBufferSize);
    FT_Purge (handle,FT_PURGE_RX);
    /*if(outputUniverse == 2)
    {
      if(!startUni2())
      {
        printf("Failed to start second universe \n");
        return false;
      }
    }*/
    return true;
  }
  else
  {
    printf("Error Connecting to ENTTEC DMX Pro. FTDI Error: %i\n", status);
    return false;
  }
  return false;
}

bool PlanktonLighting::PLEnttecUtilities::startUni2(FT_HANDLE &handle)
{
  unsigned char apiKey[] = {0xC9, 0xA4, 0x03, 0xE4};
  unsigned char* myKey = apiKey;
  uint8_t portSet[] = {1,1};
  unsigned int res = 0;
  FT_Purge (handle,FT_PURGE_TX);
	FT_Purge (handle,FT_PURGE_RX);
  sendData(13, myKey, 4, handle);
  boost::this_thread::sleep(boost::posix_time::milliseconds(200));
  sendData(147, portSet, 2, handle);

  return true;
}

bool PlanktonLighting::PLEnttecUtilities::closePro(FT_HANDLE &handle)
{
  if(handle != NULL)
  {
    FT_Close(&handle);
    return true;
  }
  return false;
}

int PlanktonLighting::PLEnttecUtilities::countDevices()
{
  FT_STATUS status;
  DWORD devices;
  status = FT_ListDevices((PVOID)&devices,NULL,FT_LIST_NUMBER_ONLY);
  if(status != FT_OK)
  {
    printf("Error getting device count: %i\n", status);
    return 0;
  }
  return devices;
}

bool PlanktonLighting::PLEnttecUtilities::isProDevice(int devNum)
{
  std::string proString("DMX USB PRO");
  FT_STATUS status;
  FT_DEVICE_LIST_INFO_NODE *devInfo;
  DWORD numDevs;
  status = FT_CreateDeviceInfoList(&numDevs);
  if(status == FT_OK)
  {
    devInfo = (FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
    status = FT_GetDeviceInfoList(devInfo,&numDevs);
    if(status == FT_OK)
    {
      std::string description(devInfo[devNum].Description);
      if(description.compare(0, proString.length(), proString) == 0)
      {
        return true;
      }
    }
  }
  return false;
}

int PlanktonLighting::PLEnttecUtilities::getProVersionNum(int devNum)
{
  int res = 0;
  FT_HANDLE handle;
  uint8_t hversion;
  initPro(devNum, handle, 120, 100, 40960, 40960);
  sendData(14, NULL, 0, handle);
  recieveData(14, (unsigned char *)&hversion, 1, handle);
  closePro(handle);
  return hversion;
}
