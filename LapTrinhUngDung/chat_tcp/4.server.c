#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#define PORT 4444
#define MAX_CLIENTS 1024
#define MAX_BUFFER_SIZE 1024

pthread_t thread[MAX_CLIENTS];
int clientSockets[MAX_CLIENTS];
FILE *fptr;

void getAndSendMessage()
{
  char sendBuffer[MAX_BUFFER_SIZE];
  while (1)
  {
    bzero(&sendBuffer, sizeof(sendBuffer));
    printf("\nType your message here ...\n");
    fflush(stdin);
    fgets(sendBuffer, sizeof(sendBuffer), stdin);
    sendBuffer[strcspn(sendBuffer, "\n")] = 0;
    fptr = fopen("server.txt", "a");
    fprintf(fptr, "SERVER : %s\n", sendBuffer);
    fclose(fptr);
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
      if (clientSockets[i] != -1)
      {
        send(clientSockets[i], sendBuffer, sizeof(sendBuffer), 0);
      }
    }
    if (strcmp(sendBuffer, "END") == 0)
    {
      for (int i = 0; i < MAX_CLIENTS; i++)
      {
        if (clientSockets[i] != -1)
        {
          close(clientSockets[i]);
        }
      }
      kill(0, SIGSTOP);
    }
  }
}

void listenSocket(void *clientId)
{
  int id = *(int *)clientId;
  char recvBuffer[MAX_BUFFER_SIZE];
  while (1)
  {
    bzero(&recvBuffer, sizeof(recvBuffer));
    recv(clientSockets[id], recvBuffer, sizeof(recvBuffer), 0);
    printf("\nClient %d: %s\n", id, recvBuffer);
    fptr = fopen("server.txt", "a");
    fprintf(fptr, "CLIENT %d: %s\n", id, recvBuffer);
    fclose(fptr);
    if (strcmp(recvBuffer, "END") == 0)
    {
      close(clientSockets[id]);
      clientSockets[id] = -1;
      pthread_cancel(thread[id]);
      thread[id] = -1;
      break;
    }
  }
}

int createThread(int descriptor)
{
  int i;
  for (i = 0; i < MAX_CLIENTS; i++)
  {
    if (clientSockets[i] == -1)
    {
      clientSockets[i] = descriptor;
      int *clientId = (int *)malloc(sizeof(int));
      *clientId = i;
      pthread_create(&thread[i], NULL, (void *)listenSocket, clientId);
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[])
{
  system("clear");
  int i;
  for (i = 0; i < MAX_CLIENTS; i++)
  {
    clientSockets[i] = -1;
    thread[i] = -1;
  }
  struct sockaddr_in serverAddress, clientAddress;
  socklen_t clientLength = sizeof(clientAddress);
  bzero(&serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(PORT);
  int socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socketDescriptor < 0)
  {
    perror("socket");
    return -1;
  }

  bind(socketDescriptor, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
  if (listen(socketDescriptor, MAX_CLIENTS) < 0)
  {
    perror("listen");
    return -1;
  }
  printf("Server is running ...\n");

  // First thread: Send message to sockets
  pthread_t thread1;
  pthread_create(&thread1, NULL, (void *)&getAndSendMessage, NULL);

  // Other threads: Listen to sockets
  while (1)
  {
    int clientSocketDescriptor = accept(socketDescriptor, (struct sockaddr *)&clientAddress, &clientLength);
    if (clientSocketDescriptor < 0)
    {
      perror("accept");
      continue;
    }
    int clientId = createThread(clientSocketDescriptor);
    if (clientId == -1)
    {
      printf("\nReached MAX_CLIENTS (%d). No more clients can be accepted.\n", MAX_CLIENTS);
      close(clientSocketDescriptor);
    }
    else
    {
      printf("\nClient %d is connected by %s:%d\n", clientId, inet_ntoa(clientAddress.sin_addr), ntohs(clientAddress.sin_port));
    }
  }
  return 0;
}
