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

int main()
{
  int socketDescriptor;
  struct sockaddr_in serverAddress;
  char sendBuffer[1000], recvBuffer[1000];
  pid_t cpid;
  FILE *fptr;
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
  serverAddress.sin_port = htons(1234);
  socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  connect(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(struct sockaddr_in));

  printf("\nConnected to server\n");

  cpid = fork();
  if (cpid == 0)
  {
    while (1)
    {
      bzero(&sendBuffer, sizeof(sendBuffer));
      printf("\nType your message here...\n");
      fflush(stdin);
      fgets(sendBuffer, sizeof(sendBuffer), stdin);
      send(socketDescriptor, sendBuffer, sizeof(sendBuffer), 0);
      fptr = fopen("client.txt", "a");
      fprintf(fptr, "CLIENT : %s", sendBuffer);
      fclose(fptr);
      if (strcmp(sendBuffer, "END\n") == 0)
      {
        close(socketDescriptor);
        kill(0, SIGQUIT);
      }
    }
  }
  else
  {
    while (1)
    {
      bzero(&recvBuffer, sizeof(recvBuffer));
      recv(socketDescriptor, recvBuffer, sizeof(recvBuffer), 0);
      printf("\nSERVER : %s", recvBuffer);
      fptr = fopen("client.txt", "a");
      fprintf(fptr, "SERVER : %s", recvBuffer);
      fclose(fptr);
      if (strcmp(recvBuffer, "END\n") == 0)
      {
        close(socketDescriptor);
        kill(0, SIGQUIT);
      }
    }
  }
  return 0;
}
