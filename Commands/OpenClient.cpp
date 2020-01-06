#include <mutex>
#include <condition_variable>
#include <cstring>
#include <algorithm>
#include "OpenClient.h"
#define ARG_OFFSET 2
#define END_OFFSET 4

// We'll use a mutex and a conditional variable to lock the state while we wait for connection
std::mutex mtxC;
std::condition_variable condVarC;

/**
 * We extract the needed connection info from the file, lock the mutex and wait for the connection.
 * @param lexVector Our parsed vector
 * @param index The current index we're iterating through.
 * @return The offset we move through our parsed vector.
 */
int OpenClient::execute(std::vector<std::string> lexVector, int index) {
  // Extracts the IP and Port address from the vector string.
  char *token = strtok(const_cast<char*>(lexVector[index + ARG_OFFSET].c_str()),",");
  const char* ip = token;
  token = strtok(nullptr, ",");
  std::string portStr(token);
  portStr.erase(remove(portStr.begin(), portStr.end(), ' '), portStr.end());
  int port = (int)this->interpreter->interpret(portStr)->calculate();
  std::unique_lock<std::mutex> lck(mtxC);
  std::thread clientThread(&OpenClient::startClient,this,ip,port);
  condVarC.wait(lck);
  clientThread.detach();
  return END_OFFSET;
}

/**
 * Starts the client, when a connection is established, we unlock the mutex and let the process continue running.
 * @param ip our simulator's IP address
 * @param port our simulator's port address
 */
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
  this->clientSocket = client_socket;
  std::cout << "Client Opened Successfully" << std::endl;
  // Unlock the mutex and notify the conditional variable we're finished.
  mtxC.unlock();
  condVarC.notify_one();
}

/**
 * Used for sending variable updates to the simulator through a predefined message structure, using supplied string.
 * @param message the message we send to the server (correct structure is handled by caller)
 */
void OpenClient::sendUpdate(const std::string& message) {
  ssize_t return_val;
  return_val = write(this->clientSocket,message.c_str(),message.length());
  if (return_val == -1)
    std::cerr << "Couldn't send updated variable information" << std::endl;
}
void OpenClient::closeSocket() {
  close(this->clientSocket);
}


