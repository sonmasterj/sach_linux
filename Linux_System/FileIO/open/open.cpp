#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <fstream>
char buf_read1[8],buf_read2[20];
int pos;
int main(int argc, char const *argv[])
{
    char buf1[20],buf2[6];
    int num,fd;
    fd=open("a.txt",O_RDWR|O_APPEND);
    if(fd==-1)
    {
        perror("open failed");
        return -1;
    }
    num=read(fd,buf_read1,7);
    buf_read1[num]='\0';
    printf("chuoi ban dau: %s",buf_read1);
    pos=lseek(fd,0,SEEK_CUR);
    printf(" vi tri offset hien tai: %d",pos);
    if(write(fd,"son",3)==-1){
        perror("write failed");
        return -1;
    }
    lseek(fd,0,SEEK_SET);
    num=read(fd,buf_read2,20);
    if(num==-1){
        perror("read failed");
        return -1;
    }
    buf_read2[num]='\0';
    printf("chuoi luc sau: %s",buf_read2);
    close(fd);
    return 0;
}
