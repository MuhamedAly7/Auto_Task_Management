#ifndef SAVING_SCHEDULE_H
#define SAVING_SCHEDULE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cstdlib>

class TaskScheduler {
private:
    const char *configFilePath;
    int minutes, hour;
    const char *day;
    const char *taskPath;

public:
    TaskScheduler(const char *configPath);

    void parseArguments(int argc, char *argv[]);

    void validateMinutes() const;

    void validateHour() const;

    void setDay(const char *inputDay);

    void saveToConfigFile() const;
};

#endif 

