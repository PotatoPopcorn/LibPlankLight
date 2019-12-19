//Copyright 2019 PotatoPopcorn (Tony Kerr)

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
// See LICENCE

#ifndef PLDEVICEARTNET_H
#define PLDEVICEARTNET_H

#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include "pldevice.h"

namespace PlanktonLighting
{
  class PLDeviceArtnet : public PLDevice
  {
  public:
    PLDeviceArtnet();
    ~PLDeviceArtnet();

    bool initDevice(std::string args);
    bool closeDevice();

    bool sendDMX(PlanktonLighting::PLUniverse *universe);
    std::string sendMSG(std::string args);
  private:
    bool m_mainLoopAlive = false;
    PlanktonLighting::PLUniverse *m_universe;

    //Artnet Variables:
    std::string m_address;
    int m_port = 6454;
    unsigned char m_physical = 0;
    unsigned char m_subUni = 0;
    unsigned char m_net = 0;
    unsigned char m_seq = 0;
    bool m_sendSeq = true;

    //Boost Variables
    boost::asio::io_context m_ioContext;
    boost::asio::io_context m_tSlow;
    boost::thread_group m_tgroup;
    boost::asio::ip::udp::socket *m_socket;
    boost::asio::ip::udp::endpoint m_recieverEndpoint;

    bool processArgs(std::string args);
    void incrementSequence();
	  void keepAlive();
  };
}

#endif //PLDEVICEARTNET_H
