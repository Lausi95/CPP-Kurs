#include "logging.h"

#include <iostream>
#include <ctime>

void printTimeStamp() {
    std::cout << "xx.xx.xx xx:xx";
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
