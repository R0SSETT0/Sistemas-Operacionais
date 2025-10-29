#include "sysclock.h"
#include "parser.h"
#include "grafico.h"
#include "execucao.h"

void main(){
    TCB* tcb = tcb_criar();
    le_arquivo(tcb);
    executar_tarefas(tcb);
    salvar_gantt_svg(tcb, global_clock/100, "gantt.svg");
}