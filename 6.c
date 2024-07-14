#include <stdio.h>
#include <unistd.h>

int main() {
    #ifdef _POSIX_VERSION
        printf("POSIX version: %ld\n", _POSIX_VERSION);
    #else
        printf("POSIX version is not defined.\n");
    #endif
    return 0;
}

