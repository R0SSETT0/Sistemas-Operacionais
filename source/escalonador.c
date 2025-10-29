#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"
#include "algoritmo.h"

char* escalonador(TCB* tcb){
    if (!strcmp(algoritimo, "FIFO")) {
        return fifo(tcb);
    } else if (!strcmp(algoritimo, "SRTF")) {
        return srtf(tcb);
    } else if (!strcmp(algoritimo, "PRIORIDADE")) {
        return prioridade(tcb);
    } else {
        return NULL;
    }
}
 