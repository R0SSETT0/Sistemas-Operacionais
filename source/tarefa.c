#include "tarefa.h"


Tarefa* tarefa_criar(){
    Tarefa* nova_tarefa = (Tarefa*)malloc(sizeof(Tarefa));
    if (nova_tarefa == NULL){
        printf("Erro na criação da tarefa\n");
        return NULL;
    }

    nova_tarefa->id = "";
    nova_tarefa->tempo_inicio = 0;
    nova_tarefa->duracao = 0;
    nova_tarefa->prioridade = 0;
    nova_tarefa->cor = "";
    return nova_tarefa;
}