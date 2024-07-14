#include<iostream>
#include <unistd.h>

int main() {
    std::cout << "Maximum number of child processes: " << sysconf(_SC_CHILD_MAX) << std::endl;
    std::cout << "Maximum number of files that can be opened simultaneously: " << sysconf(_SC_OPEN_MAX) << std::endl;
    std::cout << "Maximum number of message queues: " << sysconf(_SC_MQ_OPEN_MAX) << std::endl;
    return 0;
}

