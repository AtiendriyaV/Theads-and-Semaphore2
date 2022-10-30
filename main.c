#include<stdio.h>
#include<unistd.h>
#include<error.h>
#include<sys/utsname.h>

int main(int argc, char *argv[])
{
int flag,e;
struct utsname name;

flag=uname(&name);

if(flag == -1)
{
error(1,e,"not working");
}
write(1,name.sysname,10);
return 0;
}
