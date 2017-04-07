#include <stdio.h>
#include <stdlib.h>

#include "GrafosMatriz.h"
//#include "GrafoLista.h"

int main(void)
{
	// your code goes here
	Grafo g = initGrafoMatrizAdj(5);
	printMatrizAdj(g);

	GrafoInsereAdj(g, 3, 0);
	GrafoInsereAdj(g, 3, 2);
	GrafoInsereAdj(g, 1, 4);
	GrafoInsereAdj(g, 1, 1);
	GrafoInsereAdj(g, 2, 1);
	GrafoInsereAdj(g, 2, 4);
	GrafoInsereAdj(g, 0, 4);
	printf_s("\n");
	printMatrizAdj(g);

	calculaGrauMatriz(g, 3);

	/*Grafo *g = initGrafo(5);

	printGrafoList(g);

	insereGrafo(g, 0, 2);
	insereGrafo(g, 0, 4);
	insereGrafo(g, 1, 0);
	insereGrafo(g, 1, 3);
	insereGrafo(g, 1, 4);
	insereGrafo(g, 2, 0);
	insereGrafo(g, 2, 1);
	insereGrafo(g, 2, 3);
	insereGrafo(g, 3, 4);
	insereGrafo(g, 4, 0);

	printGrafoList(g);*/

	int q;
	scanf_s("%d", &q);

	return 0;
}