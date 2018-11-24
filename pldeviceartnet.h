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
    unsigned char m_subUni = 0;
    unsigned char m_net = 0;
    unsigned char m_seq = 0;

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
