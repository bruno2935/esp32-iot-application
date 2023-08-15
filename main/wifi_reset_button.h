#ifndef WIFI_RESET_BUTTON_H
#define WIFI_RESET_BUTTON_H

// Default interrupt flah
#define ESP_INTR_FLAG_DEFAULT		0

#define WIFI_RESET_BUTTON			0

/**
 * Configures Wifi reset button and interrupt configuration
 */
void wifi_reset_button_config(void);


#endif /* WIFI_RESET_BUTTON_H */
