#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include <signal.h>

#define N 5
#define THINKING 0 
#define HUNGRY 1 
#define EATING 2 
#define LEFT (i+4)%N
#define RIGHT (i+1)%N

#define think() sleep(1)
#define eat() sleep(1)

#define up sem_post
#define down sem_wait

void *philosopher(void *num);
void take_forks(int);
void put_forks(int);
void test(int);

typedef sem_t semaphore;
semaphore mutex;
semaphore S[N]; //inicializacao do semáforo
int state[N];
int nPhilosopher[N]={ 0,1,2,3,4 }; /* armazena os "filosofos" */

void *philosopher(void *num)
{
   while(1)
   {
      int *i = num;
      think();
      take_forks(*i);
      eat();
      put_forks(*i);
   }
}

void take_forks(int i)
{
   down(&mutex);
   state[i] = HUNGRY;
   printf("Filosofo %d tem fome.\n", i+1);
   test(i);
   up(&mutex);
   down(&S[i]);
   sleep(1);
}

void put_forks(int i)
{
   down(&mutex);
   state[i]=THINKING;
   printf("Filosofo %d deixou os garfos %d e %d.\n", i+1, LEFT+1, i+1);
   printf("Filosofo %d pensando.\n", i+1);
   test(LEFT);
   test(RIGHT);
   up(&mutex);
}

void test(int i)
{
   if(state[i]==HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
   {
      state[i]=EATING;
      eat();
      printf("Filosofo %d agarrou os garfos %d e %d.\n", i+1, LEFT+1, i+1);
      printf("Filosofo %d comendo.\n", i+1);
      up(&S[i]);
   }
}

int main() {
   int i;
   pthread_t thread_id[N]; /* identificadores das threads */
   sem_init(&mutex,0,1);
   
   for(i=0;i<N;i++)
      sem_init(&S[i],0,0);
      
   for(i=0;i<N;i++)
   {
      pthread_create(&thread_id[i], NULL, philosopher, (void *)&nPhilosopher[i]);
      //criar as threads
      printf("Filosofo %d esta a pensar.\n",i+1);
   }
   
   for(i=0;i<N;i++)
   pthread_join(thread_id[i],NULL); /* Esperara a junção das threads */ 
   return(0);
}