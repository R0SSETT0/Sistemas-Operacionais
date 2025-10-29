#ifndef ESCALONADOR_H
#define ESCALONADOR_H
#include "tcb.h"

char *algoritimo;
int quantum;

char* escalonador(TCB* tcb); //Inicia o escalonador com o algoritmo escolhido

#endif 