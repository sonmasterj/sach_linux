#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sys/time.h>
#include <sys/types.h>
using namespace std;
#define TIMEOUT 5
#define BUFF_LEN 1024
int main(int argc, char const *argv[])
{
    /* code */
    struct  timeval tv;
    tv.tv_sec=TIMEOUT;
    tv.tv_usec=0;
    int ret=-1;
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO,&readfds);
    ret=select(2,&readfds,NULL,NULL,&tv);
    if(ret==-1)
    {
        perror("select error");
        return -1;
    }
    else if(ret==0){
        printf("time out\n");
        return 0;
    }
    if(FD_ISSET(STDIN_FILENO,&readfds)){
        char buf[BUFF_LEN];
        int len=-1;
        len=read(STDIN_FILENO,buf,BUFF_LEN);
        if(len==-1)
        {
            perror("read error");
            return -1;
        }
        else
        {
            buf[len]='\0';
            printf("read file : %s",buf);
           
        }
         return 0;
    }
    
    return 1;
}
