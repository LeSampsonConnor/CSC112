#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    char *cmd[] = {"/bin/date", "+%m/%d/%y", NULL};

    for (int i=0; i<=10; i++) {
        printf("%d\n", i);
        if (i==3) {
            execv(cmd[0], cmd); // LINE A
            printf("Done!"); // LINE B: If execv fails
            perror("execv");
        } // for loop does not continue because execv calls a new child  with its own
        // code to keep it you need to use a combination of fork() and wait(). The
        // only time the Line be will be reached is if the exec comand fails

    }
    return 0;
}
