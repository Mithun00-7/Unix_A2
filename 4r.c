 #include <stdio.h>
 #include <fcntl.h>
 #include <unistd.h>
 #define FIFO_FILE "my_fifo"
 #define BUFFER_SIZE 256
 int main() {
 int fd;
 char buffer[BUFFER_SIZE];
 fd = open(FIFO_FILE, O_RDONLY);
 read(fd, buffer, BUFFER_SIZE);
 printf("Reader: Message read from FIFO: %s\n", buffer);
 close(fd);
 unlink(FIFO_FILE);
 return 0;
 }

