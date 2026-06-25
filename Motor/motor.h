#ifndef MOTOR_H
#define MOTOR_H

#ifdef __cplusplus
extern "C" {
#endif
#include "global_config.h"
// fsm:
typedef enum {
    STATE_INIT,
    STATE_IDLE,
    STATE_RUNNING,
    STATE_FAULT
}MotorState;

typedef enum {
    CMD_START = 1,
    CMD_IDLE,
    CMD_RUNNING,
    CMD_CLEAR_FAULT
}MotorCommand;

void motor_init(void);
void motor_request_start(void);
void motor_request_stop(void);
void motor_request_set_fault(void);
void motor_request_clear_fault(void);
void motor_update(void);
MotorState motor_get_satte(void);


#ifdef __cplusplus
}
#endif

#endif