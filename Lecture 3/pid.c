#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

// Define BUFSIZE 1024
int main(int argc, char const *argv[]) {
    int c;

    pid_t pid = getpid(); /* get current processes*/
    printf("My pid: %d\n", pid);
    c = fgetc(stdin);
    exit(0);
}
