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
#define PORT 2222

int main(int argc, char *argv[])
{
  system("clear");
  int clientSocketDescriptor, socketDescriptor;
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t clientLength;

  char sendBuffer[1000];
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);
  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  listen(socketDescriptor, 5);
  printf("%s\n", "Server is running ...\n");
  fflush(stdout);
  clientSocketDescriptor = accept(socketDescriptor, (struct sockaddr *)&clientAddress, &clientLength);

  if (clientSocketDescriptor < 0)
  {
    perror("accept");
    exit(1);
  }

  while (1)
  {
    bzero(&sendBuffer, sizeof(sendBuffer));
    printf("Enter your message: ");
    fflush(stdout);
    fflush(stdin);
    fgets(sendBuffer, sizeof(sendBuffer), stdin);
    sendBuffer[strcspn(sendBuffer, "\n")] = 0;
    send(clientSocketDescriptor, sendBuffer, sizeof(sendBuffer), 0);
    if (strcmp(sendBuffer, "END") == 0)
    {
      close(clientSocketDescriptor);
      close(socketDescriptor);
      kill(0, SIGSTOP);
    }
  }
  return 0;
}
