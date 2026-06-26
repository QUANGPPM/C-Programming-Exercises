#ifndef DISPATCHER_H
#define DISPATCHER_H
#ifdef __cplusplus__
extern "C" {
#endif
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    CMD_BRAKE = 0,
    CMD_SET_VELOCITY,
    CMD_SET_PID,
    TOTAL_CMD
}Command;
/**
 * brake: no argument
 * set_velocity: float vel
 * set_pid: float kp, ki, kd
 */
void execute_command(Command cmd_id, ...);

#ifdef __cplusplus__
}
#endif
#endif