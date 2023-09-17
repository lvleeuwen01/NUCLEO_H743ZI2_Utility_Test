/*------------------------------------------------------------------------------------------------*/
/**
 * @file    logging_config.h
 * @author  Luc
 * @date    Sep 12, 2023
 * @brief   Configuration file for the logging module
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
#ifndef LOGGING_LOGGING_CONFIG_H_
#define LOGGING_LOGGING_CONFIG_H_
/*------------------------------------------------------------------------------------------------*/
/* Includes                                                                                       */
/*------------------------------------------------------------------------------------------------*/
#include "logging.h"

/*------------------------------------------------------------------------------------------------*/
/* Definitions and typedefs                                                                       */
/*------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure whether the log message should be preceded by the current tick count.
 * 1 includes the tick count in log messages
 * 0 omits the tick count from log messages
 *
 * In order for the tick count to be included, the LOGGING_TICK_INCLUDE and LOGGING_TICK_GETTER
 * macro's should be defined.
 *
 */
#define LOGGING_INCLUDE_TICK_COUNT  1

/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure which file to include for access to the tick getter function.
 *
 */
#define LOGGING_TICK_INCLUDE        "cmsis_os.h"

/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure which function to call to get the current tick in unsigned integer format
 *
 */
#define LOGGING_TICK_GETTER         osKernelGetTickCount

/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure a default log level to use in modules
 *
 */
#define LOG_LEVEL_DEFAULT           LOG_LEVEL_WARNING

/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure the minimum log level to be printed to the output
 * NOTE: this overrides the configuration set in the log module declaration
 *
 */
#define LOG_LEVEL_MIN               LOG_LEVEL_WARNING

/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure the maximum log level to be printed to the output
 * NOTE: this overrides the configuration set in the log module declaration
 * NOTE: this overrides the minimum log level configuration
 *
 */
#define LOG_LEVEL_MAX               LOG_LEVEL_DEBUG

/*------------------------------------------------------------------------------------------------*/
/**
 * @brief Configure the log output to color ERROR and WARNING messages
 * 1 enables colors in the log output
 * 0 disables colors in the log output
 *
 */
#define LOGGING_ENABLE_COLORS       1

/*------------------------------------------------------------------------------------------------*/
/* Global variables                                                                               */
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
/* Global function prototypes                                                                     */
/*------------------------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------------------------*/
#endif /* LOGGING_LOGGING_CONFIG_H_ */
/*------------------------------------------------------------------------------------------------*/
/* EOF                                                                                            */
/*------------------------------------------------------------------------------------------------*/
