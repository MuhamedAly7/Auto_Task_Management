#include "delete_task.hpp"


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cerr << "Must be: " << "deltask" << " <Line Number>" << std::endl;
        exit(1);
    }

    // Get home path from environment variable HOME
    std::string homepath(std::getenv("HOME"));
    // Add my config file to the path
    homepath += "/.tasks";
    const char* configFile = homepath.c_str();

    delete_task Del_Task(configFile);
    Del_Task.DeleteTaskNum(atoi(argv[1]));

    return 0;
}