#include "list_schedule.hpp"
#include <fstream>
#include <iostream>
#include <string>

list_tasks::list_tasks(const char *configPath) : configFilePath(configPath) {}


void list_tasks::parse_configfile() {

    // Open the configuration file
    std::ifstream configFile(configFilePath);

    // check if the file is opened successfully or not
    if(!configFile.is_open()) {
        std::cerr << " Error during open the configuration file. " << std::endl;
        exit(1);
    }

    // Parse the file line by line
    int line_count = 0;
    std::string line;

    while(std::getline(configFile, line)) {
        line_count++;
        std::cout << line_count << " - " << line << std::endl;
    }
    configFile.close();
}

