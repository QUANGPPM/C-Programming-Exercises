#ifndef SENSOR_H
#define SENSOR_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>

extern jmp_buf emergency_env;
int check_sensor_recursive(int retires_left);


#ifdef __cplusplus
}
#endif
#endif