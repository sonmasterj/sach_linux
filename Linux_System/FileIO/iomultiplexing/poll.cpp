#include <iostream>
#include <fstream>
#include<unistd.h>
#include<sys/poll.h>
#define TIMEOUT 5
int main(int argc, char const *argv[])
{
    struct pollfd fd[2];
    int ret=-1;
    fd[0].fd=STDIN_FILENO;
    fd[0].events=POLLIN;
    //
    fd[1].fd=STDOUT_FILENO;
    fd[1].events=POLLOUT;
    ret=poll(fd,2,TIMEOUT*1000);
    if(ret==-1){
        perror("error poll");
        return -1;
    }
    if(ret==0){
        printf("time out");
    }
    if(fd[0].revents&POLLIN)
    {
        printf("stdin san sang doc");
    }
    if(fd[1].revents & POLLOUT){
        printf("san sang ghi");
    }
}
