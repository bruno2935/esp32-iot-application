#ifndef MAIN_TASKS_COMMON_H_
#define MAIN_TASKS_COMMON_H_

// Wifi application task
#define WIFI_APP_TASK_STACK_SIZE			4096
#define WIFI_APP_TASK_PRIORITY				5
#define WIFI_APP_TASK_CORE_ID				0


// HTTP Server Task
#define HTTP_SERVER_TASK_STACK_SIZE			8192
#define	HTTP_SERVER_TASK_PRIORIRY			4
#define HTTP_SERVER_TASK_CODE_ID			0

// HTTP Server Monitor task
#define HTTP_SERVER_MONITOR_STACK_SIZE		4096
#define HTTP_SERVER_MONITOR_PRIORITY		3
#define HTTP_SERVER_MONITOR_CORE_ID			0

// Wifi Reset button task
#define WIFI_RESET_BUTTON_TASK_STACK_SIZE	2048
#define WIFI_RESET_BUTTON_TASK_PRIORITY		6
#define WIFI_RESET_BUTTON_CORE_ID			0

// NTC103 Sensor task
#define NTC103_TASK_STACK_SIZE				4096
#define NTC103_TASK_PRIORITY				5
#define NTC103_TASK_CODE_ID					1

// STNP Time sync task
#define STNP_TIME_SYNC_TASK_STACK_SIZE		4096
#define STNP_TIME_SYNC_TASK_TASK_PRIORITY	4
#define STNP_TIME_SYNC_TASK_CODE_ID			1


#endif
