#include "TaskSaving.hpp"

int main(int argc, char *argv[]) {

    // Get home path from environment variable HOME
    std::string homepath(std::getenv("HOME"));
    // Add my config file to the path
    homepath += "/.tasks";
    // Casting the path string
    const char* configFile = homepath.c_str();

    // Initialize task saving schedule
    TaskScheduler taskScheduler(configFile);
    
    // Parse input parameters
    taskScheduler.parseArguments(argc, argv);
    // Save Schedule
    taskScheduler.saveToConfigFile();

    return 0;
}
