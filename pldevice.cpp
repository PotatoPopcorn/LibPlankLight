#include "pldevice.h"

PlanktonLighting::PLDevice::PLDevice()
{

}

PlanktonLighting::PLDevice::~PLDevice()
{

}

bool PlanktonLighting::PLDevice::initDevice(std::string args)
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

bool PlanktonLighting::PLDevice::closeDevice()
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

bool PlanktonLighting::PLDevice::sendDMX(PlanktonLighting::PLUniverse *universe)
{
  printf("Warn: PLDevice does not exist\n");
  return false;
}

std::string PlanktonLighting::PLDevice::sendMSG(std::string args)
{
  printf("Warn: PLDevice does not exist\n");
  return "";
}
