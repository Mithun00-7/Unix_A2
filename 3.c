#include <unistd.h>
#include <errno.h>

struct posix_option {
    const char *name;
    int option;
} options[] = {
    {"_SC_ARG_MAX", _SC_ARG_MAX},
    {"_SC_CHILD_MAX", _SC_CHILD_MAX},
    {"_SC_HOST_NAME_MAX", _SC_HOST_NAME_MAX},
    {"_SC_LOGIN_NAME_MAX", _SC_LOGIN_NAME_MAX},
    {"_SC_NGROUPS_MAX", _SC_NGROUPS_MAX},
    {"_SC_OPEN_MAX", _SC_OPEN_MAX},
    {"_SC_PAGESIZE", _SC_PAGESIZE},
    {"_SC_RE_DUP_MAX", _SC_RE_DUP_MAX},
    {"_SC_STREAM_MAX", _SC_STREAM_MAX},
    {"_SC_TZNAME_MAX", _SC_TZNAME_MAX},
    {"_SC_VERSION", _SC_VERSION},
    {"_SC_2_VERSION", _SC_2_VERSION},
    {"_SC_2_C_BIND", _SC_2_C_BIND},
    {"_SC_2_C_DEV", _SC_2_C_DEV},
    {"_SC_2_SW_DEV", _SC_2_SW_DEV},
    {"_SC_2_LOCALEDEF", _SC_2_LOCALEDEF}
};

int main() {
    for (size_t i = 0; i < sizeof(options) / sizeof(options[0]); ++i) {
        errno = 0;  // Reset errno before each call
        long value = sysconf(options[i].option);
        if (value == -1) {
            if (errno == EINVAL) {
                printf("%s is not supported.\n", options[i].name);
            } else {
                perror("sysconf");
            }
        } else {
            printf("%s = %ld\n", options[i].name, value);
        }
    }
    return 0;
}

