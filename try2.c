#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>
#include <error.h>

int main(int argc, char *argv[])
{

int a,e,T;
struct passwd* flag;

flag=getpwuid(getuid() == T) ;

if(a == -1)
{
error(1,e,"not working");
}
printf("UID %d\n", flag-> pw_gid);
return 0;
}
