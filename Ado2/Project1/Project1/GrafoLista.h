#include <stdio.h>
#include <stdlib.h>

#define vertex int

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura digraph representa um digrafo. O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém o número de vértices e o campo A contém o número de arcos do digrafo. */

typedef struct node {
	vertex v;
	node proximo;
} node;

typedef struct Grafo {
	int Vertices;
	int Arestas;
	node *adj;
} Grafo;

/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */


/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */

node *NEWnode(vertex w, node proximo) {
	node *noh = (node*)malloc(sizeof(struct node));
	noh->v = w;
	noh->proximo = proximo;
	return noh;
}

/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função DIGRAPHinit() constrói um digrafo com vértices 0 1 .. V-1 e nenhum arco. */

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
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função DIGRAPHinsertA() insere um arco v-w no digrafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o digrafo já tem um arco v-w, a função não faz nada. */

void insereGrafo(Grafo *G, vertex v, vertex w) {
	node *a;
	for (a = G->adj[v].v; a != NULL; a = a->proximo)
		if (a->v == w) return;
	G->adj[v].v = NEWnode(w, G->adj[v]);
	G->Arestas++;
}
