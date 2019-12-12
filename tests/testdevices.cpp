#include <cstdio>
#include <string>
#include <vector>

#include "../src/pldevices.h"

int main(int argc, char **argv)
{
    PlanktonLighting::PLDevices devices;
    std::vector<std::string> types = devices.getSupportedTypes();
    printf("There is %lu types supported: \n", types.size());
    for(int i = 0; i < types.size(); ++i)
    {
        printf(" + %s\n", types[i].c_str());
    }

    std::vector<std::string> ava = devices.getAvailableDevices();
    printf("There is %lu devices avaliable: \n", ava.size());
    for(int i = 0; i < ava.size(); ++i)
    {
        printf(" + %s\n", ava[i].c_str());
    }
    return 0;
}
