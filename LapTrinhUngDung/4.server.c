/*
 * Title : Full duplex server side
 * Name : Aditya Pratap Singh Rajput
 * Subject : Network Protocols And Programming using C
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void handleNewProcess() {}

int main(int argc, char *argv[])
{
  int clientSocketDescriptor, socketDescriptor;
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t clientLength = sizeof(clientAddress);
  char recvBuffer[1000], sendBuffer[1000];
  pid_t cpid;
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(1234);
  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  listen(socketDescriptor, 10);
  printf("Server is running ...\n");
  cpid = fork();
  while (1)
  {
    clientSocketDescriptor = accept(socketDescriptor, (struct sockaddr *)&clientAddress, &clientLength);

    cpid = fork();
    if (cpid == 0)
    {
      while (1)
      {
        bzero(&recvBuffer, sizeof(recvBuffer));
        recv(clientSocketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
        printf("\nCLIENT : %s", recvBuffer);
        if (strcmp(recvBuffer, "END\n") == 0)
        {
          close(clientSocketDescriptor);
          kill(cpid, SIGQUIT);
        }
      }
    }
  }
  return 0;
}
