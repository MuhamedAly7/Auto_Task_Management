#include "TaskExecutor.hpp"

int main() {

    // Get home path from environment variable HOME
    std::string homepath(std::getenv("HOME"));
    // Add my config file to the path
    homepath += "/.tasks";
    // Casting the path string
    const char* configFile = homepath.c_str();
    // Create instance for task executer class
    TaskExecutor taskExecutor(configFile);
    // Execute tasks from configuration file
    taskExecutor.executeTasks();

    return 0;
}
