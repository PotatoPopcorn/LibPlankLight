#include "pluniverse.h"

PlanktonLighting::Universe::Universe()
{
  //Initialize all channels as zero
  for(int i = 0; i < 512; i++)
  {
    channels[i] = 0;
  }
}

PlanktonLighting::Universe::~Universe()
{
  //Pass
}

/*
  Returns the value of a channel.
  ChanNum is one based, relates to the DMX Channel number.
  Will return -1 if chanNum is invalid.
*/
int PlanktonLighting::Universe::getChan(int chanNum)
{
  //Check arguments are valid
  if(chanNum < 1 || chanNum > 512)
  {
    prinf("Warn: Invalid Channel Number: %i\n", chanNum);
    return -1;  //Return -1 which is an error
  }
  return channels[chanNum]; //Return value if valud
}

/*
  Sets the value of the channel
  Will not work if data is invalid
*/
void PlanktonLighting::Universe::setChan(int chanNum, int value)
{
  //Check arguments are valid
  if(chanNum < 1 || chanNum > 512)
  {
    prinf("Warn: Invalid Channel Number: %i\n", chanNum);
    return;
  }
  if(value < 0 || value > 255)
  {
    prinf("Warn: Invalid Channel Value: %i\n", value);
    return;
  }

  //Change channel value
  channels[chanNum] = value;
}
