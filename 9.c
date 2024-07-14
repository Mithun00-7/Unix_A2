#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char buffer[20];
    const char *msg = "hello world";

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {  // Child process
        close(fd[1]);  // Close writing end
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {  // Parent process
        close(fd[0]);  // Close reading end
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    }

    return 0;
}

