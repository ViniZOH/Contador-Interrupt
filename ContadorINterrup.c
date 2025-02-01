#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"

//Arquivo .pio

#include "ContadorINterrup.pio.h"

// Bibliotecas criadas para o projeto
#include "bibliotecas/control_leds.h"
#include "bibliotecas/numeros.h"

#define LED_VERMELHO 13
#define BOTAO_A 5
#define BOTAO_B 6
#define MATRIZ 7

//Criação do prototipo da função de interrupção
static void gpio_irq_handler(uint gpio, uint32_t events);

//Objetos globais
PIO pio = pio0;
uint sm; 
volatile int contador = 0;
static volatile uint32_t last_time = 0; // Armazena o tempo do último evento (em microssegundos)

int main()

{   
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO,GPIO_OUT);

    gpio_init(BOTAO_A);
    gpio_set_dir(BOTAO_A,GPIO_IN);
    gpio_pull_up(BOTAO_A);

    gpio_init(BOTAO_B);
    gpio_set_dir(BOTAO_B,GPIO_IN);
    gpio_pull_up(BOTAO_B);

    //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    bool ok = set_sys_clock_khz(128000, false);

    // Inicializa todos os códigos stdio padrão que estão ligados ao binário.
    stdio_init_all();

    //configurações da PIO
    uint offset = pio_add_program(pio, &ContadorINterrup_program);
    uint sm = pio_claim_unused_sm(pio, true);
    ContadorINterrup_program_init(pio, sm, offset, MATRIZ);


 exibir_numero(pio, sm, contador);

    //Configuração da interrupão com callback incremento
    gpio_set_irq_enabled_with_callback(BOTAO_A,GPIO_IRQ_EDGE_FALL,true, &gpio_irq_handler);
    //Configuração da interrupão com callback decremento
    gpio_set_irq_enabled_with_callback(BOTAO_B,GPIO_IRQ_EDGE_FALL,true, &gpio_irq_handler);

    while (true) {
        for (int i =0; i < 5; i++) {
            gpio_put(LED_VERMELHO,1);
            sleep_ms(100);
            gpio_put(LED_VERMELHO,0);
            sleep_ms(100);
        }
    }
}
// Função de interrupção
void gpio_irq_handler(uint gpio, uint32_t events) {

    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    if (current_time - last_time > 250000) // 250 ms de debouncing
    {
        last_time = current_time; // Atualiza o tempo do último evento

           //Indicação visual: LED vermelho pisca 5 vezes em 1 segundo 200ms*5= 1s 
    //Descomente essa linha se quiser que o LED pisque antes de incrementar o numero. Comentar o código na main.
    // for (int i = 0; i < 5; i++) {
    //     gpio_put(LED_VERMELHO, 1);  // Liga o LED
    //     busy_wait_us_32(100000);              // Mantém ligado por 100 ms
    //     gpio_put(LED_VERMELHO, 0);  // Desliga o LED
    //     busy_wait_us_32(100000);              // Mantém desligado por 100 ms
    // }
    
    // Verifica qual botão acionou a interrupção
    if (gpio == BOTAO_A && contador < 9) {
        contador++;  // Incrementa o contador
    } else if (gpio == BOTAO_B && contador > 0) {
        contador--;  // Decrementa o contador
    }

    // Atualiza o display com o novo número
    exibir_numero(pio, sm, contador);

}


    }

 
