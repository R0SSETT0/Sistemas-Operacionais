#include "sysclock.h"
#include "parser.h"
#include "grafico.h"
#include "execucao.h"

void main(){
    int modo;
    char nome_arquivo[100];
    char nome_gantt[100];

    TCB* tcb = tcb_criar();
    printf("Digite o nome do arquivo de configuracao: \n");
    scanf("%100s", nome_arquivo);
    le_arquivo(tcb,nome_arquivo);

    printf("Escolha o modo de execucao:\n1 - Passo a passo\n2 - Execucao completa\n");
    scanf("%d", &modo);
    
    printf("Escolha o nome do arquivo Gantt: \n");
    scanf("%100s", nome_gantt);
    executar_tarefas(tcb,modo);
    salvar_gantt_svg(tcb, global_clock/100, nome_gantt);
}