#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/adc.h"
#include "config_matriz.h"
#include "pio_matrix.pio.h"
#include "init_GPIO.h"

// Configurações do Joystick
#define JOYSTICK_X_PIN 27    // ADC0 (GP26)
#define JOYSTICK_Y_PIN 26    // ADC1 (GP27)
#define THRESHOLD_LOW 1500
#define THRESHOLD_HIGH 2500

// Enumeração das direções
typedef enum {
    DIR_NEUTRO,
    DIR_ESQUERDA,
    DIR_DIREITA,
    DIR_CIMA,
    DIR_BAIXO
} Direcao;

void init_joystick() {
    adc_init();
    adc_gpio_init(JOYSTICK_X_PIN);
    adc_gpio_init(JOYSTICK_Y_PIN);
}

Direcao ler_direcao() {
    // Ler eixo X (esquerda/direita)
    adc_select_input(1);
    uint16_t x = adc_read();
    
    // Ler eixo Y (cima/baixo)
    adc_select_input(0);
    uint16_t y = adc_read();

    // Valores típicos para joystick analógico (12-bit):
    if(x < THRESHOLD_LOW) return DIR_DIREITA;   // X para direita
    if(x > THRESHOLD_HIGH) return DIR_ESQUERDA;   // X para esquerda
    if(y < THRESHOLD_LOW) return DIR_BAIXO;       // Y para baixo
    if(y > THRESHOLD_HIGH) return DIR_CIMA;     // Y para cima
    
    return DIR_NEUTRO;
}

void mostrar_direcao(Direcao dir, PIO pio, uint sm) {
    switch(dir) {
        case DIR_ESQUERDA:
            desenho_pio(seta_esquerda, valor_led, pio, sm, 0.0, 0.0, 0.35);  // Azul (B=0.35)
            break;
        case DIR_DIREITA:
            desenho_pio(seta_direita, valor_led, pio, sm, 0.0, 0.0, 0.35);   // Azul
            break;
        case DIR_CIMA:
            desenho_pio(seta_cima, valor_led, pio, sm, 0.0, 0.0, 0.35);      // Azul
            break;
        case DIR_BAIXO:
            desenho_pio(seta_baixo, valor_led, pio, sm, 0.0, 0.0, 0.35);     // Azul
            break;
        default:
            desenho_pio(apagar_leds, valor_led, pio, sm, 0.0, 0.0, 0.0);    // Apagar
    }
}

int main() {
    stdio_init_all();
    init_gpio();
    init_joystick();

    PIO pio = pio0;
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    while(1) {
        Direcao direcao = ler_direcao();
        mostrar_direcao(direcao, pio, sm);
        sleep_ms(50);
    }
}