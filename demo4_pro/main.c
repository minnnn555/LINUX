#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <wait.h>

int main() {
    pid_t pid =fork();
//调用一次但返回两次：在父进程中返回子进程的PID（正整数），在子进程中返回0，创建失败时返回-1
    if(pid==0){
        //子进程代码
        printf("child pid =%d\n",getpid());
        usleep(5000*1000);//delay 5000us*1000=5s
    }
    else if(pid>0)
    {
        int status;
        waitpid(pid,&status,0);
        printf("stsatues=%d\n",status);
        //父进程代码
        printf("father pid =%d ,child pid =%d\n",getpid(),pid);
    }
    
    return 0;
}