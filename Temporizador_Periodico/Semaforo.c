#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

volatile int status = 0;

bool repeating_timer_callback(struct repeating_timer *t){

    if(status == 0){
        gpio_put(LED_PIN_RED, false);
        gpio_put(LED_PIN_YELLOW, true);
        status = 1;
    } else if (status == 1){
        gpio_put(LED_PIN_YELLOW, false);
        gpio_put(LED_PIN_GREEN ,true);
        status = 2;
    } else if(status == 2){
        gpio_put(LED_PIN_GREEN, false);
        gpio_put(LED_PIN_RED, true);
        status = 0;
    }
   return true; 
}

int main()
{
    stdio_init_all();

    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);

    gpio_put(LED_PIN_RED, true);
    //sleep_ms(3000);
    
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);


    while (true) {
        printf("Estado atual: %d\n", status);
        sleep_ms(1000);
    }
}
