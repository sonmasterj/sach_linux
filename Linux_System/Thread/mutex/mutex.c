#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#define NUM_THREAD 2
pthread_t thr[NUM_THREAD];
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
int counter=0;
void *thread(void *argv){
    pthread_mutex_lock(&mutex);
    counter++;
    printf("thread %d start\n",counter);
    sleep(1);
    printf("thread %d finished\n",counter);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}
int main(int argc, char const *argv[])
{
    for(int i=0;i<NUM_THREAD;i++){
        int ret=pthread_create(&thr[i],NULL,thread,NULL);
        if(ret){
            perror("creat thread failed\n");
        }
    }
    printf("hello from main\n");
    pthread_join(thr[0],NULL);
    pthread_join(thr[1],NULL);
    return 0;
}
