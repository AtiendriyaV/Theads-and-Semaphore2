 #include <stdio.h> 
 #include <sys/wait.h>
 #include <time.h>
 #include <sys/types.h>
 #include <unistd.h>
 
  
 int main(int argc , char *argv[])
 
 {
  pid_t pid;
  time_t t;
  int status;
  int a = fork();
  int b = fork();
  
  if(a > 0 && b > 0)
  {
   printf("welcome to Parent process\n ");
  printf(" id of a and b is : %d %d \n" ,  a,b);
  
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  }
  else if(a == 0 && b > 0)
  {
  printf("welcome child1 process\n");
  printf(" id of a and b is : %d %d \n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  }
  else if(a > 0 && b ==0)
  {
  printf("welcome child2 process \n");
  printf(" id of a and b is : %d %d \n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  }
  else
  {
  printf("welcome child3 process\n");
  printf(" id of a and b is : %d %d \n" ,  a,b);
  printf("My is id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  printf("My parent id : (pid %d) started at %s \n", (int)    getpid(), ctime(&t));
  }
  
 /*
 int i;
 for (i = n; i<n+5; i++)
 {
  printf("No of process id : %d \n" , i);
  fflush(stdout);
 }
  
   if(pid != 0){
   time(&t);
  printf("main process (pid %d) stoped at %s", (int) getpid(), ctime(&t));
  
   
   printf("main process termminated\n");
   
   }
   */ 
 return 0;
  
 }
