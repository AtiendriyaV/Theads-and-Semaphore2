 #include <stdio.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <time.h>
 #include <string.h>
 

int main()
{
struct stat buf;
stat("",&buf);
char mtime[100];

printf("st_atime = %d\n", buf.st_atim);


strcpy(mtime,ctime(&buf.st_mtime));
printf("st_mtime = %s\n", buf.st_mtime);

 return 0;
 }
 
