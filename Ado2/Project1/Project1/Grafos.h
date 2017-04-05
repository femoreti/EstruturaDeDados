#include <stdio.h>

#define vertex int

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A estrutura digraph representa um digrafo. O campo adj � um ponteiro para a matriz de adjac�ncias do digrafo. O campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de arcos do digrafo. */

struct digraph {
	int V;
	int A;
	int **adj;
};
/* Um Digraph � um ponteiro para um digraph, ou seja, um Digraph cont�m o endere�o de um digraph. */

typedef struct digraph *Digraph;

/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o DIGRAPHinit() constr�i um digrafo com v�rtices 0 1 .. V-1 e nenhum arco. */

Digraph DIGRAPHinit(int V) {
	Digraph G = malloc(sizeof *G);
	G->V = V;
	G->A = 0;
	G->adj = MATRIXint(V, V, 0);
	return G;
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o MATRIXint() aloca uma matriz com linhas 0..r-1 e colunas 0..c-1. Cada elemento da matriz recebe valor val. */

static int **MATRIXint(int r, int c, int val) {
	vertex i, j;
	int **m = malloc(r * sizeof(int *));
	for (i = 0; i < r; i++)
		m[i] = malloc(c * sizeof(int));
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			m[i][j] = val;
	return m;
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o DIGRAPHinsertA() insere um arco v-w no digrafo G. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o digrafo j� tem um arco v-w, a fun��o n�o faz nada. */

void DIGRAPHinsertA(Digraph G, vertex v, vertex w) {
	if (G->adj[v][w] == 0) {
		G->adj[v][w] = 1;
		G->A++;
	}
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o DIGRAPHremoveA() remove do digrafo G o arco v-w. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se n�o existe arco v-w, a fun��o n�o faz nada. */

void DIGRAPHremoveA(Digraph G, vertex v, vertex w) {
	if (G->adj[v][w] == 1) {
		G->adj[v][w] = 0;
		G->A--;
	}
}
/* REPRESENTA��O POR MATRIZ DE ADJAC�NCIAS: A fun��o DIGRAPHshow() imprime, para cada v�rtice v do digrafo G, em uma linha, todos os v�rtices adjacentes a v. */

void DIGRAPHshow(Digraph G) {
	vertex v, w;
	for (v = 0; v < G->V; v++) {
		printf("%2d:", v);
		for (w = 0; w < G->V; w++)
			if (G->adj[v][w] == 1)
				printf(" %2d", w);
		printf("\n");
	}
}