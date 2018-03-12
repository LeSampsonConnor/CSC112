#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[]) {
    int keepGoing = 1;
    while (keepGoing) {
        //str = get user input from keyboard
        printf("> ");
        char userInput[40];
        fgets(userInput, sizeof(userInput), stdin);

        size_t ln = strlen(userInput)-1;
        if (userInput[ln] == '\n') {
            userInput[ln] = ' ';
        }
        // if str == “quit”, exit and terminate the program
        if (strcmp(userInput,"quit") == 0) break;
        // create the array for the command
        char start[] = "/bin/";
        strcat(start, userInput);

        char *cmd[] = {"/bin/", userInput, NULL};
        pid_t pid = fork();
        if (pid < 0 ) {
            perror("error");
            exit(1);
        }
        if (pid==0) { // Child process
            // call execve on the user command
            execv(cmd[0], cmd);
        } else {
            // wait for the child process to finish
            wait(NULL);
        }
    }
    return 0;
}
