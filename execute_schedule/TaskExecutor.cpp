#include "TaskExecutor.hpp"


TaskExecutor::TaskExecutor(const char *configPath) : configFilePath(configPath) {}

std::string TaskExecutor::getCommandOutput(const char *command) {
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        std::cerr << "popen() failed!" << std::endl;
        return "";
    }

    char buffer[128];
    std::string result = "";

    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr) {
            result += buffer;
        }
    }

    pclose(pipe);
    return result;
}

void TaskExecutor::executeTasks() {
    // This command to get current date and time with a specific format
    const char *command = "LC_TIME=en_US.UTF-8 date +\"%A%H:%M\"";
    const char *command2 = "LC_TIME=en_US.UTF-8 date +\"%H:%M\"";
    std::string commandResult = getCommandOutput(command);
    std::string commandResult2 = getCommandOutput(command2);

    // Open the configuration file
    std::ifstream configFile(configFilePath);

    // Check if the file is opened successfully or not
    if (!configFile.is_open()) {
        std::cerr << "Error during open the configuration file." << configFilePath << std::endl;
        exit(1);
    }

    // Parse the file line by line
    std::string line;

    while (std::getline(configFile, line)) {
        // Tokens for every line
        std::vector<std::string> lineTokens;
        std::string token;
        std::istringstream isstring(line);

        // Tokenize every task line
        while (std::getline(isstring, token, ',')) {
            lineTokens.push_back(token);
        }

        // Convert all characters to lowercase
        std::transform(commandResult.begin(), commandResult.end(), commandResult.begin(), [](unsigned char c) { return std::tolower(c); });
        std::transform(commandResult2.begin(), commandResult2.end(), commandResult2.begin(), [](unsigned char c) { return std::tolower(c); });
        std::transform(lineTokens[0].begin(), lineTokens[0].end(), lineTokens[0].begin(), [](unsigned char c) { return std::tolower(c); });

        // Compare the current time with the time line of every task
        if (commandResult.substr(0, commandResult.size() - 1) == lineTokens[0]) {
            const char *executedTask = lineTokens[1].c_str();
            int result = std::system(executedTask); // execute the task if times matched
        }

        if((lineTokens[0].substr(0, 8) == "everyday") && (commandResult2.substr(0, commandResult2.size() - 1) == lineTokens[0].substr(8, 5)))
        {
            const char *executedTask = lineTokens[1].c_str();
            int result = std::system(executedTask); // execute the task if times matched
        }
    }

    // Close the file
    configFile.close();
}
