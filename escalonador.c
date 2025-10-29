#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "escalonador.h"

int quantum_geral = 0;
char algoritmo[20] = "";

void escalonador_inciar(char *alg, int quantum){
    strncpy(algoritmo,alg,sizeof(algoritmo)-1);
    algoritmo[sizeof(algoritmo)-1] = '\0';
    quantum_geral = quantum;
    

}