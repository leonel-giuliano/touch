#include <stdio.h>
#include <unistd.h>
#include <utime.h>
#include <time.h>
#include <stdint.h>

#include "main.h"
#include "option.h"


errorEvent_t touch(const char *name, time_t t, flags8_t opFlags) {
    if((access(name, F_OK)) == -1) {
        FILE *fp = NULL;

        // The 'c' option doesn't create the file
        if(opFlags.has_c || (fp = fopen(name, "w")) == NULL)
            return errorHandler(ERROR_FILE, name);

        fclose(fp);
    }

    struct utimbuf fpTime;

    // Modify the time depending on the options or keep it
    fpTime.actime = (opFlags.has_a || !opFlags.has_m) ? t : -1;
    fpTime.modtime = (opFlags.has_m || !opFlags.has_a) ? t : -1;

    if(utime(name, &fpTime) == -1)
        return errorHandler(ERROR_FTIME);

    return 0;
}
