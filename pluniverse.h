#ifndef PLUNIVERSE_H
#define PLUNIVERSE_H

#include <cstdio>

namespace PlanktonLighting{
  //Creates a universe structure that can be used to send data to devices
  class Universe{
  public:
    Universe();
    ~Universe();

    int getChan(int chanNum);
    void setChan(int chanNum, int value);

  private:
    int channels[512];
  };
}

#endif //PLUNIVERSE_H
