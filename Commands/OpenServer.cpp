
#include <sstream>
#include <cstring>
#include <mutex>
#include "OpenServer.h"
#define ARG_OFFSET 2
#define END_OFFSET 4


int OpenServer::execute(std::vector<std::string> lexVector, int index) {
  Expression* exp = this->interpreter->interpret(lexVector[index + ARG_OFFSET]);
  int port = exp->calculate();
  std::thread serverThread(&OpenServer::startServer,this,port);
  return END_OFFSET;
}

void OpenServer::startServer(int port) {
  std::mutex mtx;
  mtx.lock();
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
  std::cout << "Server Opened Succesfully" << std::endl;
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