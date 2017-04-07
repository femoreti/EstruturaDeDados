#include <stdio.h>
#include <stdlib.h>

#define vertex int
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A estrutura digraph representa um digrafo. O campo adj é um ponteiro para o vetor de listas de adjacência, o campo V contém o número de vértices e o campo A contém o número de arcos do digrafo. */

typedef struct Node {
	vertex v;
	struct Node *proximo;
} Noh;

typedef struct Grafo {
	int Vertices;
	int Arestas;
	Noh *adj;
} Grafo;

/* A lista de adjacência de um vértice v é composta por nós do tipo node. Cada nó da lista corresponde a um arco e contém um vizinho w de v e o endereço do nó seguinte da lista. Um link é um ponteiro para um node. */


/* A função NEWnode() recebe um vértice w e o endereço next de um nó e devolve o endereço a de um novo nó tal que a->w == w e a->next == next. */

Noh *NEWnode(vertex w, Noh *proximo) {
	Noh *noh = (Noh*)malloc(sizeof(Noh));
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
	G->adj = (Noh*)malloc(V * sizeof(Noh));
	for (v = 0; v < V; v++)
	{
		G->adj[v].v = v;
		G->adj[v].proximo = NULL;
	}
	return G;
}
/* REPRESENTAÇÃO POR LISTAS DE ADJACÊNCIA: A função DIGRAPHinsertA() insere um arco v-w no digrafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o digrafo já tem um arco v-w, a função não faz nada. */

void insereGrafo(Grafo *G, vertex v, vertex w) {
	Noh *a;
	for (a = G->adj[v].proximo; a != NULL; a = a->proximo)
		if (a->v == w) return;
	G->adj[v].proximo = NEWnode(w, G->adj[v].proximo);
	G->Arestas++;
}

void printGrafoRecursivo(Noh *n)
{
	if (n != NULL)
	{
		printf("%d -> ", n->v);
		printGrafoRecursivo(n->proximo);
	}
}

void printGrafoList(Grafo *g)
{
	int i = 0;
	for (i = 0; i < g->Vertices; i++)
	{
		printf("%d -> ", g->adj[i].v);

		printGrafoRecursivo(g->adj[i].proximo);

		printf("\n");
	}

	printf("\n");
}

int verificaSeExisteVertice(Noh *n, int vertice)
{
	int valor = 0;
	if (n != NULL)
	{
		if (n->v != vertice)
			valor = verificaSeExisteVertice(n->proximo, vertice);
		else
			return 1;
	}

	return valor;
}

int calculaGrauLista(Grafo *g, int vertice)
{
	int grau = 0;

	int i = 0;
	for (i = 0; i < g->Vertices; i++)
	{
		grau += verificaSeExisteVertice(g->adj[i].proximo, vertice);
	}

	printf("vertice %d tem grau: %d", vertice, grau);
	return grau;
}

typedef struct obj {
	int v;
	struct obj *proximo;
}obj;

typedef struct Fila {
	int total;
	struct obj *ultimo, *primeiro;
} Fila;

void addFila(Fila *f, int v)
{
	obj *novo = (obj*)malloc(sizeof(obj));
	novo->proximo = NULL;
	novo->v = v;

	if (f->total == 0)
	{
		f->primeiro = novo;
		f->ultimo = novo;
	}
	else
	{
		f->ultimo->proximo = novo;
		f->ultimo = novo;
	}

	f->total++;
}

void removeFila(Fila *f)
{
	obj *temp = f->primeiro;
	f->primeiro = f->primeiro->proximo;

	free(temp);
	f->total--;
}

void BuscaLarguraLista(Grafo *g, vertex inicio)
{
	int u = 0;

	int *cor = (int*)malloc(g->Vertices * sizeof(int));
	int *pi = (int*)malloc(g->Vertices * sizeof(int));
	Fila *Q = (Fila*)malloc(g->Vertices * sizeof(Fila));
	Q->total = 0;
	Q->ultimo = NULL;
	Q->primeiro = NULL;

	int i;
	for (i = 0; i < g->Vertices; i++)
	{
		cor[i] = 0; // branco 0, cinza 1, preto 2
		pi[i] = NULL;
	}
	cor[inicio] = 1;
	addFila(Q, g->adj[inicio].v);
	printf("%2d", g->adj[inicio].v);

	while (Q->total != 0)
	{
		u = Q->primeiro->v;

		Noh *n;
		for(n = g->adj[u].proximo; n != NULL; n = n->proximo)
		{
			if (cor[n->v] == 0)
			{
				cor[n->v] = 1;
				pi[n->v] = u;
				addFila(Q, n->v);

				printf("%2d", n->v);
			}
		}
		removeFila(Q);
		cor[u] = 2;
	}

	printf("\n");
}

void DFSVisit(int u, int *cor, int *pi, Grafo *g)
{
	cor[u] = 1;

	Noh *n;
	for (n = g->adj[u].proximo; n != NULL; n = n->proximo)
	{
		if (cor[n->v] == 0)
		{
			pi[n->v] = u;
			DFSVisit(n->v, cor, pi, g);
		}
	}

	cor[u] = 2;

	printf("%2d", g->adj[u].v);
}

void BuscaProfundidadeLista(Grafo *g) 
{
	int u = 0;

	int *cor = (int*)malloc(g->Vertices * sizeof(int));
	int *pi = (int*)malloc(g->Vertices * sizeof(int));

	int i;
	for (i = 0; i < g->Vertices; i++)
	{
		cor[i] = 0; // branco 0, cinza 1, preto 2
		pi[i] = NULL;
	}

	for (u = 0; u < g->Vertices; u++)
	{
		if (cor[u] == 0)
		{
			DFSVisit(u, cor, pi, g);
		}
	}

	printf("\n");
}