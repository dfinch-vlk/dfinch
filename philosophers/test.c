#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

void take_l1(void)
{
    pthread_mutex_lock(&mutex);
    printf("has taken a fork\n");
    sleep(1);
    pthread_mutex_unlock(&mutex);
}

void take_l2(void)
{
    pthread_mutex_lock(&mutex);
    printf("has taken a fork\n");
    sleep(1);
    pthread_mutex_unlock(&mutex);
}

void eating(void)
{
    pthread_mutex_lock(&mutex);
    printf("is eating\n");
    sleep(5);
    pthread_mutex_unlock(&mutex);
}

void sleeping(void)
{
    pthread_mutex_lock(&mutex);
    printf("sleeping\n");
    sleep(5);
    pthread_mutex_unlock(&mutex);
}

void* helloWorld(void *args) {
    take_l1();
    take_l2();
    eating();
    sleeping();
    return ("hello");
}
 
int main() {
    pthread_t thread[2];

    pthread_mutex_init(&mutex, NULL);
    pthread_create(&thread[0], NULL, helloWorld, NULL);
    pthread_create(&thread[1], NULL, helloWorld, NULL);
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}