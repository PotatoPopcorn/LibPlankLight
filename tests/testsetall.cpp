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
    uni->blackout();
    printf("Please enter the value you want to set all the channels to: \n");
    int *val = (int*) malloc(sizeof(int));
    scanf("%i", val);
    uni->setAll(*val);
    th.sendDMX(uni);
    th.disconnectDevice();
    return 0;
}
