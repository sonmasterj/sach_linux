#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int status;
    pid_t pid,childpid;
    childpid=fork();
    switch(childpid){
        case -1:
            printf("erro fork\n");
            return -1;
        case 0:
            return 1;
            //abort();
        default:
            pid=wait(&status);
            if(pid==-1)
            {
                printf("print error wait");
            }
            printf("pid=%d",pid);
            if(WIFEXITED(status)){
                printf("thoat binh thuong %d\n",status);
            }
            if(WIFSIGNALED(status)){
                printf("kill by signal=%d\n",WTERMSIG(status));
            }
    }

    return 0;
}
