#include <cstdio>
#include <cstdlib>

#include <boost/thread/thread.hpp>

#include "pldeviceenttecpro.h"
#include "pluniverse.h"

int main(int argc, char ** argv)
{
  PlanktonLighting::PLDeviceEnttecPro *enttec = new PlanktonLighting::PLDeviceEnttecPro();
  bool res = enttec->initDevice("0");
  printf("%d\n", res);
  PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
  uni->setChan(3, 255);
  uni->setChan(9, 255);
  for(int i = 0; i < 100000; i++)
  {
    printf("Frame\n");
    uni->setChan(2, rand()%255);
    uni->setChan(8, rand()%255);
    enttec->sendDMX(uni);
    boost::this_thread::sleep(boost::posix_time::milliseconds(100));
  }

  enttec->closeDevice();
  return 0;
}
