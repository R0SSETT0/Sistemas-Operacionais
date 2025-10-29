#ifndef TCB_H
#define TCB_H

#include <stdio.h>
#include "tarefa.h"

typedef enum{
    NOVA,
    PRONTA,
    EXECUTANDO,
    FINALIZADA
}Status;

typedef struct tcb{
    Tarefa tarefa;
    Status status;
    int tempo_executado;
    int tempo_restante;
    int tempo_fim;
    struct tcb* proximo;

}TCB;

TCB* tcb_criar();
void tcb_exibir(TCB *tcb); //Exibir as informacoes da TCB
void tcb_apagar(TCB *tcb); //Liberar a TCB


#endif