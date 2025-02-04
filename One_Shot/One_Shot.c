#include <stdio.h> 
#include "pico/stdlib.h" 
#include "pico/time.h"  

const uint LED_PIN_R = 11;
const uint LED_PIN_B = 12;
const uint LED_PIN_G = 13;    
const uint BUTTON_PIN = 5;  // Define o pino GPIO 5 para ler o estado do botão.

volatile int status = 0;    // Lê o status dos 3 LEDs: status = 0 - leds apagados, status = 3 - todos os LEDs acesos

// Função de callback para desligar os LEDs após o tempo programado.
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
       if (status == 3) {
        // Após 3 segundos, desliga o LED vermelho e mantém os outros dois acesos.
        gpio_put(LED_PIN_R, false);
        status = 2;
    } else if (status == 2) {
        // Após mais 3 segundos, desliga o LED azul e mantém o LED verde aceso.
        gpio_put(LED_PIN_B, false);
        status = 1;
    } else if (status == 1) {
        // Após mais 3 segundos, desliga o LED verde.
        gpio_put(LED_PIN_G, false);
        status = 0;
    }

      if (status > 0) {
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
    // Retorna 0 para indicar que o alarme não deve se repetir.
    return 0;
}

int main() {
    stdio_init_all();

    // Configura os pinos dos LEDs como saídas
    gpio_init(LED_PIN_R);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_init(LED_PIN_B);
    gpio_set_dir(LED_PIN_B, GPIO_OUT);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);

    // Configura o pino do botão como entrada
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    while (true) {
        // Verifica se o botão foi pressionado (nível baixo no pino) e se os LEDs não estão acesos.
        if (gpio_get(BUTTON_PIN) == 0 && status == 0) {
            // Adiciona um pequeno atraso para debounce, evitando leituras errôneas.
            sleep_ms(50);

            // Verifica novamente o estado do botão após o debounce.
            if (gpio_get(BUTTON_PIN) == 0) {
                // Liga todos os LEDs (vermelho, azul e verde).
                gpio_put(LED_PIN_R, true);
                gpio_put(LED_PIN_B, true);
                gpio_put(LED_PIN_G, true);
                status = 3;  // Todos os LEDs acesos.

                // Agenda o alarme para desligar o LED após 3 segundos (3000 ms).
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(10);  // Pausa para reduzir o uso da CPU.
    }

    return 0;
}
