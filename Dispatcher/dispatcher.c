#include "dispatcher.h"

typedef void (*CommandFunc)(va_list agrs);

static void cmd_brake(va_list agrs){
    (void)agrs;
    printf("brake!!!!\n");

}
static void cmd_set_velocity(va_list agrs){
    double vel = va_arg(agrs, double);
    printf("Set velocity: %0.2f\n", vel);

}
static void cmd_set_pid(va_list agrs){
    double kp = va_arg(agrs, double);
    double ki = va_arg(agrs, double);
    double kd = va_arg(agrs, double);
    printf("Set pid: p=%0.2f, i=%0.2f, d=%0.2f\n", kp, ki, kd);
}

CommandFunc command_table[] = {
    cmd_brake,
    cmd_set_velocity,
    cmd_set_pid
};

void execute_command(Command cmd_id, ...){
    if(cmd_id < CMD_BRAKE || cmd_id >= TOTAL_CMD){
        //log here
        printf("Error: This command don't exist\n");
        return;
    }

    va_list agrs;
    va_start(agrs, cmd_id);
    command_table[(int)cmd_id](agrs);

    va_end(agrs);
}