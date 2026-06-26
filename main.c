#include "dispatcher.h"


int main(){
    execute_command(CMD_BRAKE);
    execute_command(CMD_SET_VELOCITY, 20.0);
    execute_command(CMD_SET_PID, 1.0, 2.0, 5.0);
    execute_command(5, 1.0, 2.0, 5.0);
    return 0;
}