#include <stdio.h>
#include <errno.h>
#include <stdarg.h>
#include <string.h>

#include "main.h"


errorEvent_t errorHandler(errorEvent_t e, ...) {
    va_list arg;
    va_start(arg, e);

    fprintf(stderr, "touch: ");

    switch (e) {
        case ERROR_FILE:
            fprintf(stderr, "cannot access '%s': %s\n", va_arg(arg, const char *), strerror(errno));
            break;

        case ERROR_FTIME:
            fprintf(stderr, "problem modifying the file time: %s\n", strerror(errno));
            break;
    }

    return e;
}
