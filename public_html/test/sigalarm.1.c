#include <stdio.h>
#include <stdib.h> /* exit */
#include <unistd.h>
#include <signal.h>
 
void sigcatch(int);
 
int main() {
 
    /* Set handler to SIGALRM */
    if (SIG_ERR == signal(SIGALRM, sigcatch)) {
        printf("failed to set signal handler.\n");
    }
 
    /* 5 seconds after, send signal */
    alarm(5);

    while (1) {
    }

    return 0;
}
 
void sigcatch(int sig) {
    printf("catch signal %d\n", sig);

    if (sig == SIGALRM) {
        printf("catch SIGALRM and exit.\n");
        exit(1);
    }
}