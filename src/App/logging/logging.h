/*------------------------------------------------------------------------------------------------*/
/**
 * @file    logging.h
 * @author  Luc
 * @date    Sep 14, 2023
 * @brief   Logging module
 * 
 * Copyright (c) 2023 Luc van Leeuwen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
/*------------------------------------------------------------------------------------------------*/
#ifndef LOGGING_LOGGING_H_
#define LOGGING_LOGGING_H_
/*------------------------------------------------------------------------------------------------*/
/* Includes                                                                                       */
/*------------------------------------------------------------------------------------------------*/
#include "SEGGER_RTT.h"
#include "logging_config.h"

/*------------------------------------------------------------------------------------------------*/
/* Definitions and typedefs                                                                       */
/*------------------------------------------------------------------------------------------------*/
/* Output configuration */
#ifdef DEBUG
#define LOG(format, ...)        SEGGER_RTT_printf(0, format "\n", ##__VA_ARGS__)
#define DPRINTF(format, ...)    SEGGER_RTT_printf(0, format, ##__VA_ARGS__)
#else
#define LOG(format, ...)
#define DPRINTF(format, ...)
#endif

/* Log module declaration */
#define LOG_MODULE(name, level) \
    static const char * log_module_name = name; \
    static const uint8_t log_module_level = level;

/* Format configuration */
#if LOGGING_INCLUDE_TICK_COUNT
#define LOG_TICK()    DPRINTF("[%9d] - ", LOGGING_TICK_GETTER())
#else
#define LOG_TICK()
#endif


#if LOGGING_ENABLE_COLORS
#define ERR_COLOR RTT_CTRL_TEXT_BRIGHT_RED
#define WRN_COLOR RTT_CTRL_TEXT_BRIGHT_YELLOW
#define COLOR_RESET RTT_CTRL_RESET
#else
#define ERR_COLOR ""
#define WRN_COLOR ""
#define COLOR_RESET ""
#endif

/* Utility */
#ifndef   MIN
  #define MIN(a, b)                                       (((a) < (b)) ? (a) : (b))
#endif

#ifndef   MAX
  #define MAX(a, b)                                       (((a) > (b)) ? (a) : (b))
#endif

/* Log level configuration */
#define LOG_LEVEL_OFF           0
#define LOG_LEVEL_ERROR         1
#define LOG_LEVEL_WARNING       2
#define LOG_LEVEL_INFO          3
#define LOG_LEVEL_DEBUG         4

#if LOG_LEVEL_MIN > LOG_LEVEL_MAX
#warning "LOG_LEVEL_MIN > LOG_LEVEL_MAX - assigning LOG_LEVEL_MAX to LOG_LEVEL_MIN"
#undef LOG_LEVEL_MIN
#define LOG_LEVEL_MIN LOG_LEVEL_MAX
#endif

/* Logging macro's */
#define LOG_ERR(format, ...)    \
        if(MIN(LOG_LEVEL_MAX, MAX(log_module_level, LOG_LEVEL_MIN)) >= LOG_LEVEL_ERROR) {\
            DPRINTF(ERR_COLOR); \
            LOG_TICK(); \
            DPRINTF("[%s] ERROR: " format, log_module_name, ##__VA_ARGS__); \
            DPRINTF(COLOR_RESET); \
            LOG(); \
        }

#define LOG_WRN(format, ...)    \
        if(MIN(LOG_LEVEL_MAX, MAX(log_module_level, LOG_LEVEL_MIN)) >= LOG_LEVEL_WARNING) { \
            DPRINTF(WRN_COLOR); \
            LOG_TICK(); \
            DPRINTF("[%s] WARNING: " format, log_module_name, ##__VA_ARGS__); \
            DPRINTF(COLOR_RESET); \
            LOG(); \
        }

#define LOG_INF(format, ...)    \
        if(MIN(LOG_LEVEL_MAX, MAX(log_module_level, LOG_LEVEL_MIN)) >= LOG_LEVEL_INFO) { \
            LOG_TICK(); \
            DPRINTF("[%s] INFO: " format, log_module_name, ##__VA_ARGS__); \
            LOG(); \
        }

#define LOG_DBG(format, ...)    \
        if(MIN(LOG_LEVEL_MAX, MAX(log_module_level, LOG_LEVEL_MIN)) >= LOG_LEVEL_DEBUG) { \
            LOG_TICK(); \
            DPRINTF("[%s] DEBUG: " format, log_module_name, ##__VA_ARGS__); \
            LOG(); \
        }

/*------------------------------------------------------------------------------------------------*/
/* Global variables                                                                               */
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
/* Global function prototypes                                                                     */
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
#endif /* LOGGING_LOGGING_H_ */
/*------------------------------------------------------------------------------------------------*/
/* EOF                                                                                            */
/*------------------------------------------------------------------------------------------------*/
