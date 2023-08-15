#ifndef NTC103_H
#define NTC103_H


#define NTC103_GPIO			25

/**
 * Starts the NTC103 sensor task
 */
void NTC103_task_start(void);

//  == function prototype ================================
void ntc103_init();

// Function to set the GPIO pin for the NTC sensor
void ntc103_set_gpio_pin(int gpio_pin);

// Function to read NTC temperature
float ntc103_read_temperature();

#endif  // NTC103_H

