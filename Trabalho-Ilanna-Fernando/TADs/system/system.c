#include "system.h"
#include "consultar_time.h"
#include "consultar_partida.h"
#include "imprimir_classificacao.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

// Menu do programa (Interface)
void lobby(bdTimes *bdt, bdPartidas *bdp) {  
    setlocale(LC_ALL, "");
    printf("Escolha 1 opcao:\n\n");
    printf("---------------------\n\n");
    printf("1: Consultar Time\n");
    printf("2: Consultar Partidas\n");
    printf("3: Imprimir Tabela de Classificação\n");
    printf("4 - Sair do programa\n");
    printf("---------------------\n\n");
    char option[5];
    scanf("%s", &option); // lê a opção digitada pelo usuário
    if (strcmp(option, "1") == 0) {
        LimpaTela();
        ConsultarTime(bdt, bdp);
        sleep(1.5);
        printf("---------------------\n\n");
        lobby(bdt,bdp);
    } 
    else if (strcmp(option, "2") == 0) {
        LimpaTela();
        ConsultarPartida(bdt, bdp);
        sleep(1.5);
        printf("---------------------\n\n");
        lobby(bdt, bdp);
    } 
    else if (strcmp(option, "3") == 0) {
        LimpaTela();
        Classificacao(bdt, bdp);
        sleep(1.5);
        printf("---------------------\n\n");
        lobby(bdt, bdp);
    }
    else if (strcmp(option, "4") == 0) {
        LimpaTela();
        printf("Saindo do programa...\n");
        return;
    }
    else {
        LimpaTela();
        printf("Digite uma opção válida\n");
        printf("---------------------\n\n");
        lobby(bdt, bdp);
    }
}

