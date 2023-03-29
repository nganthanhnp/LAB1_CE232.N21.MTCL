#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

static const char *TAG = "example";
#define LED_GPIO 2

static void blink_led(void)
{
    static bool led_state = 0;
    
    /* Toggle the LED state */
    led_state = !led_state;

    /* Set the GPIO level according to the state (LOW or HIGH)*/
    gpio_set_level(LED_GPIO, led_state);

    /* Print the LED state to the console */
    ESP_LOGI(TAG, "LED state: %s", led_state ? "ON" : "OFF");
}

void app_main(void)
{
    /* Configure the GPIO as a push/pull output */
    gpio_reset_pin(LED_GPIO);
    gpio_set_direction(LED_GPIO, GPIO_MODE_OUTPUT);
    while (1) {
        blink_led();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}