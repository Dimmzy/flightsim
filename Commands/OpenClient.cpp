#include <mutex>
#include "OpenClient.h"

std::mutex mtx;

int OpenClient::execute(std::vector<std::string> args) {
  const char* ip = args[0].c_str();
  int port = std::stoi(args[1]);
  mtx.lock();
  std::thread clientThread(&OpenClient::startClient,this,ip,port);
  return 3;
}

void OpenClient::startClient(const char* ip, int port) {
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1)
    std::cerr << "Couldn't create client socket" << std::endl;
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(ip);
  address.sin_port = htons(port);
  int is_connect = connect(client_socket, (struct sockaddr *)&address, sizeof(address));
  if (is_connect == -1)
    std::cerr << "Couldn't connect to host" << std::endl;
  // Add functionality of sending information through the client to the server
  this->clientSocket = client_socket;
  mtx.unlock();
}
void OpenClient::sendUpdate(const std::string& message) {
  ssize_t return_val;
  return_val = write(this->clientSocket,message.c_str(),message.length());
  if (return_val == -1)
    std::cerr << "Couldn't send updated variable information" << std::endl;
}

