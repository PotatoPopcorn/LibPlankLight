#include <cstdio>
#include <cstdlib>

#include "../src/pluniverse.h"

#include "testhelper.h"

int main(int argc, char **argv)
{
    TestHelper th;
    if(!th.connectDevice(argc, argv))
    {
        exit(1);
    }
    PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
    uni->blackout();
    th.sendDMX(uni);
    th.disconnectDevice();
    return 0;
}
