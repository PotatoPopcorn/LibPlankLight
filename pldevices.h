#ifndef PLDEVICES_H
#define PLDEVICES_H

#include <string>
#include <vector>

namespace PlanktonLighting{
  class PLDevices{
  public:
      std::vector<std::string> getSupportedTypes();
      std::vector<std::string> getAvailableDevices();
  };
}

#endif //PLDEVICES_H
