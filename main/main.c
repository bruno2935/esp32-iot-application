/**
 * Application Entry point
 */
#include "esp_err.h"
#include "nvs.h"
#include "nvs_flash.h"
#include "NTC103.h"
#include "wifi_app.h"
#include "wifi_reset_button.h"
#include "sntp_time_sync.h"
#include "esp_log.h"
#include "mqtt_demo_mutual_auth.h"

static const char TAG[] = "main";

void wifi_application_connected_events(void)
{
	ESP_LOGI(TAG, "Wifi application connected!!");
	sntp_time_sync_task_start();
	mqtt_task_start();

}

void app_main(void)
{
	// Initialize NVS
	esp_err_t ret = nvs_flash_init();
	if(ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
	{
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	//Start Wifi
	wifi_app_start();
	//Configure Wifi reset button
	wifi_reset_button_config();		
	//Start ntc103 sensor task
	NTC103_task_start();
	// Set connected event callback
	wifi_app_set_callback(&wifi_application_connected_events);

}
