#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

const std::string serverMessage = "Hello from the server!";
const std::string serverError = "An error occurred!";
const boost::asio::ip::port_type port = 8080;

int main() {
    while (true) {
        boost::asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));

        tcp::socket socket(io_context);
        acceptor.accept(socket);

        std::array<char, 1024> data;
        boost::system::error_code error;
        size_t length = socket.read_some(boost::asio::buffer(data), error);

        if (error) {
            std::cout << "An error occurred! Received data: " << std::string(data.data(), length) << std::endl;

            boost::asio::write(socket, boost::asio::buffer(serverError));
        }
        else {
            std::cout << "Received data: " << std::string(data.data(), length) << std::endl;

            boost::asio::write(socket, boost::asio::buffer(serverMessage));
        }
    }
    return 0;
}
