#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "config.h"
#include <string>
#include <unistd.h>

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
    using namespace std;
    time_t now = time(0);
    return ctime(&now);
}

int main() {
    try
    {
        char buffer[4096];
        boost::system::error_code error;
        boost::asio::io_service io_service;
        // create an io_server object
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), MY_PORT));
        // bind a host:port to this io_service object, an implicit socket is created
        std::string port_str = std::to_string(MY_PORT);
        std::cout << "Serving HTTP on port: " + port_str << std::endl;
        while(1) {
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            // accept one connection
            std::cout << "Tcp Connection Established" << std::endl;
            while (1) {
                size_t len = socket.read_some(boost::asio::buffer(buffer), error);
                if (error == boost::asio::error::eof) {
                    std::cout << "Connection Closed" << std::endl;
                    break;
                }
                else if (error) {
                    throw boost::system::system_error(error);
                }
                std::cout << "Bytes Received:" << len << "##" << std::endl;
                std::cout << buffer << "##" << std::endl;

                std::string buffer_str(buffer);
                boost::asio::write(socket, boost::asio::buffer(buffer_str), error);
            }
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}