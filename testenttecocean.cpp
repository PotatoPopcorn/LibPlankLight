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
  // Create the universe and set constant values
  PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
  uni->setChan(1, 255);
  uni->setChan(7, 255);
  uni->setChan(5, 255);
  uni->setChan(11, 255);

  // Start loop to create effect
  for(int i = 0; i < 100000; i++)
  {
    printf("Frame\n");
    uni->setChan(4, rand()%255);
    uni->setChan(10, rand()%255);

    // Send universe to device and wait 0.1sec
    enttec->sendDMX(uni);
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }

  //Close the device and end the program
  enttec->closeDevice();
  return 0;
}
