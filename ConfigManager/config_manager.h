#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H

#include "global_config.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

int load_config(const char* filepath, DriveConfig** config_ptr);
void sync_config(DriveConfig* config_ptr);

#endif