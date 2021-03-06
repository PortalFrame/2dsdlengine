/*
 * Copyright (c) 2011-2016 minjie.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 */

#ifndef _LOGGER_HPP_
    #define _LOGGER_HPP_

/// Shorter macro interfaces
#define LOG_INFO(msg) (cLogger::GetInstance()->PrintLog(LogLevel_INFO, msg))
#define LOG_ERROR(msg) (cLogger::GetInstance()->PrintLog(LogLevel_ERROR, msg))
#define LOG_WARN(msg) (cLogger::GetInstance()->PrintLog(LogLevel_WARN, msg))
#define LOG_DEBUG(msg) (cLogger::GetInstance()->PrintLog(LogLevel_DEBUG, msg))

typedef enum{
    LogLevel_INFO,
    LogLevel_ERROR,
    LogLevel_WARN,
    LogLevel_DEBUG
}eLogLevel;


class cLogger
{
public:
    void PrintLog(eLogLevel level, const char *msg);

private:
    cLogger(){};
    ~cLogger(){};

/// STATIC
private:
    static cLogger *s_logger;
public:
    static cLogger *GetInstance();
};

#endif /* _LOGGER_HPP_ */
