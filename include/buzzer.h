#ifndef BUZZER_H
#define BUZZER_H

#include "pico/stdlib.h"
#include "include/teclado.h"
#include "include/stateLeds.h"

// Definir o pino GPIO conectado ao buzzer
#define BUZZER_PIN 21

// Função para configurar o pino do buzzer
void setup_buzzer() {
    gpio_init(BUZZER_PIN);          // Inicializa o pino
    gpio_set_dir(BUZZER_PIN, GPIO_OUT); // Configura como saída
    gpio_put(BUZZER_PIN, 0);           // Garante que o buzzer comece desligado
}

// Função para gerar um som de uma determinada frequência (em Hz) no buzzer
void buzzer_beep(int frequency, int duration_ms) {
    int period = 1000000 / frequency;  // Calcula o período da frequência em microssegundos
    int cycles = (duration_ms * 1000) / period;  // Quantos ciclos de som em um tempo de duração

    for (int i = 0; i < cycles; i++) {
        gpio_put(BUZZER_PIN, 1);   // Liga o buzzer (HIGH)
        sleep_us(period / 2);       // Espera metade do período
        gpio_put(BUZZER_PIN, 0);   // Desliga o buzzer (LOW)
        sleep_us(period / 2);       // Espera a outra metade do período
        sleep_ms(5);                // Adiciona um pequeno atraso de 5ms entre os ciclos
    }
}

// Som para tecla 1
void sound_pattern_1(void) {
    gpio_put(LED_RED, 1);  // Liga o LED vermelho
    led_state_red = 1;     // Atualiza o estado
    buzzer_beep(800, 200);  // Frequência 800Hz por 200ms
    sleep_ms(100);          // Pausa entre os beeps
    buzzer_beep(800, 200);  // Frequência 800Hz por 200ms
    gpio_put(LED_RED, 0);  // Desliga o LED vermelho
    led_state_red = 0;     // Atualiza o estado
}

// Som para tecla 2
void sound_pattern_2(void) {
    gpio_put(LED_BLUE, 1);  // Liga o LED azul
    led_state_blue = 1;     // Atualiza o estado
    buzzer_beep(1000, 400); // Frequência 1000Hz por 400ms
    sleep_ms(50);           // Pausa entre os beeps
    buzzer_beep(1200, 300); // Frequência 1200Hz por 300ms
    gpio_put(LED_BLUE, 0);  // Desliga o LED azul
    led_state_blue = 0;     // Atualiza o estado
}

// Som para tecla 3
void sound_pattern_3(void) {
    for (int i = 0; i < 3; i++) {
        gpio_put(LED_GREEN, 1);  // Liga o LED verde
        led_state_green = 1;     // Atualiza o estado
        buzzer_beep(1400, 150); // Frequência 1400Hz por 150ms
        sleep_ms(100);          // Pausa entre os beeps
        gpio_put(LED_GREEN, 0);  // Desliga o LED verde
        led_state_green = 0;     // Atualiza o estado
    }
}

// toque 1 tecla 4
void ringtone_1(void) 
{
    gpio_put(LED_RED, 1);
    buzzer_beep(1000, 100);
    sleep_ms(100);
    gpio_put(LED_RED, 0);
    buzzer_beep(1200, 100); 
    sleep_ms(100);
    gpio_put(LED_RED, 1);
    buzzer_beep(1000, 100); 
    sleep_ms(200);
    gpio_put(LED_RED, 0);
    buzzer_beep(1200, 100); 
    sleep_ms(100);
    gpio_put(LED_RED, 1);
    buzzer_beep(1000, 100); 
    sleep_ms(400);
    gpio_put(LED_RED, 0);
}

void ringtone_2(void)
{
    gpio_put(LED_BLUE, 1);
    buzzer_beep(700, 150);
    sleep_ms(150);
    gpio_put(LED_BLUE, 0);
    buzzer_beep(900, 150);
    sleep_ms(150);
    gpio_put(LED_BLUE, 1);
    buzzer_beep(1100, 150);
    sleep_ms(150);
    gpio_put(LED_BLUE, 0);
    buzzer_beep(900, 150);
    sleep_ms(150);
    gpio_put(LED_BLUE, 1);
    buzzer_beep(700, 150);
    sleep_ms(500);
    gpio_put(LED_BLUE, 0);
}

void ringtone_3(void)
{
    gpio_put(LED_GREEN, 1);
    buzzer_beep(880, 200);
    sleep_ms(200);
    gpio_put(LED_GREEN, 0);
    buzzer_beep(1000, 200);
    sleep_ms(200);
    gpio_put(LED_GREEN, 1);
    buzzer_beep(880, 200);
    sleep_ms(200);
    gpio_put(LED_GREEN, 0);
    buzzer_beep(1000, 200);
    sleep_ms(200);
    gpio_put(LED_GREEN, 1);
    buzzer_beep(880, 200);
    sleep_ms(800);
    gpio_put(LED_GREEN, 0);
}

void ringtone_4(void)
{
    gpio_put(LED_RED, 1);
    buzzer_beep(600, 250);
    sleep_ms(250);
    gpio_put(LED_RED, 0);
    buzzer_beep(700, 250);
    sleep_ms(250);
    gpio_put(LED_RED, 1);
    buzzer_beep(800, 250);
    sleep_ms(250);
    gpio_put(LED_RED, 0);
    buzzer_beep(700, 250);
    sleep_ms(250);
    gpio_put(LED_RED, 1);
    buzzer_beep(600, 250);
    sleep_ms(500);
    gpio_put(LED_RED, 0);
}

void ringtone_5(void)
{
    gpio_put(LED_BLUE, 1);
    buzzer_beep(1300, 100);
    sleep_ms(100);
    gpio_put(LED_BLUE, 0);
    buzzer_beep(1200, 100);
    sleep_ms(100);
    gpio_put(LED_BLUE, 1);
    buzzer_beep(1100, 100);
    sleep_ms(100);
    gpio_put(LED_BLUE, 0);
    buzzer_beep(1200, 100);
    sleep_ms(100);
    gpio_put(LED_BLUE, 1);
    buzzer_beep(1300, 100);
    sleep_ms(350);
    gpio_put(LED_BLUE, 0);
}

void ringtone_6(void)
{
    gpio_put(LED_GREEN, 1);
    buzzer_beep(400, 150);
    sleep_ms(165);
    gpio_put(LED_GREEN, 0);
    buzzer_beep(500, 150);
    sleep_ms(165);
    gpio_put(LED_GREEN, 1);
    buzzer_beep(600, 150);
    sleep_ms(165);
    gpio_put(LED_GREEN, 0);
    buzzer_beep(500, 150);
    sleep_ms(165);
    gpio_put(LED_GREEN, 1);
    buzzer_beep(400, 150);
    sleep_ms(525);
    gpio_put(LED_GREEN, 0);
}

void ringtone_7(void)
{
    gpio_put(LED_RED, 1);
    buzzer_beep(700, 200);
    sleep_ms(200);
    gpio_put(LED_RED, 0);
    buzzer_beep(900, 200);
    sleep_ms(200);
    gpio_put(LED_RED, 1);
    buzzer_beep(1000, 200);
    sleep_ms(200);
    gpio_put(LED_RED, 0);
    buzzer_beep(900, 200);
    sleep_ms(200);
    gpio_put(LED_RED, 1);
    buzzer_beep(700, 200);
    sleep_ms(600);
    gpio_put(LED_RED, 0);
}

#endif // BUZZER_H