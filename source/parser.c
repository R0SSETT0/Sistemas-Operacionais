#include "parser.h"

void le_arquivo(TCB *tcb, char* nome_arquivo){
    FILE *ponteiro_arquivo;
    char linha[100];

    ponteiro_arquivo = fopen(nome_arquivo, "r");

    if (ponteiro_arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }
    
    const char *tok = ";";
    fgets(linha, sizeof(linha), ponteiro_arquivo);
    linha[strcspn(linha, "\n")] = 0;
    *algoritimo = *strtok(linha, tok);
    quantum = atoi(strtok(NULL, tok));
    TCB *atual = tcb;
    
    while (fgets(linha, sizeof(linha), ponteiro_arquivo) != NULL){
        linha[strcspn(linha, "\n")] = 0;

        char *id = strtok(linha, tok);
        char *cor = strtok(NULL, tok);
        int chegada = atoi(strtok(NULL, tok));
        int duracao = atoi(strtok(NULL, tok));
        int prioridade = atoi(strtok(NULL, tok));

        if (id != NULL) {
            strcpy(atual->tarefa.id, id);
            strcpy(atual->tarefa.cor, cor);
            atual->tarefa.tempo_inicio = chegada;
            atual->tarefa.duracao = duracao;
            atual->tempo_restante = atual->tarefa.duracao;
            atual->tarefa.prioridade = prioridade;
            atual->proximo = tcb_criar();
            atual = atual->proximo;
        }
    }
    tcb_apagar(atual);

    fclose(ponteiro_arquivo);
}