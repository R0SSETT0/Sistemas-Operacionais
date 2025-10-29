<<<<<<< HEAD
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


=======
#ifndef TCB_H
#define TCB_H

#include <stdio.h>
#include <stdlib.h>
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


>>>>>>> 1260a52b8ee27f8ab54dceda4c586c1b179425a4
#endif