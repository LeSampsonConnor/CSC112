#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    if (argv[1] == NULL) {
        perror("You must provide the path to a file");
        exit(-1);
    }

    char *cmd[] = {"/usr/bin/wc", argv[1], NULL};
    pid_t pid = fork();
    if (pid == 0) { // child process
        execv(cmd[0], cmd);
    } else { //parent process
        printf("The wc utility displays the number of lines, words, and bytes contained\nin each input file, or standard input (if no file is specified) to the\nstandard output. A line is defined as a string of characters delimited\nby a character.  Characters beyond the final character will not be included\nin the line count.\n");
        wait(NULL);
    }
    return 0;
}
