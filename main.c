#include "dispatcher.h"
#include "sensor.h"

jmp_buf emergency_env;

int main(){
    // part 1: function pointer
    execute_command(CMD_BRAKE);
    execute_command(CMD_SET_VELOCITY, 20.0);
    execute_command(CMD_SET_PID, 1.0, 2.0, 5.0);
    execute_command(5, 1.0, 2.0, 5.0);

    // part 2: recursive & setjmp/longjmp
    srand((unsigned int)time(NULL));
    int jump_result = setjmp(emergency_env);
    if(jump_result == 0){
        printf("System Check: Checking sensor communication status...\n");
        int success = check_sensor_recursive(1);
        if(success){
            printf("[OK] Sensor connected!!\n");
        }
    } else{
        printf("[FATAL] Can't connect to Sensor\n");
    }

    return 0;
}