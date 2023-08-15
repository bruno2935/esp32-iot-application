#include "NTC103.h"
#include "driver/adc.h"
#include "driver/adc_types_legacy.h"
#include "rom/gpio.h"
#include "esp_adc_cal.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "math.h"
#include "tasks_common.h"




// == global defines ==================================================

static const char * TAG = "DHT";

static int ntc_gpio_pin = -1;

#define V_REF       1100        // Reference voltage in millivolts
#define R_REF       10000       // Reference resistor in ohms
#define ADC_RESOLUTION  4095    // ADC resolution for 12 bits

void ntc103_set_gpio_pin(int gpio_pin) {
    ntc_gpio_pin = gpio_pin;
}

void ntc103_init() {
    // Configure ADC1
    adc1_config_width(ADC_WIDTH_BIT_12);
    adc1_config_channel_atten(ADC1_CHANNEL_4, ADC_ATTEN_DB_11);

    // Characterize ADC1
    esp_adc_cal_characteristics_t adc_cal;
    esp_adc_cal_value_t adc_val = esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11, ADC_WIDTH_BIT_12, V_REF, &adc_cal);
    if (adc_val == ESP_ADC_CAL_VAL_EFUSE_TP) {
        printf("ADC calibration value in eFuse is not available.\n");
    } else if (adc_val == ESP_ADC_CAL_VAL_EFUSE_VREF) {
        printf("ADC Vref calibration data is not burned into eFuse.\n");
    }
}

float ntc103_read_temperature() {
    // Set GPIO pin for NTC sensor
    if (ntc_gpio_pin != -1) {
        gpio_pad_select_gpio(ntc_gpio_pin);
        gpio_set_direction(ntc_gpio_pin, GPIO_MODE_INPUT);
        gpio_set_pull_mode(ntc_gpio_pin, GPIO_PULLUP_ONLY);
    } else {
        // Handle error - GPIO pin not set
        // You can add appropriate error handling code here
        return -1.0f;  // Return an invalid temperature value
    }

	// Read ADC1 value
	uint32_t adc_reading = 0;
	float resistance,temperature = 0;
	for (int i = 0; i<20; i++) {
		adc_reading = adc1_get_raw(ADC1_CHANNEL_4);
		// Convert ADC reading to temperature using NTC equation
		resistance = R_REF * ((ADC_RESOLUTION - adc_reading) / (float)adc_reading);
		temperature += 1.0 / ((1.0 / 298.15) + (1.0 / 3435.0) * log(resistance / 10000.0)) - 273.15;
	}
	return temperature/20;
}



/**
 * ntc103 sensor task
 */
static void NTC103_task(void *pvParameter)
{
		// Sets gpio
		ntc103_set_gpio_pin(32);
		// Inits ntc103
		ntc103_init();
		printf("Starting NTC103 task\n\n");
		for(;;)
		{
			printf("=== Reading NTC103 ===\n");
			float temp = ntc103_read_temperature();
			printf("Temp %.1f\n", temp);
			
			// Wait at least 2 seconds before heading again
			vTaskDelay( 4000 / portTICK_PERIOD_MS);
		}

}

void NTC103_task_start()
{
	xTaskCreatePinnedToCore(&NTC103_task, "NTC103_task", NTC103_TASK_STACK_SIZE, NULL, NTC103_TASK_PRIORITY, NULL, NTC103_TASK_CODE_ID);
	
}
	
