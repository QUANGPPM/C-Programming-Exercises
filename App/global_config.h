#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#include <stdio.h>
#include <stdint.h>
#include "logger.h"
#include <errno.h>

typedef struct __attribute__((packed)){
    float current_limit;
    float velocity_limit;
    int pole_pairs;
    uint8_t is_calibrated;
}DriveConfig;


#endif