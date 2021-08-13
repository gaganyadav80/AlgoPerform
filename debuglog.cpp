#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring>

void printLog(std::string msg) {
    auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char *t = ctime(&time);
    if (t[strlen(t)-1] == '\n') t[strlen(t)-1] = '\0';
    std::cout << "[" << t << "]: " << msg << "\n" ;
}
