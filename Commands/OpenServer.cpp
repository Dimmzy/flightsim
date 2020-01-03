#include <sstream>
#include <cstring>
#include <mutex>
#include "OpenServer.h"
#define ARG_OFFSET 2
#define END_OFFSET 4

// We'll use a mutex and a conditional variable to lock the state while we wait for connection
std::mutex mtxS;
std::condition_variable condVarS;

/**
 * We calculate the port through the Expression object, lock the mutex and start the server.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int OpenServer::execute(std::vector<std::string> lexVector, int index) {
  Expression *exp = this->interpreter->interpret(lexVector[index + ARG_OFFSET]);
  int port = exp->calculate();
  std::unique_lock<std::mutex> lck(mtxS);
  std::thread serverThread(&OpenServer::startServer, this, port);
  condVarS.wait(lck);
  serverThread.detach();
  return END_OFFSET;
}

/**
 * The function opens a socket listening on the passed port, and unlocks the mutex once connection is established.
 * @param port the port our server is listening on.
 */
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
  int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &address);
  if (client_socket == -1)
    std::cerr << "Couldn't accept client" << std::endl;
  else {
    std::cout << "Connected" << std::endl;
  }
  close(socketfd);
  char buffer[1024] = {0};
  bool unlocked = false;
  std::cout << "Server Opened Successfully" << std::endl;
  while (read(client_socket, buffer, 1024) > 0) {
    // Unlocks the mutex once we received information from the simulator.
    if (!unlocked) {
      condVarS.notify_one();
      mtxS.unlock();
      unlocked = true;
    }
    char *noNewLine = strtok(buffer, "\n");
    char *token = strtok(noNewLine, ",");
    // Checks for each index in our XML table
    for (const auto &path : this->vm->XMLVars) {
      // If we're tracking this variable, update it.
      if (this->vm->getBoundTable().count(path)) {
        this->vm->getBoundTable().at(path)->setValue(std::stod(token));
      }
      token = strtok(nullptr, ",");
    }
  }
}