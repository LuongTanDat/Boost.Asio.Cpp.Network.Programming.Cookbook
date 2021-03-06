#include <boost/asio.hpp>
#include <iostream>

int main()
{
	// Step 1. An instance of 'io_service' class is required by
	// socket constructor.
	boost::asio::io_service ios;

	// Step 2. Creating an object of 'tcp' class representing
	// a TCP protocol with IPv4 as underlying protocol.
	boost::asio::ip::tcp protocol = boost::asio::ip::tcp::v4();

	try
	{
		// Step 3 + 4 in single call. May throw.
		boost::asio::ip::tcp::socket sock(ios, protocol);
	}
	catch (boost::system::system_error &e)
	{
		std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();
	}

	return 0;
}