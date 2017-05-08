#ifndef HALLOWELT_LOGGING_H
#define HALLOWELT_LOGGING_H

#include <string>
#include <sstream>

#define LOG_LEVEL_TRACE 0
#define LOG_LEVEL_DEBUG 1
#define LOG_LEVEL_INFO  2
#define LOG_LEVEL_WARN  3
#define LOG_LEVEL_ERROR 4

#define LOG_LEVEL LOG_LEVEL_DEBUG

#if LOG_LEVEL <= LOG_LEVEL_TRACE
#define TRACE(message) printTimeStamp(); log("TRACE", message);
#else
#define TRACE(message)
#endif

#if LOG_LEVEL <= LOG_LEVEL_DEBUG
#define DEBUG(message) printTimeStamp(); log("DEBUG", message);
#else
#define DEBUG(message)
#endif

#if LOG_LEVEL <= LOG_LEVEL_INFO
#define INFO(message) printTimeStamp(); log("INFO", message);
#else
#define INFO(message)
#endif

#if LOG_LEVEL <= LOG_LEVEL_WARN
#define WARN(message) printTimeStamp(); log("WARN", message);
#else
#define WARN(message)
#endif

#if LOG_LEVEL <= LOG_LEVEL_ERROR
#define ERROR(message) printTimeStamp(); log("ERROR", message);
#else
#define ERROR(message)
#endif

void printTimeStamp();

void log(const char *level, const char *message);
void log(const char *level, const std::string &message);
void log(const char *level, const std::stringstream &message);

#endif //HALLOWELT_LOGGING_H
