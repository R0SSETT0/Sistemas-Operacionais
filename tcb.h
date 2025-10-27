#ifndef TCB_H
#define TCB_H

#include "tarefa.h"

typedef enum{
    NOVA,
    PRONTA,
    EXECUTANDO,
    BLOQUEADA,
    FINALIZADA
}Status;

typedef struct tcb{
    Tarefa tarefa;
    Status status;
    int tempo_executado;
    int tempo_restante;
    int tempo_inicio;
    int tempo_fim;
    struct tcb* prox;

}TCB;

TCB* tcb_criar(Tarefa tarefa);
void tcb_mudar_status(TCB *tcb, Status status); //Mudar o status da TCB 
void tcb_exibir(TCB *tcb); //Exibir as informacoes da TCB
void tcb_apagar(TCB *tcb); //Liberar a TCB


#endif