<<<<<<< HEAD
#ifndef TAREFA_H
#define TAREFA_H

typedef struct{
    char *id;
    int tempo_inicio; 
    int duracao;
    int prioridade;
    char cor[32]; //Cor pra definir no grafico de Gantt
}Tarefa;

=======
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
>>>>>>> 1260a52b8ee27f8ab54dceda4c586c1b179425a4
#endif