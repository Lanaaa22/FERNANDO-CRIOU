#ifndef ATUALIZAR_PARTIDA_H
#define ATUALIZAR_PARTIDA_H

#include "../time/time.h"
#include "../partida/partida.h"

void MostrarPartidas(bdPartidas *bdp, bdTimes *bdt);
char *nomeID(int id, bdTimes *bdt);
void AtualizarPartida(bdTimes *bdt, bdPartidas *bdp);
//AtualizarPartidaArquivo(IDtime1, IDtime2, placar1, placar2);
void AtualizarPartidaLista(int idAtualizado, int placar1, int placar2, bdPartidas *bdp);
int golsID2(bdPartidas *bdp, int id);
int golsID1(bdPartidas *bdp, int id);
#endif