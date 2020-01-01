#include <mutex>
#include "OpenClient.h"
#define ARG_OFFSET 2
#define END_OFFSET 4


int OpenClient::execute(std::vector<std::string> lexVector, int index) {
  const char* ip = lexVector[index + ARG_OFFSET].substr(0,lexVector[index + ARG_OFFSET].find(',')).c_str();
  int port = std::stoi(lexVector[index + ARG_OFFSET].substr(lexVector[index + ARG_OFFSET].find(',') + 1));
  std::thread clientThread(&OpenClient::startClient,this,ip,port);
  clientThread.detach();
  return END_OFFSET;
}

void OpenClient::startClient(const char* ip, int port) {
  std::mutex mtx;
  mtx.lock();
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
  std::cout << "Client Opened Successfully" << std::endl;
  mtx.unlock();
}
void OpenClient::sendUpdate(const std::string& message) {
  ssize_t return_val;
  return_val = write(this->clientSocket,message.c_str(),message.length());
  if (return_val == -1)
    std::cerr << "Couldn't send updated variable information" << std::endl;
}

