#include "../partida/atualizar_partida.h"
#include "../system/system.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void printBDPartidas(bdPartidas *bdp) {

    printf("ID   Time1        Time2        Placar1  Placar2\n");

    for (Partida *p = bdp->first; p != NULL; p = p->next) {

        printf("%-4d %-12s %-12s %-8d %-8d\n",
               p->id,
               p->Time1,     
               p->Time2,    
               p->GolsTime1,
               p->GolsTime2);
    }
}
