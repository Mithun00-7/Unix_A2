#include <iostream>
#include <unistd.h>
#include <cstring>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello from parent";
    char read_msg[100];

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
        read(fd[0], read_msg, sizeof(read_msg));
        std::cout << "Child received: " << read_msg << std::endl;
        close(fd[0]);
    } else {  // Parent process
        close(fd[0]);  // Close reading end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }

    return 0;
}

