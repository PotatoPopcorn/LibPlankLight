#include "pldeviceartnet.h"

//Empty constructor
PlanktonLighting::PLDeviceArtnet::PLDeviceArtnet()
{

}

//Empty destructor
PlanktonLighting::PLDeviceArtnet::~PLDeviceArtnet()
{

}

//Start artnet device, args must have the format:
//[IP Address] [Port] [Physical] [Subnet] [Net] [Send Sequence]
bool PlanktonLighting::PLDeviceArtnet::initDevice(std::string args)
{
  //Initialize values
  m_universe = new PLUniverse;

  processArgs(args);

  //Setup Network Connection
  try{
    boost::asio::ip::udp::resolver resolver(m_ioContext);
		m_recieverEndpoint = *resolver.resolve(boost::asio::ip::udp::v4(), m_address, "6454").begin();
		m_socket = new boost::asio::ip::udp::socket(m_ioContext);
		m_socket->open(boost::asio::ip::udp::v4());
  }
  catch(std::exception& e)
  {
    printf("ERROR %s\n", e.what());
		return false;
  }
  m_mainLoopAlive = true;
	m_tgroup.create_thread(boost::bind(&PlanktonLighting::PLDeviceArtnet::keepAlive, this));
	return true;
}

//Stop the artnet device
bool PlanktonLighting::PLDeviceArtnet::closeDevice()
{
  m_mainLoopAlive = false;
	m_tgroup.join_all();

    m_socket->close();
    delete m_socket;
    delete m_universe;

	return true;
}

//Sends the universe to the device
bool PlanktonLighting::PLDeviceArtnet::sendDMX(PlanktonLighting::PLUniverse *universe)
{
  //Copy values from parsed universe into
  for(int i = 1; i <= 512; i++)
  {
    m_universe->setChan(i, universe->getChan(i));
  }
  return true;
}

//Processes a message sent to the device, used to access aditional features
std::string PlanktonLighting::PLDeviceArtnet::sendMSG(std::string args)
{
  std::string retStr;
  return retStr;
}

//A private function, used to set all the variables
bool PlanktonLighting::PLDeviceArtnet::processArgs(std::string args)
{
  //Turn args into a vector and check all required have been parsed
  std::vector<std::string> argVec;
  boost::split(argVec, args, boost::is_any_of(" "), boost::token_compress_on );
  if(argVec.size() != 6)
  {
    printf("Too few arguments sent to Artnet\n");
    return false;
  }

  //Process Args
  try{
    m_address = argVec[0];
    m_port = atoi(argVec[1].c_str());
    m_physical = (unsigned char) atoi(argVec[2].c_str());
    m_subUni = (unsigned char) atoi(argVec[3].c_str());
    m_net = (unsigned char) atoi(argVec[4].c_str());
    if(argVec[5] == "0"){ m_sendSeq = false; }
    else if (argVec[5] != "1") {printf("ERROR Parsing send sequence in LPL Artnet");}
  }
  catch(std::exception& e)
  {
    printf("ERROR %s\n", e.what());
    printf("Invalid arguments parsed to ArtNet device");
    return false;
  }
  return true;

}

//Implements the Artnet sequence
void PlanktonLighting::PLDeviceArtnet::incrementSequence()
{
  if(m_sendSeq)
  {
    if (m_seq >= 256)
  	{
  		m_seq = 1;
  	}
  	else
  	{
  		++m_seq;
  	}
  }
}

//Run inside the thread, ensures that data is constantly sent. This function is also responsible for sending the packets.
void PlanktonLighting::PLDeviceArtnet::keepAlive()
{
  while (m_mainLoopAlive)
	{
		try
		{
			boost::array<unsigned char, 530> sendBuf = { 'A', 'r', 't', '-', 'N', 'e', 't', 0, 0, 0x50, 0, 0x0e, m_seq, m_physical, m_subUni, m_net, 0x02, 0 };
			for (int i = 0; i < 512; ++i)
			{
				sendBuf.at(i + 18) = m_universe->getChan(i+1);
			}
			m_socket->send_to(boost::asio::buffer(sendBuf), m_recieverEndpoint);
			incrementSequence();
		}
		catch (std::exception& e)
		{
			perror(e.what());
		}
		//boost::asio::deadline_timer t(m_tslow, boost::posix_time::milliseconds(1));
		//t.wait();
	}
}
