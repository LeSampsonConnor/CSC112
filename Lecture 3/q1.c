#include <stdio.h>

int main(int argc, char const *argv[]) {
    printf("Hello1\n");   /* LINE A */
    if (fork == 0) {
        printf("hello2\n"); /* LINE B*/
        if (fork() == 0) {
            printf("hello3\n");  /* LINE C */
            fork();
        }
    }
    printf("Bye\n"); /* LINE D */
    return 0;
}
