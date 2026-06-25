/* File: logger.h */
#ifndef LOGGER_H
#define LOGGER_H
#ifdef __cplusplus
extern "C"{
#endif

#include <stdint.h>
#include <stddef.h>

// -------------------------------------------------------------------------
// 1. LOG LEVEL DEFINITIONS
// -------------------------------------------------------------------------
#define LOG_LEVEL_NONE    0
#define LOG_LEVEL_FATAL   1
#define LOG_LEVEL_ERROR   2
#define LOG_LEVEL_WARN    3
#define LOG_LEVEL_INFO    4
#define LOG_LEVEL_DEBUG   5

// -------------------------------------------------------------------------
// 2. HIGHEST LOG LEVEL CONFIGURATION (COMPILE-TIME FILTER)
// Change this value to enable or disable log groups when packaging the final build
// -------------------------------------------------------------------------
#define CONFIG_LOG_MAX_LEVEL   LOG_LEVEL_DEBUG

// -------------------------------------------------------------------------
// 3. BASE FUNCTION DECLARATIONS IMPLEMENTED IN LOGGER.C
// -------------------------------------------------------------------------
uint32_t logger_get_timestamp_ms(void);

// Base logging function accepts variable arguments (acts like printf)
void embedded_log_write(const char* color, const char* level_str, const char* tag, const char* fmt, ...);

// -------------------------------------------------------------------------
// 4. ANSI COLOR CODES FOR TERMINAL VISUALIZATION
// -------------------------------------------------------------------------
#define LOG_COLOR_F       "\033[1;35m"  // Bright magenta (Fatal)
#define LOG_COLOR_E       "\033[0;31m"  // Red (Error)
#define LOG_COLOR_W       "\033[0;33m"  // Yellow (Warning)
#define LOG_COLOR_I       "\033[0;32m"  // Green (Info)
#define LOG_COLOR_D       "\033[0;36m"  // Cyan (Debug)

// -------------------------------------------------------------------------
// 5. MACRO SYSTEM
// -------------------------------------------------------------------------

#if CONFIG_LOG_MAX_LEVEL >= LOG_LEVEL_FATAL
    #define LOG_F(tag, fmt, ...) embedded_log_write(LOG_COLOR_F, "F", tag, fmt, ##__VA_ARGS__)
#else
    #define LOG_F(tag, fmt, ...)
#endif

#if CONFIG_LOG_MAX_LEVEL >= LOG_LEVEL_ERROR
    #define LOG_E(tag, fmt, ...) embedded_log_write(LOG_COLOR_E, "E", tag, fmt, ##__VA_ARGS__)
#else
    #define LOG_E(tag, fmt, ...)
#endif

#if CONFIG_LOG_MAX_LEVEL >= LOG_LEVEL_WARN
    #define LOG_W(tag, fmt, ...) embedded_log_write(LOG_COLOR_W, "W", tag, fmt, ##__VA_ARGS__)
#else
    #define LOG_W(tag, fmt, ...)
#endif

#if CONFIG_LOG_MAX_LEVEL >= LOG_LEVEL_INFO
    #define LOG_I(tag, fmt, ...) embedded_log_write(LOG_COLOR_I, "I", tag, fmt, ##__VA_ARGS__)
#else
    #define LOG_I(tag, fmt, ...)
#endif

// For DEBUG, add __FILE__, __LINE__, and __func__ information to the format string (fmt)
#if CONFIG_LOG_MAX_LEVEL >= LOG_LEVEL_DEBUG
    #define LOG_D(tag, fmt, ...) embedded_log_write(LOG_COLOR_D, "D", tag, "(%s:%d -> %s()): " fmt, \
                                                    __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#else
    #define LOG_D(tag, fmt, ...)
#endif



#ifdef __cplusplus
}
#endif
#endif
