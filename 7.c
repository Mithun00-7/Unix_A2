#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main() {
    printf("Supplemental groups: %ld\n", sysconf(_SC_NGROUPS_MAX));
    printf("Maximum number of links of a file: %ld\n", _POSIX_LINK_MAX);
    printf("Maximum number of simultaneous asynchronous I/O: %ld\n", sysconf(_SC_AIO_MAX));
    printf("Real signals: %ld\n", sysconf(_SC_RTSIG_MAX));
    return 0;
}

