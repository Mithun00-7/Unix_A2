#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int sig) {
    printf("Alarm received!\n");
}

int main() {
    signal(SIGALRM, alarm_handler);

    printf("Setting alarm for 5 seconds...\n");
    alarm(5);

    pause();  // Wait for signal

    printf("Alarm expired\n");
    return 0;
}

