#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

pthread_mutex_t mutexFuel;
pthread_cond_t condFuel;

int fuel = 0;

void* fuel_filling(void* arg) 
{
    for (int i = 0; i <6; i++) 
    {
        pthread_mutex_lock(&mutexFuel);
        fuel += 15;
        printf("FUEL Thread ID %ld : \n", pthread_self());
        printf("...... Filled fuel... %d\n", fuel);
        pthread_mutex_unlock(&mutexFuel);
        pthread_cond_signal(&condFuel);
        sleep(3);
    }
}

void* car(void* arg) 
{
    pthread_mutex_lock(&mutexFuel);
    while (fuel < 50) 
    {
        printf("CAR : While (fuel < 40)...........................\n");
        printf("CAR Thread ID %ld : No fuel. Waiting...\n", pthread_self());
        pthread_cond_wait(&condFuel, &mutexFuel);
        printf("CAR : Notified to FUEL Thread......................\n");
       
    }
    fuel = fuel-50;
    printf(" CAR Thread : Got fuel. Now fuel left with : %d\n", fuel);
    pthread_mutex_unlock(&mutexFuel);
}

int main(int argc, char* argv[]) 
{
    pthread_t th[2];
    pthread_mutex_init(&mutexFuel, NULL);
    pthread_cond_init(&condFuel, NULL);

    for (int i = 0; i < 2; i++) 
    {
        if (i == 1) 
        {
            if (pthread_create(&th[i], NULL, &fuel_filling, NULL) != 0) 
            {
                perror("Failed to create thread");
            }
        } 
        else 
        {
            if (pthread_create(&th[i], NULL, &car, NULL) != 0) 
            {
                perror("Failed to create thread");
            }
        }
    }

    for (int i = 0; i < 2; i++) 
    {
        if (pthread_join(th[i], NULL) != 0) 
        {
            perror("Failed to join thread");
        }
        else
        {
          printf("=======================================\n");
	  printf("Thread ID : %ld is Attached to main\n", th[i]);
	  printf("======================================\n");
        }  
    }

    pthread_mutex_destroy(&mutexFuel);
    pthread_cond_destroy(&condFuel);
    return 0;
}


