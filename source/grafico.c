#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafico.h"

#define CEDULA_L 20
#define CEDULA_A 30
#define MARGEM 20

/* Cabeçalho básico do SVG com largura/altura e viewBox */
static void svg_header(FILE *f, int largura, int altura) {
    fprintf(f, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    fprintf(f, "<svg xmlns=\"http://www.w3.org/2000/svg\" ");
    fprintf(f, "width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n", largura, altura, largura, altura);
}

static void svg_footer(FILE *f) {
    fprintf(f, "</svg>\n");
}

/* Desenha texto simples */
static void svg_text(FILE *f, int x, int y, const char *texto) {
    fprintf(f, "<text x=\"%d\" y=\"%d\" font-family=\"Arial\" font-size=\"12\">%s</text>\n", x, y, texto);
}

/* Função pública: gera e salva SVG com o Gantt */
int salvar_gantt_svg(TCB *tcb, int total_ticks, char *nome_gantt) {
    if (!nome_gantt) return -1;

    /* Conta quantas tarefas (linhas) serão desenhadas */
    int n = 0;
    for (TCB *p = tcb; p != NULL; p = p->proximo) n++;
    if (n == 0) {
        fprintf(stderr, "[UI] sem tarefas para desenhar.\n");
        return -1;
    }

    int largura = MARGEM*2 + total_ticks * CEDULA_L;
    int altura = MARGEM*2 + n * CEDULA_A + 50;
    FILE *f = fopen(nome_gantt, "w");
    if (!f) { perror("fopen svg"); return -1; }

    svg_header(f, largura, altura);

    /* Marcações de tempo (linhas verticais e labels a cada 5 ticks) */
    for (int t = 0; t <= total_ticks; ++t) {
        int x = MARGEM + t * CEDULA_L;
        /* Marca em cada tick (1 em 1) */
        fprintf(f, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"#ddd\" stroke-width=\"1\" />\n",
                x, MARGEM, x, MARGEM + n*CEDULA_A);
        char num[16]; snprintf(num, sizeof(num), "%d", t);
        svg_text(f, x+2, MARGEM-5, num);
    }

    /* Desenha cada linha de tarefa e seus segmentos */
    int idx = 0;
    for (TCB *aux = tcb; aux != NULL; aux = aux->proximo) {
        int y = MARGEM + idx*CEDULA_A;
    char label[64];
    /* id já inclui prefixo (ex: t01) */
    snprintf(label, sizeof(label), "%s", aux->tarefa.id);
        svg_text(f, 2, y + CEDULA_A/2 + 5, label);

        /* Fundo da linha (grade) */
        fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"#f8f8f8\" stroke=\"#eee\" />\n",
                MARGEM, y, total_ticks*CEDULA_L, CEDULA_A-6);

    /* Desenha retângulo branco representando tempo de espera (ingresso -> tempo_inicio)
       se houver espera antes da primeira execução. */
    int wait_start = aux->tarefa.tempo_inicio;
    int wait_end = (aux->tarefa.tempo_inicio >= 0) ? aux->tarefa.tempo_inicio : total_ticks;
    int wait_len = wait_end - wait_start;
    if (wait_len > 0) {
        int wx = MARGEM + wait_start * CEDULA_L;
        int ww = wait_len * CEDULA_L;
        /* branco com borda leve para indicar espera */
        fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"#ffffff\" stroke=\"#bbb\" stroke-width=\"1\" />\n",
            wx, y, ww, CEDULA_A-10);
    }

        /* Desenha segmentos de execução */
        for (int s = 0; s < aux->tempo_fim; ++s) {
            int sx = MARGEM + aux->tarefa.tempo_inicio * CEDULA_L;
            int sw = aux->tempo_fim * CEDULA_L;
            const char *col = aux->tarefa.cor;
            if (!col || strlen(col) == 0) col = "#88c";
            fprintf(f, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" stroke=\"#333\" stroke-width=\"1\" />\n",
                    sx, y, sw, CEDULA_A-10, col);
        }
        idx++;
    }

    svg_text(f, MARGEM, MARGEM + n*CEDULA_A + 20, "Legenda: retângulos coloridos = execução da tarefa");
    svg_footer(f);
    fclose(f);
    printf("[UI] Gantt salvo em: %s\n", nome_gantt);
    return 0;
}