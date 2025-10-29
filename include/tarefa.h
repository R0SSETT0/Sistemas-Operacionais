#ifndef TAREFA_H
#define TAREFA_H

typedef struct{
    char *id;
    int tempo_inicio; 
    int duracao;
    int prioridade;
    char cor[32]; //Cor pra definir no grafico de Gantt
}Tarefa;

#endif