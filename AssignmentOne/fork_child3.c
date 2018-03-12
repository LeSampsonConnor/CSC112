#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    printf("in main process.\n");
    pid_t pid = fork();
    if (pid < 0) {
        perror("error");
        exit(-1);
    }
    if (pid == 0) { //child process
        if (pid == 0) { // child process two
            printf("in child process 2\n");
        }
            printf("in child process 1\n");
    } else {
        printf("end of main process\n");
    }
    return 0;
}
