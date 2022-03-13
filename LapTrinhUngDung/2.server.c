#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int clientSocketDescriptor, socketDescriptor;
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t clientLength;

  char sendBuffer[1000];
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(1234);
  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  listen(socketDescriptor, 5);
  printf("Server is running ...\n");
  clientSocketDescriptor = accept(socketDescriptor, (struct sockaddr *)&clientAddress, &clientLength);

  while (1)
  {
    bzero(&sendBuffer, sizeof(sendBuffer));
    printf("\nType your message here...\n");
    fflush(stdin);
    fgets(sendBuffer, sizeof(sendBuffer), stdin);
    send(clientSocketDescriptor, sendBuffer, sizeof(sendBuffer), 0);
    if (strcmp(sendBuffer, "END\n") == 0)
    {
      close(clientSocketDescriptor);
      close(socketDescriptor);
      kill(0, SIGQUIT);
    }
  }
  return 0;
}
