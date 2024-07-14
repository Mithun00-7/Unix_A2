#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_NAME "myfifo"
#define BUFFER_SIZE 300

void writer() {
    int fd;
    char buffer[BUFFER_SIZE] = "Hello from writer!";
    mkfifo(FIFO_NAME, 0666);
    fd = open(FIFO_NAME, O_WRONLY);
    write(fd, buffer, sizeof(buffer));
    close(fd);
}

void reader() {
    int fd;
    char buffer[BUFFER_SIZE];
    fd = open(FIFO_NAME, O_RDONLY);
    read(fd, buffer, BUFFER_SIZE);
    printf("Reader received: %s\n", buffer);
    close(fd);
}

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        reader();
    } else {
        writer();
    }
    return 0;
}

