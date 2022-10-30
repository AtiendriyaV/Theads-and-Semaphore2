#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <error.h>
#include <sys/time.h>

int main(int argc, char *argv[])

{
 time_t t;
 struct tm *tmp;
 char buf1[64];
 time(&t); 
 tmp = localtime(&t);
 
 if (strftime(buf1, 64, "time and date: %R", tmp) == 0)
 printf("buffer length 64 is too small\n");
 else
 printf("%s\n", buf1);
  exit(0);
 return 0;
 }
