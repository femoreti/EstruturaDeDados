#include <stdio.h>
#include <stdlib.h>

#include "Grafos.h"

int main(void)
{
	// your code goes here
	Grafo g = initGrafoMatrizAdj(5);
	printMatrizAdj(g);

	GrafoInsereAdj(g, 3, 2);
	GrafoInsereAdj(g, 1, 4);
	GrafoInsereAdj(g, 1, 1);
	printf_s("\n");
	printMatrizAdj(g);

	int q;
	scanf_s("%d", &q);

	return 0;
}