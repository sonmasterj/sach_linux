#include <unistd.h>  
#include <sys/types.h>  
#include <errno.h>  
#include <stdio.h>  
#include <sys/wait.h>  
#include <stdlib.h>  
int main()  
{  
    pid_t child_pid;  
    int counter = 2;  
  
    printf("Gia tri khoi tao cua counter = %d\n", counter);  
  
    child_pid = fork();  
    if(child_pid >= 0)  
    {  
        if(0 == child_pid)  
        {  
            counter ++;  
            sleep(2);  
            printf("Day la tien trinh con, gia tri counter sau khi tang = %d\n", counter);  
            while(1);  
        }  
        else  
        {  
            counter ++;  
            sleep(2);  
            printf("Day la tien trinh cha, gia tri counter sau khi tang = %d\n", counter);  
            while(1);  
        }  
    }  
    else  
    {  
        printf("Tao process con khong thanh cong\n");  
    }  
      
    return 0;  
}  