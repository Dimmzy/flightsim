
#include "Command.h"

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

int ConnectServer::execute(std::vector<std::string> args) {
  const char* ip = args[0].c_str();
  int port = std::stoi(args[1]);
  std::thread clientThread(startClient,ip,port);
  return 3;
}

void ConnectServer::startClient(const char* ip, int port) {
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

}

int Print::execute(std::vector<std::string> args) {
  std::cout << args[0] << std::endl;
  return 2;
}

int Sleep::execute(std::vector<std::string> args) {
  std::this_thread::sleep_for(std::chrono::milliseconds(stoi(args[0])));
  return 2;
}

int DefineVar::execute(std::vector<std::string> args) {

}
While::While(map<std::string, Command *> &commands) {
x
}
