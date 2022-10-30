#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include<stdlib.h>
#include <stdio.h>
#include <sys/sem.h>
#include<time.h>
#include<math.h>

int main()
{
	char *buf, temp[30];
	key_t key = ftok("shmfile",100);
	int len,sid,val,i=0;
	int left,right,id;
	len =sprintf(temp," %d",val);
	write(1,temp,len);

	
	struct  sembuf p1;
	time_t t;
	
         
        sid= semget(key, 1, IPC_CREAT|0777);
	sid = shmget(key,1024,0666|IPC_CREAT);

	if (sid == -1)
	{
		write (1,"Shared memory Create Error",25);
		exit(0);
	}
			
	while (1)
	{
 
		write(1,"\n",1);		
		write(1,"enter to the sema", 18);
		write(1,"\n",1);
		p1.sem_num=0;  
		p1.sem_op=-1;   
		p1.sem_flg=0;  
		val=semop(id,&p1,1);
		
		if (val == -1 )
		{
			write(1, "Wait operation Failed", 22);
			exit(0);
		}

 	        write(1,"Enter details to shared memory",20);
	        val=read(0,buf,20);
         	write(1,"Details updated in shared memory",20);
         	
		write(1,ctime(&t),15);
			
		read(0,buf,1);
	
		val=semop(id,&p1,1);
		
		if (val ==-1 )
		{
			write(1, "Signal operation Failed", 24);
			exit(0);
		}
		
		write(1,"\n",1);
		val= semctl(id,0, GETVAL, NULL);
		write(1,"Semaphore value : ",19);
		
	
	if (val == -1)
	{
		write (1,"Shared memory Detach Error",15);
		exit(0);
	}
	return 0;
}
}

