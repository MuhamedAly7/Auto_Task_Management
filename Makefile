# For Task executer side
SRC_TASK_EXECUTOR1 := execute_schedule/TaskExecutor.cpp
SRC_TASK_EXECUTOR2 := execute_schedule/main.cpp

# For Task saving side
SRC_TASK_SAVING1 := saving_schedule/TaskSaving.cpp
SRC_TASK_SAVING2 := saving_schedule/main.cpp

# For List Tasks side
SRC_LIST_TASKS1 := list_schedule/list_schedule.cpp
SRC_LIST_TASKS2 := list_schedule/main.cpp

# For Delete Tasks side
SRC_DELETE_TASKS1 := delete_task/delete_task.cpp
SRC_DELETE_TASKS2 := delete_task/main.cpp


# Compiler
CXX := g++
# Current directory
CURR_DIR := ${PWD}

# Useful variable
CONFIG_FILE_PATH   := "${HOME}/.tasks"
BASH_ALIASE_PATH   := "${HOME}/.bash_aliases"
SYSD_SERVICE_FILE  := "${CURR_DIR}/task_manager_executor.service"
SYSD_DESTINATION   := "/etc/systemd/system/"
SYSTEMD_SERVICE    := task_manager_executor.service
STRING_ALIAS1      := "alias addtask='${CURR_DIR}/saving_schedule/savingexp'"
STRING_ALIAS2      := "alias ltasks='${CURR_DIR}/list_schedule/list_tasks'"
STRING_ALIAS3      := "alias deltasks='${CURR_DIR}/delete_task/delete_task'"
STRING_ALIAS4      := "alias cleantasks='echo -n > ${HOME}/.tasks'"


# Build target
build:
	@${CXX} ${SRC_TASK_SAVING1} ${SRC_TASK_SAVING2} -o ${CURR_DIR}/saving_schedule/savingtasks
	@${CXX} ${SRC_TASK_EXECUTOR1} ${SRC_TASK_EXECUTOR2} -o ${CURR_DIR}/execute_schedule/TaskExecutor
	@${CXX} ${SRC_LIST_TASKS1} ${SRC_LIST_TASKS2} -o ${CURR_DIR}/list_schedule/list_tasks
	@${CXX} ${SRC_DELETE_TASKS1} ${SRC_DELETE_TASKS2} -o ${CURR_DIR}/delete_task/delete_task

#	@echo ${CURR_DIR}

# Creating the config file
	@if [ -f ${CONFIG_FILE_PATH} ]; then \
		echo ".tasks File found"; \
	else \
		echo ".tasks File Created"; \
		touch ${CONFIG_FILE_PATH}; \
	fi

# Creating the .bash_aliases if it not found
	@if [ -f ${BASH_ALIASE_PATH} ]; then \
		echo ".bash_aliases File found"; \
	else \
		touch ${BASH_ALIASE_PATH}; \
		echo ".bash_aliases Created"; \
	fi


# Install the application
install:

# Creating systemd daemon/service file for application
	@echo "[Unit]" > ${SYSD_SERVICE_FILE}
	@echo "Description=Task Executor Service" >> ${SYSD_SERVICE_FILE}
	@echo "Documentation=https://github.com/MuhamedAly7/Auto_Task_Management" >> ${SYSD_SERVICE_FILE}
	@echo "" >> ${SYSD_SERVICE_FILE}
	@echo "[Service]" >> ${SYSD_SERVICE_FILE}
	@echo "Type=simple" >> ${SYSD_SERVICE_FILE}
	@echo "User=muhammed" >> ${SYSD_SERVICE_FILE}
	@echo "Environment=\"DISPLAY=:0\"" >> ${SYSD_SERVICE_FILE}
	@echo "Environment=\"DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus\"" >> ${SYSD_SERVICE_FILE}
	@echo "Environment=\"XDG_RUNTIME_DIR=/run/user/1000\"" >> ${SYSD_SERVICE_FILE}
	@echo "Environment=\"QT_QPA_PLATFORM=xcb\"" >> ${SYSD_SERVICE_FILE}
	@echo "Environment=\"LANG=en_US.UTF-8\"" >> ${SYSD_SERVICE_FILE}
	@echo "ExecStart=${CURR_DIR}/execute_schedule/TaskExecutor" >> ${SYSD_SERVICE_FILE}
	@echo "Restart=always" >> ${SYSD_SERVICE_FILE}
	@echo "RestartSec=60" >> ${SYSD_SERVICE_FILE}
	@echo "" >> ${SYSD_SERVICE_FILE}
	@echo "[Install]" >> ${SYSD_SERVICE_FILE}
	@echo "WantedBy=graphical.target" >> ${SYSD_SERVICE_FILE}

# Install Edite text tool
	@sudo apt install sed
# Copy the systemd service file to /etc/systemd/system/
	@sudo cp ${SYSD_SERVICE_FILE} ${SYSD_DESTINATION}
# Reload daemons/services
	@sudo systemctl daemon-reload
# Enable and start my service
	@sudo systemctl enable ${SYSTEMD_SERVICE}
	@sudo systemctl start ${SYSTEMD_SERVICE}
	@sudo systemctl daemon-reload
# Add alias of to be our command
	@echo ${STRING_ALIAS1} >> ${BASH_ALIASE_PATH}
	@echo ${STRING_ALIAS2} >> ${BASH_ALIASE_PATH}
	@echo ${STRING_ALIAS3} >> ${BASH_ALIASE_PATH}
	@echo ${STRING_ALIAS4} >> ${BASH_ALIASE_PATH}

# Info the user it is finished
	@echo "Done!"

# Uninstall the application
uninstall:
	@sudo systemctl disable ${SYSTEMD_SERVICE}
	@sudo systemctl stop ${SYSTEMD_SERVICE}
	@sudo rm ${SYSD_DESTINATION}${SYSTEMD_SERVICE}
	@sudo systemctl daemon-reload
	@sed -i '/alias addtask=.*saving_schedule\/savingexp/d' "${BASH_ALIASE_PATH}"
	@sed -i '/alias ltasks=.*list_schedule\/list_tasks/d' "${BASH_ALIASE_PATH}"
	@sed -i '/alias deltasks=.*delete_task\/delete_task/d' "${BASH_ALIASE_PATH}"
	@sed -i '/alias cleantasks='\''.*'\''/d' "${BASH_ALIASE_PATH}"
	@echo "Done!"

# Clean the executable of application
clean:
	@rm ${CURR_DIR}/saving_schedule/savingtasks
	@rm ${CURR_DIR}/execute_schedule/TaskExecutor
	@rm ${CURR_DIR}/list_schedule/list_tasks
	@rm ${CURR_DIR}/delete_task/delete_task
	
