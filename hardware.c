#include "global_config.h"
#include <time.h>
// hardware: 32bit register
volatile uint32_t HW_STATUS_REG = 0;

void delay_ms(uint32_t milliseconds){
    struct timespec req;
    req.tv_sec = milliseconds / 1000;
    req.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&req, NULL);
}
