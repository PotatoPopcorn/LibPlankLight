#include <cstdio>
#include <cstdlib>

#include "../pluniverse.h"

#include "testhelper.h"

int main(int argc, char **argv)
{
    TestHelper th;
    if(!th.connectDevice(argc, argv))
    {
        exit(1);
    }
    PlanktonLighting::PLUniverse *uni = new PlanktonLighting::PLUniverse();
    uni->whiteout();
    th.sendDMX(uni);
    th.disconnectDevice();
    return 0;
}
