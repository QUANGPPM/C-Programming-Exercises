#include "motor.h"

MotorState current_state = STATE_INIT; 
volatile uint32_t* const hw_ptr = &HW_STATUS_REG;
static const char* MOTOR_TAG = "MOTOR";

void motor_init(void){
    current_state = STATE_INIT;
}

void motor_request_start(void){
    *hw_ptr |= BIT_MOTOR_EN; // enable motor
    LOG_W(MOTOR_TAG, "ENABLE MOTOR");
}
void motor_request_stop(void){
    *hw_ptr &= ~BIT_MOTOR_EN; // disable motor
    LOG_W(MOTOR_TAG, "DISABLE MOTOR");
}
void motor_request_set_fault(void){
    *hw_ptr |= BIT_MOTOR_CURR;
    LOG_W(MOTOR_TAG, "SET FAULT to MOTOR");
}
void motor_request_clear_fault(void){
    *hw_ptr &= ~BIT_MOTOR_TEMP;
    *hw_ptr &= ~BIT_MOTOR_CURR;
    *hw_ptr &= ~BIT_SENSOR_ERR;
    LOG_W(MOTOR_TAG, "CLEAR FAULT");
}
void motor_update(void){
    switch(current_state){
        case STATE_INIT:
            LOG_I(MOTOR_TAG, "Motor init....");
            current_state = STATE_IDLE;
            break;
        case STATE_IDLE:
            LOG_I(MOTOR_TAG, "Motor Idle....");
            if(BIT_MOTOR_EN & *hw_ptr){
                current_state = STATE_RUNNING;
            }
            break;
        case STATE_RUNNING:
            LOG_I(MOTOR_TAG, "Running....");
            if((BIT_MOTOR_EN & *hw_ptr) == 0){
                current_state = STATE_IDLE;
            }
            if((BIT_MOTOR_CURR & *hw_ptr) || (BIT_MOTOR_TEMP & *hw_ptr) || (BIT_SENSOR_ERR & *hw_ptr)){
                current_state = STATE_FAULT;
            }
            break;
        case STATE_FAULT:
            LOG_I(MOTOR_TAG, "Motor fault....");
            if(!(BIT_MOTOR_CURR & *hw_ptr) && !(BIT_MOTOR_TEMP & *hw_ptr) && !(BIT_SENSOR_ERR & *hw_ptr)){
                current_state = STATE_FAULT;
            }
            break;
    }
}
MotorState motor_get_satte(void){
    return current_state;
}