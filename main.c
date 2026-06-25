#include <stdlib.h>
#include "motor.h"

static const char* TAG = "PROGRAM";

void motor_control(MotorCommand choice){
    switch(choice){
        case CMD_START:
            motor_request_start();
            break;
        case CMD_IDLE:
            motor_request_stop();
            break;
        case CMD_RUNNING:
            motor_request_set_fault();
            break;
        case CMD_CLEAR_FAULT:
            motor_request_clear_fault();
            break;
        default:
            break;
    }
}

int main(){
    LOG_I(TAG, "Start program!!!");
    motor_init();
    while(1){
        LOG_I(TAG, "Choose your choice:");
        LOG_I(TAG, "0-continue\t1-start\t2-stop\t3-setFault\t4-clearError\t5-exit");
        uint8_t choice = 0;
        scanf("%hhu", &choice);
        if(choice == 5) exit(1);
        motor_control((MotorCommand)choice);
        motor_update();
        //Read ADC
        uint16_t adc_value = 500;
        LOG_I(TAG, "voltage value: %2.0f", adc_to_voltage(adc_value));
        adc_value++;
    }
    

    return 0;
}