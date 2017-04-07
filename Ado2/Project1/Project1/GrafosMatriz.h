#include <stdio.h>
#include <stdlib.h>

#define vertex int

typedef struct digrafo {
	int Vertex;
	int Arestas;
	int **adj;
} *Grafo;

static int **initMatrizAdj(int linha, int coluna, int val) {
	vertex i, j;
	int **matriz = (int**)malloc(linha * sizeof(int *)); //define numero de linhas e aloca memoria
	for (i = 0; i < linha; i++) //linhas
		matriz[i] = (int*)malloc(coluna * sizeof(int)); //aloca memoria para colunas na linha
	for (i = 0; i < linha; i++)
	{//a cada linha
		for (j = 0; j < coluna; j++)
		{//colunas
			matriz[i][j] = val;
		}
	}
	return matriz;
}

Grafo initGrafoMatrizAdj(int V) {
	Grafo G = (Grafo)malloc(sizeof *G);
	G->Vertex = V;
	G->Arestas = 0;
	G->adj = initMatrizAdj(V, V, 0);
	
	return G;
}

void GrafoInsereAdj(Grafo G, vertex v, vertex w) {
	if (G->adj[v][w] == 0) {
		G->adj[v][w] = 1;
		G->Arestas++;
	}
}

void GrafoRemoveAdj(Grafo G, vertex v, vertex w) {
	if (G->adj[v][w] == 1) {
		G->adj[v][w] = 0;
		G->Arestas--;
	}
}

void printMatrizAdj(Grafo G) {
	vertex v, w;

	for (v = 0; v < G->Vertex; v++)
	{//a cada linha
		for (w = 0; w < G->Vertex; w++)
		{//colunas
			printf("%d ", G->adj[v][w]);
		}
		printf("\n");
	}
	printf("\n");
}

int calculaGrauMatriz(Grafo g, int vertice)
{
	int i, grau = 0;
	for (i = 0; i < g->Vertex; i++)
	{
		if (g->adj[i][vertice] == 1)
			grau++;
	}

	printf("vertice %d tem grau: %d", vertice, grau);

	return grau;
}
