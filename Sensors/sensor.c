#include "sensor.h"

int check_sensor_recursive(int retires_left){
    
    int sensor_status = rand() % 2;
    
    if (sensor_status == 1)
        return 1;
    else {
        if (retires_left > 0){
            printf("[WARN] connection loss, try to connect... remaining %d times\n", retires_left);
            return check_sensor_recursive(retires_left - 1);
        }
        else {
            printf("[CRITICAL] Out of retries! Initiating Emergency Bailout....\n");
            longjmp(emergency_env, 99);
        }
    }
}