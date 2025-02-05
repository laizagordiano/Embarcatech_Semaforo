#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição das GPIOs para o LED RGB
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Mudar o estado dos LEDs
    if (gpio_get(LED_RED)) { 
        gpio_put(LED_RED, 0);    // Desliga o LED vermelho
        gpio_put(LED_YELLOW, 1); // Liga o LED amarelo
    } else if (gpio_get(LED_YELLOW)) { 
        gpio_put(LED_YELLOW, 0); // Desliga o LED amarelo
        gpio_put(LED_GREEN, 1);  // Liga o LED verde
    } else {
        gpio_put(LED_GREEN, 0);  // Desliga o LED verde
        gpio_put(LED_RED, 1);    // Liga o LED vermelho
    }

    return true; // Retorna true para repetir a chamada
}

void setup() {
    // Inicializa as GPIOs dos LEDs
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
}

int main() {
    stdio_init_all();
    setup();
    // Inicializa o temporizador
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); // 3 segundos de intervalo

    // Inicializa o semáforo na cor vermelha
    gpio_put(LED_RED, 1);    // Liga o LED vermelho
    gpio_put(LED_YELLOW, 0); // Desliga o LED amarelo
    gpio_put(LED_GREEN, 0);  // Desliga o LED verde

    // Loop principal
    while (true) {
        // A cada 1 segundo, imprimir uma mensagem via serial
        printf("Semáforo funcionando!\n");
        sleep_ms(1000); // Atraso de 1 segundo
    }

    return 0;
}
