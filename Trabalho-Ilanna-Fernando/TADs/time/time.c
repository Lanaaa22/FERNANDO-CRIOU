#include "tad_time.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct time {
    int id; //id dos times
    char nome[50]; //nome do time
};

#define MAX_TIMES 45 // 10 times, turno único: (10 * 9) / 2 = 45 jogos

struct bdtimes {
    Time *t[MAX_TIMES];
    int qtd;
};

// Função que carrega arquivo time.csv
void extraiArquivoTimes(bdTimes *bdt) {
    FILE *file = fopen("arquivos/times.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Time *novoTime; 
    char linha[255];
    fgets(linha, sizeof(linha), file); //ler o indice (pula o índice)
    while (fgets(linha, sizeof(linha), file) != NULL) {
        novoTime = (Time *)malloc(sizeof(Time));
        if (novoTime == NULL) {
        printf("Erro ao alocar memória");
    }
        sscanf(linha, "%d ,%49[^\n]", &novoTime->id, novoTime->nome);
        inserirBDtimes(novoTime, bdt);
    }
    fclose(file);
}

// Função que insere um novo time (do arquivo times.csv) na struct bdtime
void inserirBDtimes(Time *novoTime, bdTimes *bdt) {
    bdt->t[bdt->qtd] = novoTime;
    bdt->qtd++;
}

// Cria e aloca memória para o estrutura BDTime
bdTimes *createBDTimes() 
{
   bdTimes *bd = (bdTimes *)malloc(sizeof(bdTimes)); 
    if (bd == NULL) {
        printf("Erro ao alocar memória");
    }
   bd->qtd = 0;                                         
   for (int i = 0; i<MAX_TIMES; i++) {
        bd->t[i] = NULL;   
   }                                  
   

   return bd; 
}

// Imprime bdTimes
void printBDTimes(bdTimes *bd) {
    for (int i = 0; i < bd->qtd; i++) {
        printf("Time %d:\n", i + 1);
        printf("  ID: %d\n", bd->t[i]->id);
        printf("  Nome: %s\n", bd->t[i]->nome);
    }
}

// Libera memória de BDTimes
void liberaBDTimes(bdTimes *bd) {
    for(int i=0; i<bd->qtd; i++) {
        free(bd->t[i]);
    }
    free(bd);
}

// Retorna a quantidade de times
int getQtdTimes(bdTimes *bdt) {
    return bdt->qtd;
}

// Retorna o ID do time de acordo com o índice
int getIDTime(bdTimes *bdt, int i) { 
    return bdt->t[i]->id;
}

// Retorna o nome do time de acordo com o índice
char* getNomeTime(bdTimes *bdt, int i) { 
    return bdt->t[i]->nome;
}

