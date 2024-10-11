#ifndef __TOUCH_OPTION_H__
#define __TOUCH_OPTION_H__


#include <utime.h>

#include "main.h"


// OPTION FLAGS

#define has_a flags.flag0
#define has_c flags.flag1
#define has_m flags.flag2


// Modifies the time of the file
// Can return ERROR_FILE and ERROR_FTIME
errorEvent_t touch(const char *_File, time_t _Time, flags8_t _OptionFlags);


#endif
