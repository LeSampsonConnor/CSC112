#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    printf("Parent running.\n");
    pid_t pid = fork();
    if (pid < 0) {
        perror("error");
        exit(-1);
    }
    if (pid == 0) { //child process one
        if (fork() == 0) { // child process two
            printf("Second child running\n");
        } else { // Parent of proccess two (ie process one)
            printf("Parent running after second fork\n");
            printf("First child running\n");
            wait(NULL); // wait for child process two to join its parent
            printf("First child done\n");
        }
    } else { // Parent of child one
        printf("Parent running after first fork\n");
        wait(NULL); // Wait for child procces one to join with its parent
        printf("Second child done\n");
        printf("Parent done.\n");
    }
    return 0;
}
