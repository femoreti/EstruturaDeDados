#include <stdio.h>
#include <stdlib.h>

//#include "GrafosMatriz.h"
#include "ArvoreAVL.h"

int main(void)
{
	int *h = 0;
	Node *n = InsereAVL(NULL, 30, &h);
	n = InsereAVL(n, 15, &h);

	PreOrdem(n);

	n = InsereAVL(n, 18, &h);
	n = InsereAVL(n, 40, &h);
	n = InsereAVL(n, 48, &h);
	printf("\n");
	PreOrdem(n);

	Node *temp = BuscaArvoreRecursiva(n, 41);
	if (temp != NULL)
		printf("\nEncontrou valor %d", temp->dado);
	else
		printf("\nValor nao encontrado");

	printf("\nA arvore esta balanceada? %s", (VerificarSeAVL(n) == 1) ? "sim" : "nao");

	int q;
	scanf_s("%d", &q);

	return 0;
}