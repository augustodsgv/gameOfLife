/*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "gameOfLife.h"

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
   return 0;
}