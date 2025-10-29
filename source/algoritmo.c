#include "algoritmo.h"

char* fifo(TCB* tcb){
    char *aux;
    int inicio = -1;
    TCB* atual = tcb;
    while(atual != NULL){
        if((inicio == -1 || atual->tarefa.tempo_inicio < inicio) && atual->status == PRONTA){
            inicio = atual->tarefa.tempo_inicio;
            strcpy(aux, atual->tarefa.id);
        }
        atual = atual->proximo;
    }
    return aux;
}

char* srtf(TCB* tcb){
    char *aux;
    int menor_duracao = -1;
    TCB* atual = tcb;
    while(atual != NULL){
        if((menor_duracao == -1 || atual->tempo_restante < menor_duracao) && atual->status == PRONTA){
            menor_duracao = atual->tempo_restante;
            strcpy(aux, atual->tarefa.id);
        }
        atual = atual->proximo;
    }
    return aux;
}

char* prioridade(TCB* tcb){
    char *aux;
    int maior_prioridade = -1;
    TCB* atual = tcb;
    while(atual != NULL){
        if((atual->tarefa.prioridade > maior_prioridade) && atual->status == PRONTA){
            maior_prioridade = atual->tarefa.prioridade;
            strcpy(aux, atual->tarefa.id);
        }
        atual = atual->proximo;
    }
    return aux;
}