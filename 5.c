 #include <stdio.h>
 #include <unistd.h>
 int main() {
 printf("Number of clock ticks: %ld\n", sysconf(_SC_CLK_TCK));
 printf("Maximum number of child processes: %ld\n",
 sysconf(_SC_CHILD_MAX));
 printf("Maximum path length: %ld\n", pathconf("/", _PC_PATH_MAX));
 printf("Maximum number of open files per process: %ld\n",
 sysconf(_SC_OPEN_MAX));
 return 0;
 }
