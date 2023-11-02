#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "myStr.h"

#define tamanhoCampo 10

typedef struct field{
    int sizeOfField;
    int ** matriz;
}field;

// Função que printa o campo de forma mais completa
void printCampo(field campo){
    for(int i = 0; i < campo.sizeOfField; i++){
        for(int j = 0; j < campo.sizeOfField; j++)
            printf("+---");
        printf("+\n");
        for(int j = 0; j < campo.sizeOfField; j++)
            printf("| %c ", campo.matriz[i][j] ? '@' : ' ');
        printf("|\n");
    }
    for(int j = 0; j < campo.sizeOfField; j++)
        printf("+---");
    printf("+\n");
}

// Função que printa o campo mas numa "resolução" mais baixa
void printCampoSimplificado(field campo){
    printf("\n+");
    for(int i = 0; i < campo.sizeOfField + 1; i++)
        printf("--");
    printf("+\n");
    for(int i = 0; i < campo.sizeOfField; i++){
        printf("| ");
        for(int j = 0; j < campo.sizeOfField; j++)
            printf("%c ", campo.matriz[i][j] ? '@' : ' ');
        printf(" |\n");
    }
    printf("+");
    for(int i = 0; i < campo.sizeOfField + 1; i++)
        printf("--");
    printf("+\n");
}


// Função que inicializa os parâmetros e o vetor do campo
void alocaMatrizCampo(field * campo){
    campo->matriz = (int**)malloc(sizeof(int*) * campo->sizeOfField);
    for(int i = 0; i < campo->sizeOfField; i++)
        campo->matriz[i] = (int *)malloc(sizeof(int) * campo->sizeOfField);
}

// TODO!!! resolver essa função
// Função que povoa a matriz do campo.
// A escala de criação vai de 0, onde nenhum indivídio é criado, até 20, onde a população é total
void povoaCampoAleatorio(field * campo, int populationScale){
    if (populationScale > 20 || populationScale < 0){
        printf("Campo não povoado: escala de criação fora do limite [0, 20]");
    }else{
        srand(time(NULL));
        for(int i = 0; i < tamanhoCampo; i++)
            for(int j = 0; j < tamanhoCampo; j++)
               campo->matriz[i][j] = rand() % (populationScale - 19);
    }
}



void povoaCampoArquivo(field * campo, char nomeArquivo[]){
    FILE * arquivo = fopen(nomeArquivo, "r");
    char input;
    campo->sizeOfField = 0;     // Iniciando com 0

    while(1){
        fread(&input, sizeof(char), 1, arquivo);       // Pegando informações do tamanho do campo
        if(input == '\n') break;
        // Vai multiplicando por 10 pois o campo mais a esquerda vai crescendo sua magnitude
        campo->sizeOfField = campo->sizeOfField * 10 + charToInt(input);
    }
    alocaMatrizCampo(campo);
    // Alocando o vetor
    campo->matriz = (int**)malloc(sizeof(int*) * campo->sizeOfField);       
    for(int i = 0; i < campo->sizeOfField; i++)
        campo->matriz[i] = (int*)malloc(sizeof(int) * campo->sizeOfField);
    
    // Percorrendo o arquivo e atribuindo os valores
    for(int i = 0; i < campo->sizeOfField; i++){
        for(int j = 0; j < campo->sizeOfField; j++){
            do{
                fread(&input, sizeof(char), 1, arquivo);
            }while(input == '\n' || input == ' ');          // Tratando os valores de espaço e fim de linha
            campo->matriz[i][j] = charToInt(input);
            // printf("[%d][%d] = %d\n", i, j, charToInt(input));
        }  
    }
}



// Simula um ciclo. Neste, é olhada a perspectiva de cada célula, que olha os vizinhos ao seu redor
// Há 3 regras:
// Qualquer célula viva com menos de 2 células vizinhas vivas morre
// Qualquer célula viva com mais de 3 células vizinhas morre
// Qualquer célula viva com 2 ou 3 células vizinhas permanece viva
// Qualquer célula morta com exatos 3 vizinhos volta a vida
void simulaCicloA(field * campo){
    int ** matrizAux = (int**)malloc(sizeof(int*) * campo->sizeOfField);    // Matriz que será calculada com base no campo atual
    for(int i = 0; i < campo->sizeOfField; i++)
        matrizAux[i] = (int*)malloc(sizeof(int) * campo->sizeOfField);

    for(int i = 0; i < campo->sizeOfField; i++)
        for(int j = 0; j < campo->sizeOfField; j++){
            int nNeigh = 0;         // Contador de vizinhos
            for(int k = i - 1; k <= i + 1; k++){            // Percorrendo o loop dos vizinhos
                if(k < 0 || k >= campo->sizeOfField)   break;          // Usando um break somente para não rodar iterações desnecessárias em casos onde a célula está na borda
                for(int l = j - 1; l <= j + 1; l++){
                    if(l < 0 || l >= campo->sizeOfField)    break;
                    if(k != i || l != j)        // Não se pode incluir a própria célula na conta dos vizinhos
                        nNeigh += campo->matriz[k][l];      // Como já é binário, usa-se assim pra evitar mais uma conta
                }
            }
            // printf("[%d][%d] = %d\n", i, j, nNeigh);
            // Contados os vizinhos, agora é preciso decidir se as céluas vivem, morrem ou renascem
            if (campo->matriz[i][j])            // Caso esteja viva
                if(nNeigh < 2 || nNeigh > 3)      // Caso esteja fora da zona habitável, morre
                    matrizAux[i][j] = 0;
                else    
                    matrizAux[i][j] = 1;
            else                              // Caso esteja morta
                if(nNeigh == 3)
                    matrizAux[i][j] = 1;
        }

    // free(campo->matriz);
    campo->matriz = matrizAux;
}


int main(int argc, char * argv[]){
    field campo;

    if(argc < 2){
        povoaCampoArquivo(&campo, "fases/theGlider.txt");
    }else{
        char nomeArquivo[50];
        strcat(nomeArquivo, "fases/");
        strcat(nomeArquivo, argv[1]);
        strcat(nomeArquivo, ".txt");
        printf("%s", nomeArquivo);
        povoaCampoArquivo(&campo, nomeArquivo);
    }
    
    while(1){
        printCampoSimplificado(campo);
        simulaCicloA(&campo);
        // getchar();
        sleep(1);
    }
    // */
   return 0;
}