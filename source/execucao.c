#include "execucao.h"
#include <stdbool.h>
#include "sysclock.h"
#include "escalonador.h"

void executar_tarefas(TCB *tcb, int modo){
    char* tarefa_executando = NULL;
    bool tarefas_restantes = true;
    int contador_finalizadas = 0;
    if(modo != 1 && modo != 2){
        printf("Modo invalido! Executando em modo completo.\n");
    }
    if(modo == 1){
        while(tarefas_restantes){
            if((global_clock/100) % quantum == 0){
                tarefa_executando = escalonador(tcb);
            }
            int contador_tarefas = 0;
            for(TCB *aux = tcb;aux != NULL;aux = aux->proximo){
                if((global_clock/100) == aux->tarefa.tempo_inicio){
                    aux->status = PRONTA;
                }
                contador_tarefas++;
                if(tarefa_executando == aux->tarefa.id){
                    aux->tempo_restante -= tik;
                    aux->tempo_executado += tik;
                    printf("Executando tarefa: %s\n", tarefa_executando);
                    tik_tak();
                    if(aux->tempo_restante == 0){
                        aux->status = FINALIZADA;
                        aux->tempo_fim = global_clock/100;
                        contador_finalizadas++;
                    }
                } 
                else{
                    
                }
            }
            if(contador_finalizadas == contador_tarefas){
                tarefas_restantes = false;
            }
            printf("Pressione Enter para o próximo tick...\n");
            getchar();
        }
    }
    else {
        while(tarefas_restantes){
            if((global_clock/100) % quantum == 0){
                tarefa_executando = escalonador(tcb);
            }
            int contador_tarefas = 0;
            for(TCB *aux = tcb;aux != NULL;aux = aux->proximo){
                if((global_clock/100) == aux->tarefa.tempo_inicio){
                    aux->status = PRONTA;
                }
                contador_tarefas++;
                if(tarefa_executando == aux->tarefa.id){
                    aux->tempo_restante -= tik;
                    aux->tempo_executado += tik;
                    printf("Executando tarefa: %s\n", tarefa_executando);
                    tik_tak();
                    if(aux->tempo_restante == 0){
                        aux->status = FINALIZADA;
                        aux->tempo_fim = global_clock/100;
                        contador_finalizadas++;
                    }
                }
            }
            if(contador_finalizadas == contador_tarefas){
                tarefas_restantes = false;
            }
        }
    }    
}