#include <iostream>
#include <asio.hpp>

using asio::ip::udp;

int main(int argc, char* argv[]) {
  try
  {
  if (argc != 2) {
    std::cerr << "Usage: client <host>" << std::endl;
    return 1;
  }

  asio::error_code ec;

  asio::io_context io;
  udp::resolver resolver(io);
  udp::endpoint reciever_endpoint(asio::ip::make_address(argv[1], ec), 7777);

  udp::socket socket(io);
  socket.open(udp::v4());

  char send_buf[1] = {0};
  socket.send_to(asio::buffer(send_buf), reciever_endpoint);
  std::cout << "sent message" << std::endl;

  char recv_buf[128];
  udp::endpoint sender_endpoint;
  size_t len = socket.receive_from(asio::buffer(recv_buf), sender_endpoint);
  std::cout.write(recv_buf, len);
  }
  catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
