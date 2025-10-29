#include "parser.h"

void le_arquivo(TCB *tcb){
    FILE *ponteiro_arquivo;
    char linha[100];
    char nome_arquivo[] = "tarefas.txt";

    ponteiro_arquivo = fopen(nome_arquivo, "r");

    if (ponteiro_arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    const char *tok = ";";
    fgets(linha, sizeof(linha), ponteiro_arquivo);
    linha[strcspn(linha, "\n")] = 0;
    *algoritimo = strtok(linha, tok);
    quantum = atoi(strtok(NULL, tok));
    TCB *atual = tcb;
    
    while (fgets(linha, sizeof(linha), ponteiro_arquivo) != NULL){
        linha[strcspn(linha, "\n")] = 0;

        char *id = strtok(linha, tok);
        int chegada = atoi(strtok(NULL, tok));
        int duracao = atoi(strtok(NULL, tok));
        int prioridade = atoi(strtok(NULL, tok));

        if (id != NULL) {
            strcpy(atual->tarefa.id, id);
            atual->tarefa.chegada = chegada;
            atual->tarefa.duracao = duracao;
            atual->tempo_inicio = chegada;
            atual->tempo_restante = duracao;
            atual->tarefa.prioridade = prioridade;
            atual->proximo = tcb_criar();
            atual = atual->proximo;
        }
    }
    tcb_apagar(atual);

    fclose(ponteiro_arquivo);
}