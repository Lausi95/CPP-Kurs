#include "logging.h"

#include <iostream>
#include <ctime>

void printTimeStamp() {
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, 80, "%d.%m.%y %H:%M:%S", timeinfo);
    std::cout << buffer;
}

void log(const char *level, const char *message) {
    std::cout << " [" << level << "] " << message << std::endl;
}

void log(const char *level, const std::string &message) {
    std::cout << " [" << level << "] " << message << std::endl;
}

void log(const char *level, const std::stringstream &message) {
    std::cout << " [" << level << "] " << message.str() << std::endl;
}
