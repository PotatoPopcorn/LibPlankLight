#include <cstdio>
#include <cstdlib>

#include <boost/thread/thread.hpp>

#include "pldeviceenttecpro.h"
#include "pluniverse.h"

int main(int argc, char ** argv)
{
  //Start Enttec Device
  PlanktonLighting::PLDeviceEnttecPro *enttec = new PlanktonLighting::PLDeviceEnttecPro();
  bool res = enttec->initDevice("0 1");
  if(res == false)
  {
    printf("Failed to init device, Crashing\n");
    return 1;
  }
  //Creade a blackout universe
  PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
  enttec->sendDMX(uni);

  //Close the device and end the program
  enttec->closeDevice();
  return 0;
}
