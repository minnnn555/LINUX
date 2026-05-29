#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    char writebuf[]="hello world";
    char readbuf[100];
    ssize_t bytesw ;
    ssize_t bytesr ;
    //open
   int fd=open("example.txt", O_RDWR|O_CREAT,0644);
   if(fd==-1){
    printf("open fail\n");
    return -1;
   }
   //write
    bytesw = write(fd ,writebuf , strlen(writebuf));
    if(bytesw==-1)
    {
        printf("write fail\n");
        close(fd);
        return -1;
    }
        printf("write successfully %ld\n",bytesw);
    if(lseek(fd,0,SEEK_SET)==-1)
    {
        printf("lseek fail\n");
    }
    //read
    bytesr = read(fd, readbuf, 100 );
    if(bytesr==-1)
    {
        printf("read fail\n");
        close(fd);
        return -1;
    }
    readbuf[bytesr]='\0';
    printf("read successfully %ld\n",bytesr);
    printf("read data = %s\n",readbuf);
    close(fd);
    return 0;
}