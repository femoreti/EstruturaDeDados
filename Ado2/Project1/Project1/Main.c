#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinariaBusca.h"

void Debug()
{

}

int main(void) 
{
	// your code goes here
	Node *arvore;
	arvore = (Node*)malloc(sizeof(Node));
	arvore->valor = 10;

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		int n;
		scanf_s("%d", &n);

		InsereIterativo(arvore, n);
	}

	PreOrdem(arvore);

	int q;
	scanf_s("%d", &q);
	
	return 0;
}