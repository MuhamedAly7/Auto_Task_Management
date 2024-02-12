#include "TaskSaving.hpp"
#include <iomanip>


// Initialize the attributes
TaskScheduler::TaskScheduler(const char *configPath) : configFilePath(configPath) {
    minutes = 0;
    hour = 0;
    day = nullptr;
    taskPath = nullptr;
}

// Parsing the input Argumets
void TaskScheduler::parseArguments(int argc, char *argv[]) {
    if (argc != 8) {
        std::cerr << "Must be: " << "addtask" << " -m <minute> -h <hour> -d <day> <task executable path>" << std::endl;
        exit(1);
    }

    for (int i = 1; i < argc - 1; i += 2) {
        if (strcmp(argv[i], "-m") == 0) {
            minutes = atoi(argv[i + 1]);
            validateMinutes();
        } else if (strcmp(argv[i], "-h") == 0) {
            hour = atoi(argv[i + 1]);
            validateHour();
        } else if (strcmp(argv[i], "-d") == 0) {
            setDay(argv[i + 1]);
        } else {
            std::cerr << "Invalid Argument: " << argv[i] << std::endl;
            exit(1);
        }
    }

    taskPath = argv[argc - 1];
}


/* ------------------------------------- Validate Parameters ----------------------------------------- */
void TaskScheduler::validateMinutes() const {
    if (minutes > 59) {
        std::cerr << "Invalid Argument " << minutes << std::endl;
        exit(1);
    }
}

void TaskScheduler::validateHour() const {
    if (hour > 23) {
        std::cerr << "Invalid Argument " << hour << std::endl;
        exit(1);
    }
}

void TaskScheduler::setDay(const char *inputDay) {
    day = inputDay;
    std::string dayStr(day);
    std::transform(dayStr.begin(), dayStr.end(), dayStr.begin(), [](unsigned char c) { return std::tolower(c); });

    if ((dayStr != "saturday") && (dayStr != "sunday") && (dayStr != "monday") && (dayStr != "tuesday") && (dayStr != "wednesday") && (dayStr != "thursday") && (dayStr != "friday") && (dayStr != "everyday") ) {
        std::cerr << "Invalid Argument " << day << std::endl;
        exit(1);
    }
}
/* --------------------------------------------------------------------------------------------------- */

// Saving tasks time line into configuration file
void TaskScheduler::saveToConfigFile() const {
    std::ofstream configFile(configFilePath, std::ios::app);
    if (!configFile.is_open()) {
        std::cerr << "Error open the config file." << std::endl;
        exit(1);
    }

    configFile << day << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minutes << "," << taskPath << std::endl;

    std::cout << "Scheduling information saved successfully." << std::endl;
}
