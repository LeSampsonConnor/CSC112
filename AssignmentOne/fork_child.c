#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
  printf ("in main process.\n");
  pid_t pid = fork();

  if (pid == 0) {
    printf("in child process 1\n");
  } else {
    printf("end of main process\n");
  }
}


/*
Question from handout:
(a) When fork() returns -1 what happens?: An error occured when trying to create
the procces
*/
