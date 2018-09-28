#ifndef PLDEVICE_H
#define PLDEVICE_H

#include <cstdio>
#include <string>

#include "pluniverse.h"

namespace PlanktonLighting{
  class PLDevice{
  public:
    PLDevice();
    ~PLDevice();

    virtual bool initDevice(std::string args);
    virtual bool closeDevice();

    virtual bool sendDMX(PlanktonLighting::PLUniverse *universe);
    virtual std::string sendMSG(std::string args);
  };
}

#endif //PLDEVICE_H
