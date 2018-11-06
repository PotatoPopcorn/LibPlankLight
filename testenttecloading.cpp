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

  // Create universe
  PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
  //Effect Loop
  for(int i = 0; i < 100000; i++)
  {
    //Create inner flash effect
    int inner = i % 512;
    if(inner<256)
    {
      uni->setChan(4, inner);
    }
    else
    {
      uni->setChan(4, 511-inner);
    }

    //Create outer loading effect
    int outer = i % 48;
    if(outer < 16)
    {
      uni->setChan(1, 255);
      uni->setChan(2, 0);
      uni->setChan(3, 0);
    }
    else if(outer < 32)
    {
      uni->setChan(1, 0);
      uni->setChan(2, 255);
      uni->setChan(3, 0);
    }
    else
    {
      uni->setChan(1, 0);
      uni->setChan(2, 0);
      uni->setChan(3, 255);
    }

    //Send universe to device
    enttec->sendDMX(uni);
    boost::this_thread::sleep(boost::posix_time::milliseconds(5));
    printf("Frame\n");

  }

  //Close the device and end the program
  enttec->closeDevice();
  return 0;
}
