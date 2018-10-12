#include <cstdio>

#include "plenttecutilities.h"

int main(int argc, char ** argv)
{
  PlanktonLighting::PLEnttecUtilities entUtils;
  int numDevs = entUtils.countDevices();
  if(numDevs == 0)
  {
    printf("No Devices Found\n");
  }
  else
  {
    printf("%i devices connected\n", numDevs);
    for(int i = 0; i < numDevs; i++)
    {
      bool isPro = entUtils.isProDevice(i);
      printf(isPro ? "True\n" : "False\n");
    }
  }

}
