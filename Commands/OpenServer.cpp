
#include <sstream>
#include <cstring>
#include <mutex>
#include "OpenServer.h"

std::mutex mtx;

int OpenServer::execute(std::vector<std::string> args) {
  int port = std::stoi(args[0]);
  mtx.lock();
  std::thread serverThread(&OpenServer::startServer,this,port);
  serverThread.join();
  return 2;
}

void OpenServer::startServer(int port) {
  int socketfd = socket(AF_INET, SOCK_STREAM, 0);
  if (socketfd == -1)
    std::cerr << "Couldn't create socket" << std::endl;
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);
  if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1)
    std::cerr << "Couldn't bind socket to IP" << std::endl;
  if (listen(socketfd, 5) == -1)
    std::cerr << "Couldn't listen to socket" << std::endl;
  int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t*)&address);
  if (client_socket == -1)
    std::cerr << "Couldn't accept client" << std::endl;
  else {
    std::cout << "Connected" << std::endl;
  }
  close(socketfd);
  char buffer[1024] = {0};
  mtx.unlock();
  while(read(client_socket, buffer, 1024) > 0) {
    char* noNewLine = strtok(buffer, "\n");
    char* token = strtok(noNewLine, ",");
    for(const auto& path : this->vm->XMLVars) {
      if (this->vm->getBoundTable().count(path)) {
        this->vm->getBoundTable().at(path)->setValue(std::stod(token));
        std::cout << "updated " + path + " to " + token << std::endl;
        std::cout << "proof: " + std::to_string(this->vm->getBoundTable().at(path)->getValue()) << std::endl;
      }
      token = strtok(nullptr, ",");
    }
  }
}