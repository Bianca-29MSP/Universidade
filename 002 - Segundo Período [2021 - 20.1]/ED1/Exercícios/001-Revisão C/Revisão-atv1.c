//Jogo - Pedra, Papel, Tesoura
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jogadaComputador();
char confereGanhadorRodada(int j, int c);

int main() {
    srand(time(NULL));
    int jogador;
    int computador;
    int rodadas = 5;
    int pontosJogador = 0;
    int pontosComputador = 0;
    printf("1 - Pedra\n2 - Papel\n3 - Tesoura\n");
    int i;
    for(i = 0; i < rodadas; i++) {
        scanf("%d", &jogador);
        computador = jogadaComputador();
        char vencedor = confereGanhadorRodada(jogador, computador);
        printf("[%d][%d]\n", jogador, computador);
        if(vencedor == 'j')
            pontosJogador++;
        else if(vencedor == 'c')
            pontosComputador++;
    }
    
    if(pontosJogador > pontosComputador)
        printf("You Win!");
    else if(pontosJogador < pontosComputador)
        printf("You Lose!");
    else
        printf("Empate.");
    
    return 0;
}

int jogadaComputador() {
    //De 1 até 3
    int jogada = (rand() % 3) + 1;
    return jogada;
}

char confereGanhadorRodada(int j, int c) {
    //Pedra
    if(j == 1) {
        if(c == 2) 
            return 'c';
        else if(c == 3) 
            return 'j';
        else 
            return '=';
    }
    //Papel
    else if(j == 2) {
        if(c == 1) 
            return 'j';
        else if(c == 3) 
            return 'c';
        else 
            return '=';
    }
    //Tesoura
    else {
        if(c == 1) 
            return 'c';
        else if(c == 2) 
            return 'j';
        else 
            return '=';
    }
}