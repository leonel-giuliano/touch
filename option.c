#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#include "main.h"
#include "option.h"


errorEvent_t touch(const char *name, flags8_t opFlags) {
    if((access(name, F_OK)) == -1) {
        FILE *fp;

        // The 'c' option doesn't create the file
        if(opFlags.has_c || (fp = fopen(name, "w")) == NULL)
            return errorHandler(ERROR_FILE);

        fclose(fp);
    }

    return 0;
}
