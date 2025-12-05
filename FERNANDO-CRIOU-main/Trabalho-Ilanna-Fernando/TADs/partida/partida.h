#ifndef TAD_PARTIDA_H
#define TAD_PARTIDA_H

//Definição do dado Partida para representar uma informação de partida
typedef struct partida Partida;

//Definição do dado bdPartida para representar uma informação de bdpartida
typedef struct bdpartida bdPartidas;

// Função que extrai dados do arquivo
void extraiArquivoPartidas(bdPartidas *bd);

// Função que insere nova partida em bdPartidas
void inserirBDPartidas(Partida *novaPartida, bdPartidas *bdp);

// Cria e aloca memória de bdPartida
bdPartidas *createBDPartidas();

// Imprime bdPartida
void printBDPartidas(bdPartidas *bd);

// Libera memória de bdPartida
void liberaBDPartidas(bdPartidas *bd);

// Funções para acessar dados de bdPartidas
int getQtdPartidas(bdPartidas *bdp);
int getTime1ID(bdPartidas *bdp, int i);
int getTime2ID(bdPartidas *bdp, int i);
int getGolsTime1(bdPartidas *bdp, int i);
int getGolsTime2(bdPartidas *bdp, int i);
int getPartidaID(bdPartidas *bdp, int i);
#endif