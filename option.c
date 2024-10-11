#include <stdio.h>
#include <stdint.h>

#include "main.h"
#include "option.h"


errorEvent_t touch(const char *name, flags8_t opFlags) {
    FILE *fp = fopen(name, "r+");
    if(fp == NULL) {
        // The 'c' prevents the file from being created
        if(opFlags.has_c || (fp = fopen(name, "w")) == NULL)
            return errorHandler(ERROR_FILE, name);
    }

    fclose(fp);

    return 0;
}
