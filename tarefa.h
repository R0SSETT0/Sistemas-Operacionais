#ifndef TAREFA_H
#define TAREFA_H

typedef struct{
    int id;
    int chegada; 
    int duracao;
    int prioridade;
    char cor[32]; //Cor pra definir no grafico de Gantt
}Tarefa;

#endif