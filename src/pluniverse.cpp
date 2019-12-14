//Copyright 2019 PotatoPopcorn (Tony Kerr)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// See LICENCE

#include "pluniverse.h"

PlanktonLighting::PLUniverse::PLUniverse()
{
  //Initialize all channels as zero
  for(int i = 0; i < 512; i++)
  {
    channels[i] = 0;
  }
}

PlanktonLighting::PLUniverse::~PLUniverse()
{
  //Pass
}

/*
  Returns the value of a channel.
  ChanNum is one based, relates to the DMX Channel number.
  Will return -1 if chanNum is invalid.
*/
int PlanktonLighting::PLUniverse::getChan(int chanNum)
{
  //Check arguments are valid
  if(chanNum < 1 || chanNum > 512)
  {
    printf("Warn: Invalid Channel Number: %i\n", chanNum);
    return -1;  //Return -1 which is an error
  }
  return channels[chanNum-1]; //Return value if valud
}

/*
  Sets the value of the channel
  Will not work if data is invalid
*/
void PlanktonLighting::PLUniverse::setChan(int chanNum, int value)
{
  //Check arguments are valid
  if(chanNum < 1 || chanNum > 512)
  {
    printf("Warn: Invalid Channel Number: %i\n", chanNum);
    return;
  }
  if(value < 0 || value > 255)
  {
    printf("Warn: Invalid Channel Value: %i\n", value);
    return;
  }

  //Change channel value
  channels[chanNum-1] = value;
}

// Set all channels to zero
void PlanktonLighting::PLUniverse::blackout()
{
  for(int i = 1; i < 513; i++)
  {
    setChan(i, 0);
  }
}

// Set all channels to full
void PlanktonLighting::PLUniverse::whiteout()
{
  for(int i = 1; i < 513; i++)
  {
    setChan(i, 255);
  }
}

//Set all channels to a particular value
void PlanktonLighting::PLUniverse::setAll(int value)
{
  for(int i = 1; i < 513; i++)
  {
    setChan(i, value);
  }
}
