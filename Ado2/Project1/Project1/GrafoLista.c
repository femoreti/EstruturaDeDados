#include <stdio.h>
#include <stdlib.h>

#define vertex int

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A estrutura digraph representa um digrafo. O campo adj � um ponteiro para o vetor de listas de adjac�ncia, o campo V cont�m o n�mero de v�rtices e o campo A cont�m o n�mero de arcos do digrafo. */

typedef struct node {
	vertex v;
	node proximo;
} node;

typedef struct Grafo {
	int Vertices;
	int Arestas;
	node *adj;
} Grafo;

/* A lista de adjac�ncia de um v�rtice v � composta por n�s do tipo node. Cada n� da lista corresponde a um arco e cont�m um vizinho w de v e o endere�o do n� seguinte da lista. Um link � um ponteiro para um node. */


/* A fun��o NEWnode() recebe um v�rtice w e o endere�o next de um n� e devolve o endere�o a de um novo n� tal que a->w == w e a->next == next. */

node *NEWnode(vertex w, node proximo) {
	node *noh = (node*)malloc(sizeof(struct node));
	noh->v = w;
	noh->proximo = proximo;
	return noh;
}

/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o DIGRAPHinit() constr�i um digrafo com v�rtices 0 1 .. V-1 e nenhum arco. */

Grafo *initGrafo(int V) {
	vertex v;
	Grafo *G = (Grafo*)malloc(sizeof(Grafo));
	G->Vertices = V;
	G->Arestas = 0;
	G->adj = malloc(V * sizeof(node));
	for (v = 0; v < V; v++)
		G->adj[v].v = NULL;
	return G;
}
/* REPRESENTA��O POR LISTAS DE ADJAC�NCIA: A fun��o DIGRAPHinsertA() insere um arco v-w no digrafo G. A fun��o sup�e que v e w s�o distintos, positivos e menores que G->V. Se o digrafo j� tem um arco v-w, a fun��o n�o faz nada. */

void insereGrafo(Grafo *G, vertex v, vertex w) {
	node *a;
	for (a = G->adj[v].v; a != NULL; a = a->proximo)
		if (a->v == w) return;
	G->adj[v].v = NEWnode(w, G->adj[v]);
	G->Arestas++;
}