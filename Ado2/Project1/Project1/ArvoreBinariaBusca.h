#include <stdio.h>

typedef struct Tree {
	int valor;
	struct Tree *esq, *dir;
} Node;

Node *BuscaArvoreRecursiva(Node *raiz, int n) 
{
	if (raiz == NULL || raiz->valor == n)
		return raiz;

	if (raiz->valor > n)
		return BuscaArvoreRecursiva(raiz->esq, n);
	else
		return BuscaArvoreRecursiva(raiz->dir, n);
}

Node *BuscaArvoreIterativa(Node *raiz, int n)
{
	while (raiz != NULL && raiz->valor != n) {
		if (raiz->valor > n)
			raiz = raiz->esq;
		else
			raiz = raiz->dir;
	}
	return raiz;
}

struct Tree *InsereRecursivo(struct Tree *raiz, Node *novo) {
	if (raiz == NULL) 
		return novo;
	if (raiz->valor > novo->valor)
		raiz->esq = InsereRecursivo(raiz->esq, novo);
	else
		raiz->dir = InsereRecursivo(raiz->dir, novo);
	return raiz;
}

void InsereIterativo(Node *p, int v)
{
	Node *q, *novo;
	q = NULL;
	while (p != NULL) {
		q = p;
		if (v == p->valor) {
			printf("Elemento ja existe!");
			return;
		}
		if (v < p->valor) p = p->esq;
		else p = p->dir;
	} // while
	novo = (Node*)malloc(sizeof(Node));
	novo->valor = v;
	if (p == NULL)
		p = novo;
	else {
		if (v < q->valor)
			q->esq = novo;
		else q->dir = novo;
	}
}

void InOrdem(Node *n)
{
	if (n != NULL)
	{
		InOrdem(n->esq);
		printf("%d\n", n->valor);
		InOrdem(n->dir);
	}
}

void PreOrdem(Node *n)
{
	printf("%d\n", n->valor);
	PreOrdem(n->esq);
	PreOrdem(n->dir);
}

void PosOrdem(Node *n)
{
	PosOrdem(n->esq);
	PosOrdem(n->dir);
	printf("%d\n", n->valor);
}