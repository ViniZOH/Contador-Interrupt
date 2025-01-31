//Vão ser declarados os frames e cores da animação 1
#ifndef NUMEROS_H
#define NUMEROS_H
#include "control_leds.h"
//Exemplo de como definir as cores de cada led:
/*(os números indicam a intensidade da cor caso o led epecífico seja ligado, vc pode misturar as 
intensidades de red, green ou blue pra atingir outras cores;
Você pode deixar todas da mesma cor ou alterar a cor de cada led individualmente).*/

double numeros_red[25] =     {0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1, 
                            0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1,
                            0.1, 0.1, 0.1, 0.1, 0.1};

double numeros_green[25] =   {0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 
                            0.0, 0.0, 0.0, 0.0, 0.0,
                            0.1, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0};

double numeros_blue[25] =    {0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0, 
                            0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0,
                            0.0, 0.0, 0.0, 0.0, 0.0};




//exemplo de frame (Aqui vc desenha)
//Numeros de 0 a 9
// Número 0
uint numero_0[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

// Número 1
uint numero_1[25] = {
    0, 0, 1, 0, 0,
    0, 1, 1, 0, 0,
    1, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    1, 1, 1, 1, 1
};

// Número 2
uint numero_2[25] = {
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1
};

// Número 3
uint numero_3[25] = {
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

// Número 4
uint numero_4[25] = {
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 0, 1
};

// Número 5
uint numero_5[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

// Número 6
uint numero_6[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 0,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

// Número 7
uint numero_7[25] = {
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    0, 0, 0, 1, 0,
    0, 0, 1, 0, 0,
    0, 1, 0, 0, 0
};

// Número 8
uint numero_8[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

// Número 9
uint numero_9[25] = {
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 1,
    1, 1, 1, 1, 1
};

                                        
// Rodar animação:
// Função para exibir o número correspondente
void exibir_numero(PIO pio, uint sm, uint contador) {
    switch (contador) {
        case 0:
            put_leds(numero_0, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 1:
            put_leds(numero_1, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 2:
            put_leds(numero_2, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 3:
            put_leds(numero_3, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 4:
            put_leds(numero_4, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 5:
            put_leds(numero_5, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 6:
            put_leds(numero_6, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 7:
            put_leds(numero_7, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 8:
            put_leds(numero_8, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        case 9:
            put_leds(numero_9, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
        default:
            // Se o número estiver fora do intervalo, não faz nada ou limpa a matriz
            put_leds(numero_0, numeros_red, numeros_green, numeros_blue, contador, pio, sm);
            break;
    }
}

#endif //ANIM_H