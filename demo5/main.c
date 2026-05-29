#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // execl("/bin/ls","ls","-l","/home",NULL);
    execl("/home/min/work/demo1/hello","hello",NULL);
    return 0;
}