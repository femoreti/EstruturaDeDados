#include <stdio.h>
#include <stdlib.h>
/*
#include "ArvoreBinariaBusca.h"

void Escolha(Node *r)
{
	printf("\n####---MENU---###\n");
	printf("Escolha o que deseja fazer:\n");
	printf("1 - Inserir elemento\n");
	printf("2 - Remover elemento\n");
	printf("3 - buscar elemento\n");
	printf("4 - imprimir arvore\n");
	printf("0 - Sair\n");
	printf("###############\n");

	int temp,n;
	scanf_s("%d", &temp);
	switch (temp)
	{
	case 1:
		printf("####---Inserir Elemento---###\n");
		printf("Escolha uma opcao abaixo:\n");
		printf("1 - Inserir Iterativo\n");
		printf("2 - Inserir Recursivo\n");

		scanf_s("%d", &n);
		
		switch (n)
		{
			int q;
		case 1:
			printf("Digite o valor a ser inserido iterativamente: ");
			scanf_s("%d", &q);

			if (r == NULL)
				r = NewNode(q);
			else
				InsereIterativo(r, q);
			break;
		case 2:
			printf("Digite o valor a ser inserido recursivamente: ");
			scanf_s("%d", &q);
			r = InsereRecursivo(r, q);
			break;
		default:
			printf("invalido!\n");
			break;
		}
		break;
	case 2:
		printf("Digite o valor a ser removido : ");
		scanf_s("%d", &n);
		RemoveArvore(r, n);
		break;
	case 3:
		printf("####---Buscar Elemento---###\n");
		printf("Escolha uma opcao abaixo:\n");
		printf("1 - Busca Iterativa\n");
		printf("2 - Busca Recursiva\n");
		scanf_s("%d", &n);

		switch (n)
		{
			int q;
		case 1:
			printf("Digite o valor para busca iterativa: ");
			scanf_s("%d", &q);
			Node *nIt = BuscaArvoreIterativa(r, q);
			if(nIt == NULL)
				printf("Valor nao encontrado.");
			else
				printf("valor %d encontrado.", nIt->valor);
			break;
		case 2:
			printf("Digite o valor para busca recursiva: ");
			scanf_s("%d", &q);
			Node *nRec = BuscaArvoreRecursiva(r, q);
			if (nRec == NULL)
				printf("Valor nao encontrado.");
			else
				printf("valor %d encontrado.", nRec->valor);
			break;
		default:
			printf("invalido!\n");
			break;
		}
		break;
	case 4:
		printf("####---Imprimir---###\n");
		printf("Escolha uma opcao abaixo:\n");
		printf("1 - Imprimir In-Ordem\n");
		printf("2 - Imprimir Pre-Ordem\n");
		printf("3 - Imprimir Pos-Ordem\n");

		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			InOrdem(r);
			break;
		case 2:
			PreOrdem(r);
			break;
		case 3:
			PosOrdem(r);
			break;
		default:
			printf("invalido!\n");
			break;
		}
		break;
	case 0:

		return;
	default:
		printf("invalido, tente novamente.\n");
		break;
	}

	Escolha(r);
}

int main(void) 
{
	// your code goes here
	Node *arvore = NULL;

	Escolha(arvore);

	//int q;
	//scanf_s("%d", &q);
	
	return 0;
}
*/