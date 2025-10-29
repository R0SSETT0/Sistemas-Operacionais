#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"
#include "algoritmo.h"

char* escalonador(TCB* tcb){
    if (algoritimo == "FIFO") {
        return fifo(tcb);
    } else if (algoritimo == "SRTF") {
        return srtf(tcb);
    } else if (algoritimo == "PRIORIDADE") {
        return prioridade(tcb);
    }
}
 