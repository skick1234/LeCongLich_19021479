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

int main(int argc, char *argv[])
{
  int socketDescriptor, clientSocketDescriptor;
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t clientLength = sizeof(clientAddress);
  char recvBuffer[1000], sendBuffer[1000];
  pid_t cpid;
  FILE *fptr;
  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(1234);
  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

  bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  listen(socketDescriptor, 5);
  printf("Server is running ...\n");

  clientSocketDescriptor = accept(socketDescriptor, (struct sockaddr *)&clientAddress, &clientLength);

  cpid = fork();
  if (cpid == 0)
  {
    while (1)
    {
      bzero(&recvBuffer, sizeof(recvBuffer));
      recv(clientSocketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
      printf("\nCLIENT : %s", recvBuffer);
      fptr = fopen("server.txt", "a");
      fprintf(fptr, "CLIENT : %s", recvBuffer);
      fclose(fptr);
      if (strcmp(recvBuffer, "END\n") == 0)
      {
        close(clientSocketDescriptor);
        close(socketDescriptor);
        kill(0, SIGQUIT);
      }
    }
  }
  else
  {
    while (1)
    {
      bzero(&sendBuffer, sizeof(sendBuffer));
      printf("\nType your message here...\n");
      fflush(stdin);
      fgets(sendBuffer, sizeof(sendBuffer), stdin);
      fptr = fopen("server.txt", "a");
      fprintf(fptr, "SERVER : %s", sendBuffer);
      fclose(fptr);
      send(clientSocketDescriptor, sendBuffer, sizeof(sendBuffer), 0);
      if (strcmp(sendBuffer, "END\n") == 0)
      {
        close(clientSocketDescriptor);
        close(socketDescriptor);
        kill(0, SIGQUIT);
      }
    }
  }
  return 0;
}
