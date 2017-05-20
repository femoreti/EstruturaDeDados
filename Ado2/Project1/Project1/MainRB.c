#include <stdio.h>
#include <stdlib.h>

#include "ArvoreRubroNegra.h"

int main(void)
{
	Node *raiz;
	raiz = NewNode(10, preto);

	insereRN(5, raiz);
	insereRN(3, raiz);

	PreOrdem(raiz);

	int q;
	scanf_s("%d", &q);

	return 0;
}