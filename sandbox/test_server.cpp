#include <ctime>
#include <iostream>
#include <string>
#include <asio.hpp>

using asio::ip::udp;

std::string make_daytime_string() {
  std::time_t now = time(0);
  return std::ctime(&now);
}

int main() {
  try
  {
    asio::io_context io;
    udp::socket socket(io, udp::endpoint(udp::v4(),7777));
    socket.non_blocking(true);
    for(;;)
    {
      char recv_buf[1];
      udp::endpoint remote_endpoint;
      try {
        socket.receive_from(asio::buffer(recv_buf), remote_endpoint);
        std::cout << "something" << std::endl;
      }
      catch (std::exception& e) {
        std::cout << "nothing" << std::endl;
        continue;
      }
      std::string message = make_daytime_string();
      asio::error_code ignored_error;
      socket.send_to(asio::buffer(message), remote_endpoint, 0, ignored_error);
    }
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
