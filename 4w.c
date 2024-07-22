 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/stat.h>
 #include <unistd.h>
 #include <string.h>
 #define FIFO_FILE "my_fifo"
 int main() {
 int fd;
 const char *message = "Hello from the writer process!";
 mkfifo(FIFO_FILE, 0666);
 fd = open(FIFO_FILE, O_WRONLY);
 write(fd, message, strlen(message) + 1);
 close(fd);
 return 0;
 }
