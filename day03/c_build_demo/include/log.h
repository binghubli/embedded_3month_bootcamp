#ifndef LOG_H
#define LOG_H

#include "err_code.h"
#include <stdio.h>
#include <stddef.h>

void log_info(const char* msg);
void log_error(const char* msg);

#endif
