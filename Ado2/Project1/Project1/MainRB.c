#include <stdio.h>
#include <stdlib.h>

#include "ArvoreRubroNegra.h"

Node *raiz, *nulo;
int main(void)
{
	
	nulo = NewNode(-1, preto, NULL);
	raiz = nulo;
	raiz = insereRN(10, raiz, nulo);

	raiz = insereRN(5, raiz, nulo);
	raiz = insereRN(3, raiz, nulo);
	raiz = insereRN(7, raiz, nulo);
	raiz = insereRN(9, raiz, nulo);
	raiz = insereRN(11, raiz, nulo);
	raiz = insereRN(12, raiz, nulo);
	raiz = insereRN(4, raiz, nulo);
	raiz = insereRN(1, raiz, nulo);
	//insereRN(3, raiz, nulo);

	PreOrdem(raiz);

	int q;
	scanf_s("%d", &q);

	return 0;
}