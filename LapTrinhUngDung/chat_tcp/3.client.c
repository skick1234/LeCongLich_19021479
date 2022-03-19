#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#define PORT 3333

int main()
{
  system("clear");
  struct sockaddr_in serverAddress;
  char sendBuffer[1000], recvBuffer[1000];
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(PORT);
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);

  if (connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(struct sockaddr_in)) < 0)
  {
    perror("connect");
    return 1;
  }
  printf("\nConnected to server\n");

  pid_t cpid = fork();
  FILE *fptr;
  if (cpid == 0)
  {
    while (1)
    {
      bzero(&sendBuffer, sizeof(sendBuffer));
      printf("\nType your message...\n");
      fflush(stdin);
      fgets(sendBuffer, sizeof(sendBuffer), stdin);
      sendBuffer[strcspn(sendBuffer, "\n")] = 0;
      send(socketDescriptor, sendBuffer, sizeof(sendBuffer), 0);
      fptr = fopen("client.txt", "a");
      fprintf(fptr, "CLIENT : %s\n", sendBuffer);
      fclose(fptr);
      if (strcmp(sendBuffer, "END") == 0)
      {
        close(socketDescriptor);
        kill(0, SIGSTOP);
      }
    }
  }
  else
  {
    while (1)
    {
      bzero(&recvBuffer, sizeof(recvBuffer));
      recv(socketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
      printf("\nSERVER : %s\n", recvBuffer);
      fflush(stdout);
      fptr = fopen("client.txt", "a");
      fprintf(fptr, "SERVER : %s\n", recvBuffer);
      fclose(fptr);
      if (strcmp(recvBuffer, "END") == 0)
      {
        close(socketDescriptor);
        kill(0, SIGSTOP);
      }
    }
  }
  return 0;
}
