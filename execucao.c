#include "execucao.h"
#include <stdbool.h>
#include "sysclock.h"

void executar_tarefas(TCB *tcb){
    char* tarefa_executando = NULL;
    bool tarefas_restantes = true;
    int contador_finalizadas = 0;

    while(tarefas_restantes){
        tarefa_executando = escalonador(tcb);
        int contador_tarefas = 0;
        for(TCB *aux = tcb;aux != NULL;aux = aux->proximo){
            contador_tarefas++;
            if(tarefa_executando == aux->tarefa.id){
                aux->tempo_restante -= tik;
                printf("Executando tarefa: %s\n", tarefa_executando);
                tik_tak();
                if(aux->tempo_restante == 0){
                    aux->status = FINALIZADA;
                    contador_finalizadas++;
                }
            }
        }
        if(contador_finalizadas == contador_tarefas){
            tarefas_restantes = false;
        }
    }
}