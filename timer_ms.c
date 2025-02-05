#include <stdio.h>
#include "pico/stdlib.h"

#define LED_RED_PIN 11    
#define LED_YELLOW_PIN 12 
#define LED_GREEN_PIN 13  


typedef enum {
    RED,
    YELLOW,
    GREEN
} TrafficLightState;

 TrafficLightState current_state = RED;

 void initialize_leds() {
    gpio_init(LED_RED_PIN);
    gpio_set_dir(LED_RED_PIN, GPIO_OUT);
    gpio_init(LED_YELLOW_PIN);
    gpio_set_dir(LED_YELLOW_PIN, GPIO_OUT);
    gpio_init(LED_GREEN_PIN);
    gpio_set_dir(LED_GREEN_PIN, GPIO_OUT);

     gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_YELLOW_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);
}

 bool repeating_timer_callback(struct repeating_timer *t) {
     gpio_put(LED_RED_PIN, 0);
    gpio_put(LED_YELLOW_PIN, 0);
    gpio_put(LED_GREEN_PIN, 0);

     switch (current_state) {
        case RED:
            gpio_put(LED_YELLOW_PIN, 1);  
            current_state = YELLOW;
            break;
        case YELLOW:
            gpio_put(LED_GREEN_PIN, 1);  
            current_state = GREEN;
            break;
        case GREEN:
            gpio_put(LED_RED_PIN, 1);  
            current_state = RED;
            break;
    }

    return true;  
}

int main() {
     
    stdio_init_all();

     
    initialize_leds();

     
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

     
    gpio_put(LED_RED_PIN, 1);

     
    while (true) {
         
        printf("Estado atual do semáforo: %d\n", current_state);
        sleep_ms(1000);  
    }

    return 0;
}