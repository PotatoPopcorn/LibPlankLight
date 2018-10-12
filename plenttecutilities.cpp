#include "plenttecutilities.h"

PlanktonLighting::PLEnttecUtilities::PLEnttecUtilities()
{

}

PlanktonLighting::PLEnttecUtilities::~PLEnttecUtilities()
{

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
  //TODO
  return 0;
}
