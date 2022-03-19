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
#define PORT 3333

int main(int argc, char *argv[])
{
  system("clear");
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t clientLength = sizeof(clientAddress);
  char recvBuffer[1000], sendBuffer[1000];
  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

  bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  listen(socketDescriptor, 5);
  printf("Server is running ...\n");

  int clientSocketDescriptor = accept(socketDescriptor, (struct sockaddr *)&clientAddress, &clientLength);
  if (clientSocketDescriptor < 0)
  {
    perror("accept");
    exit(1);
  }

  pid_t cpid = fork();
  FILE *fptr;
  if (cpid == 0)
  {
    while (1)
    {
      bzero(&recvBuffer, sizeof(recvBuffer));
      recv(clientSocketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
      printf("\nCLIENT : %s\n", recvBuffer);
      fptr = fopen("server.txt", "a");
      fprintf(fptr, "CLIENT : %s\n", recvBuffer);
      fclose(fptr);
      if (strcmp(recvBuffer, "END") == 0)
      {
        close(clientSocketDescriptor);
        close(socketDescriptor);
        kill(0, SIGSTOP);
      }
    }
  }
  else
  {
    while (1)
    {
      bzero(&sendBuffer, sizeof(sendBuffer));
      printf("\nType your message...\n");
      fflush(stdin);
      fgets(sendBuffer, sizeof(sendBuffer), stdin);
      sendBuffer[strcspn(sendBuffer, "\n")] = 0;
      fptr = fopen("server.txt", "a");
      fprintf(fptr, "SERVER : %s\n", sendBuffer);
      fclose(fptr);
      send(clientSocketDescriptor, sendBuffer, sizeof(sendBuffer), 0);
      if (strcmp(sendBuffer, "END") == 0)
      {
        close(clientSocketDescriptor);
        close(socketDescriptor);
        kill(0, SIGSTOP);
      }
    }
  }
  return 0;
}
