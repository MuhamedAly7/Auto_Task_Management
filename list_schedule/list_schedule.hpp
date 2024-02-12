#ifndef LIST_SCHEDULE_H
#define LIST_SCHEDULE_H

#include <iostream>
#include <fstream>
#include <string>


class list_tasks {
    private:
        const char *configFilePath;

    public:
        list_tasks(const char *configPath);
        void parse_configfile();
};

#endif
