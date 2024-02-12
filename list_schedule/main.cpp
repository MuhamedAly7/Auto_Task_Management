#include "list_schedule.hpp"


int main()
{
    
    // Get home path from environment variable HOME
    std::string homepath(std::getenv("HOME"));
    // Add my config file to the path
    homepath += "/.tasks";
    const char* configFile = homepath.c_str();
    
    list_tasks file_parser(configFile);

    file_parser.parse_configfile();

    return 0;
}
