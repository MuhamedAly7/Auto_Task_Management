# Auto_Task_Management
Auto Task Management is a developed command-line tool for task/executable/scripts scheduling and execution in a Linux environment. It allows you to add, list, delete specific tasks, and clean all tasks easily. The tasks are scheduled based on specified minutes, hours, and days.

## Usage
### Add Task
To add a task, use the following command:
```bash
addtask -m <minute> -h <hour> -d <day> <executable task file Path>
```
Replace <minute>, <hour>, <day>, and <executable task file Path> with the desired values for scheduling your task.

### List Tasks
To list all tasks, use the following command:
```bash
ltasks
```
### Delete Specific Task
To delete a specific task, use the following command:
```bash
deltasks <task number>
```
Replace <task number> with the number corresponding to the task you want to delete (as displayed by the ltasks command).

### Clean All Tasks
To clean all tasks, use the following command:
```bash
cleantasks
```
This command will remove all tasks.

## Build and Installation
### Build
To build the executable files, run:
```bash
make build
```
### Installation
To install the application, run:
```bash
make install
```
This will create the necessary configuration files, systemd service file, and bash aliases.

### Uninstallation
To uninstall the application, run:
```bash
make uninstall
```
This will disable and stop the systemd service, remove the service file, and update the bash aliases.

### Clean Executables
To clean the compiled executables, run:
```bash
make clean
```
## Configuration
- The configuration file is located at ${HOME}/.tasks.
- Bash aliases for convenient usage are added to ${HOME}/.bash_aliases.
## Note
- The systemd service file is named task_manager_executor.service.
- The application is designed to work in a Linux environment.
- Ensure that your system has sed installed.

Feel free to customize the makefile according to your needs and system specifications.

