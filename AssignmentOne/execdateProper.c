#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    char *cmd[] = {"/bin/date", "+%m/%d/%y", NULL};

    for (int i=0; i<=10; i++) {
        printf("%d\n", i);
            if (i==3) {
                if (fork() == 0) { // child process
                    execv(cmd[0], cmd); // LINE A
                    printf("Done!"); // LINE B: If execv fails
                    perror("execv");
                } else { // parent
                    wait(NULL);  // waiting for its child to finish
            }
        }
    }
    return 0;
}
