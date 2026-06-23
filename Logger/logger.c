/* File: logger.c */

#ifndef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#endif

#include "logger.h"
#include <stdio.h>
#include <stdarg.h> // Required for va_list, va_start, va_end

#ifdef _WIN32
    #include <windows.h>
#else
    #include <time.h>
#endif

#define LOG_COLOR_RESET   "\033[0m"

// -------------------------------------------------------------------------
// HÀM LOG GỐC CỦA HỆ THỐNG (ĐẦU MỐI XỬ LÝ TẬP TRUNG)
// -------------------------------------------------------------------------
void embedded_log_write(const char* color, const char* level_str, const char* tag, const char* fmt, ...) {
    // 1. Print the fixed prefix (color, millisecond timestamp, level label, tag name)
    printf("%s[%08lu][%s][%s]: ", color, (unsigned long)logger_get_timestamp_ms(), level_str, tag);

    // 2. Process the variable argument list passed in (... like printf)
    va_list args;
    va_start(args, fmt);
    
    // ON PC (Ubuntu/Windows): use vprintf to write directly to the standard terminal stream
    vprintf(fmt, args);
    
    /* * ON REAL EMBEDDED BOARDS (STM32, ESP32, ...): comment out the vprintf line above 
     * and uncomment the code below to route log output through UART, SD card, or a ring buffer.
     *
     * char log_buffer[256];
     * vsnprintf(log_buffer, sizeof(log_buffer), fmt, args);
     * HAL_UART_Transmit(&huart1, (uint8_t*)log_buffer, strlen(log_buffer), 100);
     */

    va_end(args);

    // 3. Reset ANSI color and automatically add a newline to finish the log message
    printf(LOG_COLOR_RESET "\n");
}

// -------------------------------------------------------------------------
// SYNCHRONOUS TIMESTAMP FUNCTION (MILLISECONDS)
// -------------------------------------------------------------------------
uint32_t logger_get_timestamp_ms(void) {
#if defined(_WIN32)
    return GetTickCount();
#elif defined(__linux__)
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint32_t)(ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
#else 
    // ON REAL EMBEDDED BOARDS: return the hardware tick counter
    // Example for STM32: return HAL_GetTick();
    // Example for ESP32: return (uint32_t)(esp_timer_get_time() / 1000);
    static uint32_t simulated_tick = 0;
    return simulated_tick++;
#endif
}