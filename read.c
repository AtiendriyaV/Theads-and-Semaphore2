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
	char *buf, temp[25];
	int sid,val;
	int *data;
	
	key_t key = ftok("shmfile",5);
	

	sid = shmget(key,1024,0666|IPC_CREAT);

	if (sid == -1)
	{
		write (1,"Shared memory Access Error",25);
		exit(0);
	} 
	 
	 key_t k = 100;	
 	struct  sembuf p1;
	time_t t;
		
	sid= semget(k, 1, IPC_CREAT|0777);
	if (sid ==-1 )
	{
		write(1, "Refer Error", 11);
		exit(0);
	}	
	
			
	while (1)
	{
		
		buf = (char*) shmat(sid,(void*)0,0);
	         val=write(1,buf,10);
		write(1,"Shared memory Details",20);
		
		p1.sem_num=0;  /* semaphore number */
		p1.sem_op=+1;   /* semaphore operation */
		p1.sem_flg=0;  /* operation flags */
		
		write(1,"\n",1);		
		write(1,"=====In Exit====", 17);
		write(1,"\n",1);
		exit(0);
		}
   
		val=semop(sid,&p1,1);
		
		if (val ==-1 )
		{
			write(1, "Signal operation Failed", 24);
			exit(0);
		}
		
		write(1,"\n",1);
		val= semctl(sid,0, GETVAL, NULL);
		write(1,"Semaphore value : ",19);
	
	val = shmdt(buf);
	if (val == -1)
	{
		write (1,"Shared memory Detach Error", 26);
		exit(0);
	}
	return 0;
}
