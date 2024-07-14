#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT signal %d\n", sig);
}

void handle_sigalrm(int sig) {
    printf("Caught SIGALRM signal %d\n", sig);
}

int main() {
    signal(SIGINT, handle_sigint);
    signal(SIGALRM, handle_sigalrm);

    alarm(5);  // Set an alarm for 5 seconds

    while (1) {
        sleep(1);
    }

    return 0;
}

