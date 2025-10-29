#ifndef TAREFA_H
#define TAREFA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *id;
    int tempo_inicio; 
    int duracao;
    int prioridade;
    char *cor; //Cor pra definir no grafico de Gantt
}Tarefa;

Tarefa* tarefa_criar();
void tarefa_apagar(Tarefa* tarefa);
#endif