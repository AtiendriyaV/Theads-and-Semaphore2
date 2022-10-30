#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

struct msg_buffer
{
 long msg_type;
 char msg_txt[200];
} message;

int main()
{
  key_t k;
  int mid;
  
  k = ftok("proglife",200);
  mid = msgget(k , 0666 | IPC_CREAT);
  message.msg_type = 1;
  printf("Write message to be passed:");
  fgets(message.msg_txt,MAX,stdin);
  msgsnd(mid ,&message , sizeof(message),0);
  printf("message to be passed is : %s \n", message.msg_txt);
  
  return 0;
  }
  
