#include "../time/time.h"
#include "../partida/partida.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct partida {
    int id;          // Identificador da partida
    int Time1id;     // ID do primeiro time
    int Time2id;     // ID do segundo time
    int GolsTime1;   // Gols marcados pelo primeiro time
    int GolsTime2;   // Gols marcados pelo segundo time
    Partida *next;
    Partida *prev;
};

struct bdpartida {
    Partida *first;
    Partida *last;
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
    novaPartida->next = bdp->first;
    novaPartida->prev = NULL;
    if (bdp->qtd != 0) {
        bdp->first->prev = novaPartida;
    } else {
        bdp->last = novaPartida;
    }
    bdp->first = novaPartida;
    bdp->qtd++;
}

// Cria e aloca memória pra bdPartidas
bdPartidas *createBDPartidas() {
    bdPartidas *bd = (bdPartidas *)malloc(sizeof(bdPartidas));
    if (bd == NULL) {
        printf("Erro ao alocar memória");
    }
    bd->qtd = 0;
    bd->first = NULL;
    bd->last = NULL;
    return bd;
}

// Imprime as informações bdPartidas
void printBDPartidas(bdPartidas *bd) {
    int cont = 0;
    for (Partida *p = bd->first; p != NULL; p = p->next) {
        printf("Partida %d:\n", cont + 1);
        printf("  ID: %d\n", p->id);
        printf("  ID do time 1: %d\n", p->Time1id);
        printf("  ID do time 2: %d\n", p->Time2id);
        printf("  Gols do time 1: %d\n", p->GolsTime1);
        printf("  Gols do time 2: %d\n", p->GolsTime2);
        cont++;
    }

}

// Libera memória de BDpartidas
void liberaBDPartidas(bdPartidas *bd) {
    Partida *p = bd->first;
    Partida *t;
    while (p != NULL) {
        t = p->next;
        free(p);
        p = t;
    }
    free(bd);
}
// Retorna a quantidade de partidas de bdPartidas
int getQtdPartidas(bdPartidas *bdp) {
    return bdp->qtd;
}

// Retorna o ID do time Mandante
int getTime1ID(bdPartidas *bdp, int i) {
    Partida *p = bdp->first;
    int cont = 0;
    while(p != NULL && cont < i) {
        p = p->next;
        cont++;
    }
    if(p == NULL) {
        return 1;
    }
    return p->Time1id;
}

// Retorna o ID do time Visitante
int getTime2ID(bdPartidas *bdp, int i) {
    Partida *p = bdp->first;
    int cont = 0;
    while(p != NULL && cont < i) {
        p = p->next;
        cont++;
    }
    if(p == NULL) {
        return 1;
    }
    return p->Time2id;
}

// Retorna os Gols do time Mandante
int getGolsTime1(bdPartidas *bdp, int i) {
    Partida *p = bdp->first;
    int cont = 0;
    while(p != NULL && cont < i) {
        p = p->next;
        cont++;
    }
    if(p == NULL) {
        return 1;
    }
    return p->GolsTime1;
}

// Retorna os Gols do time Visitante
int getGolsTime2(bdPartidas *bdp, int i) {
    Partida *p = bdp->first;
    int cont = 0;
    while(p != NULL && cont < i) {
        p = p->next;
        cont++;
    }
    if(p == NULL) {
        return 1;
    }
    return p->GolsTime2;
}

// Retorna o ID da Partida de acordo com o índice
int getPartidaID(bdPartidas *bdp, int i) {
    Partida *p = bdp->first;
    int cont = 0;
    while(p != NULL && cont < i) {
        p = p->next;
        cont++;
    }
    if(p == NULL) {
        return 1;
    }
    return p->id;
}