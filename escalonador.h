#ifndef ESCALONADOR_H
#define ESCALONADOR_H

#include "tcb.h"

void inicia_escalonador(char *algoritmo, int quantum); //Inicia o escalonador com o algoritmo escolhido
void adiciona_escalonador(TCB *tcb); //Adiciona uma TCB na fila
void remove_escalanonador(TCB *tcb); //Remove a TCB da fila
TCB* proxima_escalonador(); //escolhe a proxima TCB para executar
TCB* get_atual_escalonador(); //Pega a TCB execudando atualmente
void finaliza_escalonador(TCB *tcb); //Finaliza o escalonador e ajustar estado

#endif 