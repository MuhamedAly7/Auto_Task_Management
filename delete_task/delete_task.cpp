#include "delete_task.hpp"


delete_task::delete_task(const char *configPath) : configFilePath(configPath) {}


void delete_task::DeleteTaskNum(int num) {
    if(num < 1)
    {
        std::cerr << "Invalid line number" << std::endl;
        exit(1);
    }
    // Open the configuration file
    std::ifstream configFile(configFilePath);

    // check if the file is opened successfully or not
    if(!configFile.is_open())
    {
        std::cerr << " Error during open the configuration file. " << std::endl;
        exit(1);
    }

    // Parse the file line by line
    int line_count = 0;
    std::string line;
    std::vector<std::string> new_lines;

    while(std::getline(configFile, line)) {
        line_count++;
        if(line_count == num)
        {
            continue;
        }
        else
        {
            new_lines.push_back(line);
        }
    }

    configFile.close();

    if(std::remove(configFilePath) == 0) {
        std::cout << "done!" << std::endl;
    }
    else {
        std::cerr << "Error!!" << std::endl;
    }

    // Create an ofstream object and open the file
    std::ofstream outputFile(configFilePath);

    if(outputFile.is_open())
    {
        for(auto line : new_lines)
        {
            outputFile << line << std::endl;
        }
        outputFile.close();
    }
    else
    {
        std::cerr << "Error!!" << std::endl;
    }
}
