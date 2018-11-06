/*

IMPORTANT: This class should never be used as an output device, it exists only to be overridden by other devices
*/

#include "pldevice.h"

//Empty constructor and destructor
PlanktonLighting::PLDevice::PLDevice()
{

}

PlanktonLighting::PLDevice::~PLDevice()
{

}

//Generic function for stating the device
bool PlanktonLighting::PLDevice::initDevice(std::string args)
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

//Generic function for stopping the device
bool PlanktonLighting::PLDevice::closeDevice()
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

//Generic function for sending DMX to the device
bool PlanktonLighting::PLDevice::sendDMX(PlanktonLighting::PLUniverse *universe)
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

//Generic function for sending control messages to the device
std::string PlanktonLighting::PLDevice::sendMSG(std::string args)
{
  printf("Warn: PLDevice does not exist\n");
  return "";
}
