#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

struct msg_buffer
{
 long msg_type;
 char msg_text[200];
} message;

int main()
{
  key_t k;
  int mid;
  
  k = ftok("proglife",70);
  mid = msgget(k , 0666 | IPC_CREAT);
  msgrcv(mid , &message , sizeof(message) , 1,0);
  printf("Message Notified : %s \n", message.msg_text);
  msgctl(mid , IPC_RMID , NULL);
  
  return 0;
  }
  
