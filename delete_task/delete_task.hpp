#ifndef DELETE_TASK_H
#define DELETE_TASK_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>


class delete_task {
    private:
        const char *configFilePath;
    public:
        delete_task(const char *configPath);
        void DeleteTaskNum(int num);
};

#endif // !DELETE_TASK_H
