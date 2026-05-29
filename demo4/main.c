#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    typedef struct informatian{
        char name[20];
        char id[10];
        char password[20];
    }inf;
    inf Information1 ={"min","aa","abc"};
    inf Information2;
    // char writebuf[]="hello world";
    // char readbuf[100];
    ssize_t bytesw ;
    ssize_t bytesr ;
    //open
   FILE *fd=fopen("example.txt","w+");
   if(fd==NULL){
    printf("open fail\n");
    return -1;
   }
   //write
    bytesw = fwrite( &Information1, sizeof(inf), 1,fd);
    if(bytesw!=1)
    {
        printf("write fail\n");
        fclose(fd);
        return -1;
    }
        
    if(fseek(fd,0,SEEK_SET)==-1)
    {
        printf("lseek fail\n");
    }
    //read
    bytesr = fread(&Information2, sizeof(inf), 1, fd );
        Information2.name[sizeof(Information2.name) - 1] = '\0';      // name[19] = '\0'
        Information2.id[sizeof(Information2.id) - 1] = '\0';          // id[9] = '\0'
        Information2.password[sizeof(Information2.password) - 1] = '\0'; // password[19] = '\0'
    if(bytesr>0){
        
        printf("read successfully\n");
        printf("read data name = %s\n",Information2.name);
        printf("read data id= %s\n",Information2.id);
        printf("read data password = %s\n",Information2.password);
    }
    else
    {
        printf("read fail\n");
        fclose(fd);
        return -1;
    }
    fclose(fd);
    return 0;
}