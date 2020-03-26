#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
char name[20];
void *printhello(void* argv){
    char  *c=(char*)argv;
    printf("hello from thread by %s\n",c);
    pthread_exit(NULL);
}
int main(void) {
    strncpy(name,"cong son",20);
    pthread_t thread;
    int ret=pthread_create(&thread,NULL,printhello,&name);
    if(ret){
        perror("creat thread failed\n");

    }
    printf("hello from main\n");
    pthread_join(thread,NULL);
    return 0;
}