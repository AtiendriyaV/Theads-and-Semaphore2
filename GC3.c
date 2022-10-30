 #include <stdio.h> 
 #include <sys/wait.h>
 #include <time.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>

  
  int main(int argc , char *argv[])
 
  {
  time_t t;
  int status;
  int a = fork();
  int b = fork();
  int pid1,pid2,pid3,pid4;
  {
  if(pid1 = (a > 0 && b > 0))
  {
  printf("welcome to Parent process\n ");
  printf("process id of a and b is : %d %d \n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  }
  if(pid2 = (a == 0 && b > 0))
  {
  printf("welcome child1 process\n");
  printf("Process id of a and b is : %d %d\n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  sleep(2);
  pid2 = wait(NULL);
  printf("CT: child has terminated\n");
  printf("PID of ex1.c = %d\n" , getpid());
  char *args[] = {"helllo" , "boss" , "goodevening" , NULL};
  fork();
  execv("./ex2",args);
  printf("back to ex1.c");
  exit(0);
  exit(0);
  }
 if(pid3 = (a > 0 && b == 0))
  {
  printf("welcome child2 process \n");
  printf("process id of a and b is : %d %d \n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  pid3 = wait(NULL);
  printf("CT: child has terminated\n");
  exit(0);
  }
  if(pid4 = (a == 0 && b == 0))
  {
  printf("welcome child3 process\n");
  printf("process id of a and b is : %d %d \n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  pid4 = wait(NULL);
  printf("CT: child has terminated\n");
  }
  }
  
   
 
  /*
   if(pid != 0){
   time(&t);
  printf("main process (pid %d) stoped at %s", (int) getpid(), ctime(&t));
  /*
   
   printf("main process termminated\n");
   
   }
   */ 
  /*
 {
 fork();
 printf("PID of ex1.c = %d\n" , getpid());
 char *args[] = {"helllo" , "boss" , "goodevening" , NULL};
 fork();
 execv("./ex2",args);
 printf("back to ex1.c");
 exit(0);
 }
 
*/ 
   printf("\n");
    return 0;
  
 }
