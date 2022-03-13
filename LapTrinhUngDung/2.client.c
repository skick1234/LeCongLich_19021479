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

int main()
{
  struct sockaddr_in serverAddress;
  char recvBuffer[1000];
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(1234);
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

  connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

  while (1)
  {
    bzero(&recvBuffer, sizeof(recvBuffer));
    recv(socketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
    printf("SERVER : %s", recvBuffer);
    if (strcmp(recvBuffer, "END\n") == 0)
    {
      close(socketDescriptor);
      kill(0, SIGQUIT);
    }
  }
  return 0;
}
