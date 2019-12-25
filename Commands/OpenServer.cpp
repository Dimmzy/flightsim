
#include "OpenServer.h"

int OpenServer::execute(std::vector<std::string> args) {
  int port = std::stoi(args[0]);
  std::thread serverThread(startServer,port);
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
  char buffer[1024] = {0};
  int valread = read(client_socket, buffer, 1024);
  // Write a parser that maps the variables and their values to our HashMap
}