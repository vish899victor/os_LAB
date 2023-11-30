#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

sem_t chopstick[5];
void *philo(void *arg){
    long int num = (long int) arg;
    printf("Philosopher %ld is thinking\n",num);
    printf("Philosopher %ld wants to eat\n",num);
    printf("Philosopher %ld tries to pick left chopstick\n",num);

    //Enters the CS 
    sem_wait(&chopstick[num]);

    printf("Philosopher %ld picks left chopstick\n",num);
    printf("Philosopher %ld tries to pick right chopstick\n",num);

    sem_wait(&chopstick[(num+1)%5]);
    
    printf("Philosopher %ld picks right chopstick\n",num);

    //eat the food
    printf("Philosopher %ld is eating\n",num);
    sleep(2);

    //finish eating
    printf("Philosopher %ld finished eating\n",num);
    
    sem_post(&chopstick[(num+1)%5]);
    printf("Philosopher %ld leaves right chopstick\n",num);

    sem_post(&chopstick[num]);
    printf("Philosopher %ld leaves left chopstick\n",num);

}

int main(){
    long int i ;
    int n[5];
    pthread_t p[5];
    
    for(i=0;i<5;i++)
        sem_init(&chopstick[i],0,1);

    for(i=0;i<5;i++)
        pthread_create(&p[i],NULL,philo,(void *)i);
    
    for(i=0;i<5;i++)
        pthread_join(p[i],NULL);

return 0;
}