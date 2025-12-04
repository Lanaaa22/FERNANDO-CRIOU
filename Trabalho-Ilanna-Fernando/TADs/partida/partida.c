#include "tad_partida.h"
#include "tad_time.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct partida {
    int id;          // Identificador da partida
    int Time1id;     // ID do primeiro time
    int Time2id;     // ID do segundo time
    int GolsTime1;   // Gols marcados pelo primeiro time
    int GolsTime2;   // Gols marcados pelo segundo time
};

#define MAX_PARTIDAS 90 // 10 times, turno único: (10 * 9) / 2 = 45 jogos (Mas por um erro de criação do arquivo, ele possui 90 partidas)

struct bdpartida {
    Partida *p[MAX_PARTIDAS];
    int qtd;
};

//Função que carrega arquivo partidas
void extraiArquivoPartidas(bdPartidas *bdp) {
    FILE *file = fopen("arquivos/partidas_completo.csv", "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    Partida *novaPartida;
    char linha[255];
    fgets(linha, sizeof(linha), file); //ler o indice (pula o índice)
    while (fgets(linha, sizeof(linha), file) != NULL) {
        novaPartida = (Partida *)malloc(sizeof(Partida));
        if (novaPartida == NULL) {
            printf("Erro ao alocar memória");
        }
        sscanf(linha, "%d, %d, %d, %d, %d", &novaPartida->id, &novaPartida->Time1id, &novaPartida->Time2id, &novaPartida->GolsTime1, &novaPartida->GolsTime2);
        inserirBDPartidas(novaPartida, bdp);
    }
    fclose(file);
}

// Insere a partida no bdPartidas
void inserirBDPartidas(Partida *novaPartida, bdPartidas *bdp) {
    if (bdp->qtd >= MAX_PARTIDAS) {
        printf("Erro ao inserir mais partidas");
        return;
    } else {
        bdp->p[bdp->qtd] = novaPartida;
        bdp->qtd++;
    }

}

// Cria e aloca memória pra bdPartidas
bdPartidas *createBDPartidas() {
    bdPartidas *bd = (bdPartidas *)malloc(sizeof(bdPartidas));
    if (bd == NULL) {
        printf("Erro ao alocar memória");
    }
    bd->qtd = 0;
       for (int i = 0; i<MAX_PARTIDAS; i++) {
        bd->p[i] = NULL;   
    }
    return bd;
}

// Imprime as informações bdPartidas
void printBDPartidas(bdPartidas *bd) {
    for (int i = 0; i < bd->qtd; i++) {
        printf("Partida %d:\n", i + 1);
        printf("  ID: %d\n", bd->p[i]->id);
        printf("  ID do time 1: %d\n", bd->p[i]->Time1id);
        printf("  ID do time 2: %d\n", bd->p[i]->Time2id);
        printf("  Gols do time 1: %d\n", bd->p[i]->GolsTime1);
        printf("  Gols do time 2: %d\n", bd->p[i]->GolsTime2);
    }

}

// Libera memória ocupada por bdPartidas
void liberaBDPartidas(bdPartidas *bd) {
    for(int i=0; i<bd->qtd; i++) {
        free(bd->p[i]);
    }
    free(bd);
}

// Retorna a quantidade de partidas de bdPartidas
int getQtdPartidas(bdPartidas *bdp) {
    return bdp->qtd;
}

// Retorna o ID do time Mandante
int getTime1ID(bdPartidas *bdp, int i) {
    return bdp->p[i]->Time1id;
}

// Retorna o ID do time Visitante
int getTime2ID(bdPartidas *bdp, int i) {
    return bdp->p[i]->Time2id;
}

// Retorna os Gols do time Mandante
int getGolsTime1(bdPartidas *bdp, int i) {
    return bdp->p[i]->GolsTime1;
}

// Retorna os Gols do time Visitante
int getGolsTime2(bdPartidas *bdp, int i) {
    return bdp->p[i]->GolsTime2;
}

// Retorna o ID da Partida de acordo com o índice
int getPartidaID(bdPartidas *bdp, int i) {
    return bdp->p[i]->id;
}