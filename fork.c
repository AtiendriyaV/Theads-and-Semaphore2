#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{

 fork(); //create child process and parent process
 fork();
 fork();
 printf("hello boss \n PID = %d\n" , getpid()); //processid
 
 return 0;

}
