#include <cstdio>

#include "plenttecutilities.h"

int main(int argc, char ** argv)
{
  //Start Enttec and find devices
  PlanktonLighting::PLEnttecUtilities entUtils;
  int numDevs = entUtils.countDevices();

  //Print message if no devices are found
  if(numDevs == 0)
  {
    printf("No Devices Found\n");
  }
  //Print cound and details about device
  else
  {
    printf("%i devices connected\n", numDevs);
    for(int i = 0; i < numDevs; i++)
    {
      //Check if device is an Enttec Pro
      bool isPro = entUtils.isProDevice(i);
      printf(isPro ? "True\n" : "False\n");
      //TODO: Check version
    }
  }

}
