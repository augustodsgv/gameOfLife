/*
Programa: gameOfLife.h
Descrição: Conway game of life implementation
Author: Augusto dos Santos
Data: 02/11/2023
*/

#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

typedef struct field{
    int sizeOfField;
    int ** matriz;
}field;

// Display
void printCampo(field campo);       // Printa na tela o campo
void printCampoSimplificado(field campo);       // Printa o campo de forma mais simplificada

// Criação de fase
void alocaMatrizCampo(field * campo);
void povoaCampoAleatorio(field * campo, int populationScale);       // Cria um campo de forma aleatório. BUGADO
void povoaCampoArquivo(field * campo, char nomeArquivo[]);          // Cria um campo de acordo com o arquivo passado

// Simulação
void simulaCicloA(field * campo);                                   // Simula um ciclo de interação entre as células


#endif /*GAME_OF_LIFE_H*/