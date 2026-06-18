#include "log.h"

void log_info(const char* msg)
{
    if (msg == NULL)
        return;
    printf("[INFO] %s\n", msg);
}

void log_error(const char* msg)
{
    if (msg == NULL)
        return;
    printf("[ERROR] %s\n", msg);
}