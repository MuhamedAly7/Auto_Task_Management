#ifndef TASK_EXECUTOR_H
#define TASK_EXECUTOR_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdlib>

class TaskExecutor {
private:
    const char *configFilePath;

public:
    TaskExecutor(const char *configPath);

    std::string getCommandOutput(const char *command);

    void executeTasks();
};

#endif 
