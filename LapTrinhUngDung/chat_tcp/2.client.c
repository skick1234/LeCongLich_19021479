#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#define PORT 2222

int main()
{
  system("clear");
  struct sockaddr_in serverAddress;
  char recvBuffer[1000];
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(PORT);
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

  if (connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
  {
    perror("connect");
    return 1;
  }
  printf("\nConnected to server\n");

  while (1)
  {
    bzero(&recvBuffer, sizeof(recvBuffer));
    recv(socketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
    printf("SERVER : %s\n", recvBuffer);
    if (strcmp(recvBuffer, "END") == 0)
    {
      close(socketDescriptor);
      kill(0, SIGSTOP);
    }
  }
  return 0;
}
