#ifndef GLOBAL_CONFIG_H
#define GLOBAL_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>
#include "logger.h"
// value
#define SET 1
#define RESET 0
// Bit mask:
#define BIT_MOTOR_EN    SET << 0     // 1 = allow to run, 0 = stop
#define BIT_MOTOR_TEMP  SET << 1   // 1 = over temperature
#define BIT_MOTOR_CURR  SET << 2   // 1 = over current
#define BIT_SENSOR_ERR  SET << 3   // 1 = loss sensor signal


extern volatile uint32_t HW_STATUS_REG;
void delay_ms(uint32_t milliseconds);
// convert from adc to voltage
static inline float adc_to_voltage(uint16_t adc_val){
    return ((float)adc_val / 4095.0) * 3.3;
}

#ifdef __cplusplus
}
#endif
#endif