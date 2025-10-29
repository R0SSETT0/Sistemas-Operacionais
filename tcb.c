#include "tcb.h"

TCB* tcb_criar(){
    TCB* novo_tcb = (TCB*)malloc(sizeof(TCB));
    if (novo_tcb == NULL){
        printf("Erro na criação do TCB\n");
        return NULL;
    }
    Tarefa tarefa;
    novo_tcb->tarefa = tarefa;
    novo_tcb->status = PRONTA;
    novo_tcb->tempo_executado = 0;
    novo_tcb->tempo_restante = 0;
    novo_tcb->tempo_fim = NULL;
    novo_tcb->proximo = NULL;
    return novo_tcb;
}
void tcb_mudar_status(TCB *tcb,Status status){
    if (tcb != NULL){
        tcb->status = status;
    }
}
void tcb_exibir(TCB *tcb){
    if (tcb != NULL){
        printf("TCB ID: %s\n",tcb->tarefa.id);
        printf("Chegada: %d\n",tcb->tarefa.tempo_inicio);
        printf("Duracao: %d\n",tcb->tarefa.duracao);
        printf("Prioridade: %d\n",tcb->tarefa.prioridade);
        printf("Cor: %s\n",tcb->tarefa.cor);
        printf("Status: %d\n",tcb->status);
        printf("Tempo Executado: %d\n",tcb->tempo_executado);
        printf("Tempo Restante: %d\n",tcb->tempo_restante);
        printf("Tempo Inicio: %d\n",tcb->tarefa.tempo_inicio);
        printf("Tempo Fim: %d\n",tcb->tempo_fim);
    }
}
void tcb_apagar(TCB *tcb){
    if (tcb != NULL){
        free(tcb);
    }
}