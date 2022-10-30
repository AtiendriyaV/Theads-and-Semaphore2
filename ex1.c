#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc , char *argv[])
{
 fork();
 printf("PID of ex1.c = %d\n" , getpid());
 char *args[] = {"helllo" , "boss" , "goodevening" , NULL};
 fork();
 execv("./ex2",args);
 printf("back to ex1.c");
 

 return 0;

}
