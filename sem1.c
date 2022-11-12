#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

void printInt(int val)
{
	char buf[6];
	int len;
	len =sprintf(buf," %d",val);
	write(1,buf,len);
}


int main(int argc, char *argv[])
{
	int len,val,i=0;
	int left,right,id;
	char buf[30];
	//a=0;
	//b=4;
	key_t k = 100;	 //key_t k
 	struct  sembuf p1;//declaration of semaphore structure 
 	
	time_t t;
		
	id= semget(k, 1, IPC_CREAT|0777);
	
	// id is variable declared to the int semget systemcall
	       //1 is number of semaphore to used //  
	       //checks the value of semaphore 0,1,-1//
	       // IPC_CREAT is the int flag value 
	
	if (id ==-1 ) //if semnum =-1 do this   
	{
		write(1, "Refer Error", 11);
		exit(0);
	}	
		
	while (1)   //jab tak 1 value hai tab tak ye operation hoga
	{
		// Entry section 
		write(1,"\n",1);		
		write(1,"=====In Entry====", 18);
		write(1,"\n",1);
		p1.sem_num=0;  /* semaphore number */
		p1.sem_op=+1;   /* semaphore operation */
		p1.sem_flg=0;  /* operation flags */
		val=semop(id,&p1,1);
		
		if (val == -1 )
		{
			write(1, "Wait operation Failed", 22);
			exit(0);
		}
		
		
		  //The semctl function is the catchall for various semaphore operations.
                //GETVAL is Return the value of semval for the member semnum 
                //i.e. return the value of semaphore for operation
                
                
		write(1,"\n",1);
		val= semctl(id,0, GETVAL, NULL);
		write(1,"Semaphore value : ",19);
		printInt(val);
		
		write(1,"\n",1);
		write(1,"In Critical section : ", 19);
		write(1,"\n",1);
		write(1,ctime(&t),15);
		write(1,"\n",1);
		
		sleep(rand()%3);	
		read(0,buf,1);
		
		//* for signal operation
		//semop atomically performs an array of operations on a semaphore set.
		//int semop(int semid, struct sembuf semoparray[], size_t nops);
        
		
		
		// Exit section 
		p1.sem_num=0;  /* semaphore number */
		p1.sem_op=1;   /* semaphore operation */
		p1.sem_flg=0;  /* operation flags */
		
		write(1,"\n",1);		
		write(1,"=====In Exit====", 17);
		write(1,"\n",1);
		
		val=semop(id,&p1,1);
		
		if (val ==-1 )
		{
			write(1, "Signal operation Failed", 24);
			exit(0);
		}
		
		write(1,"\n",1);
		val= semctl(id,0, GETVAL, NULL);
		write(1,"Semaphore value : ",19);
		printInt(val);	
			
	}
	
}
	
       
