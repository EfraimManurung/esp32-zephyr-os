// src/main.c

#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>

// Define the LED pin. Adjust according to your ESP32 board.
#define LED_PIN 2

// Define the delay between LED toggles (in milliseconds).
#define SLEEP_TIME_MS 1000

void main(void) {
    // Get the device binding for GPIO.
    const struct device *dev = device_get_binding("GPIO_0");

    printk("MAIN PROGRAM START!!.\n");
    
    if (dev == NULL) {
        printk("Failed to get binding for GPIO device.\n");
        return;
    }

    // Configure the LED pin as an output.
    gpio_pin_configure(dev, LED_PIN, GPIO_OUTPUT_ACTIVE);

    while (1) {
        // Toggle the LED state.
        gpio_pin_toggle(dev, LED_PIN);

        // Print to the console for debugging purposes.
        printk("Toggled LED\n");

        // Sleep for the specified time.
        k_msleep(SLEEP_TIME_MS);
    }
}
