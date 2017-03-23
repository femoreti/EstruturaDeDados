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

Node *NewNode(int v)
{
	Node *novo = (Node*)malloc(sizeof(Node));
	novo->valor = v;
	novo->dir = NULL;
	novo->esq = NULL;

	return novo;
}

struct Tree *InsereRecursivo(struct Tree *raiz, int v) {
	if (raiz == NULL)
	{
		return NewNode(v);
	}
	if (raiz->valor > v)
		raiz->esq = InsereRecursivo(raiz->esq, v);
	else
		raiz->dir = InsereRecursivo(raiz->dir, v);
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
		if (v < p->valor) 
			p = p->esq;
		else 
			p = p->dir;
	} // while
	novo = NewNode(v);

	if (v < q->valor)
		q->esq = novo;
	else 
		q->dir = novo;
}

Node * NodeMinValue(Node *raiz) {
	Node *temp = raiz;

	while (temp->esq != NULL)
	{
		temp = temp->esq;
	}

	return temp;
}

Node * RemoveArvore(Node *r, int v) {
	if (r == NULL)
	{
		return r;
	}

	if (v < r->valor)
	{
		r->esq = RemoveArvore(r->esq, v);
	}
	else if (v > r->valor) {
		r->dir = RemoveArvore(r->dir, v);
	}
	else 
	{
		if (r->esq == NULL)
		{
			Node *temp = r->dir;
			free(r);
			return temp;
		}
		else if (r->dir == NULL) {
			Node *temp = r->esq;
			free(r);
			return temp;
		}
		else {
			Node *temp = NodeMinValue(r->dir);
			r->valor = temp->valor;
			r->dir = RemoveArvore(r->dir, temp->valor);
		}
	}

	return r;
}

void InOrdem(Node *n)
{
	if (n != NULL)
	{
		InOrdem(n->esq);
		printf("%d ", n->valor);
		InOrdem(n->dir);
	}
}

void PreOrdem(Node *n)
{
	if (n != NULL)
	{
		printf("%d ", n->valor);
		PreOrdem(n->esq);
		PreOrdem(n->dir);
	}
}

void PosOrdem(Node *n)
{
	if (n != NULL)
	{
		PosOrdem(n->esq);
		PosOrdem(n->dir);
		printf("%d ", n->valor);
	}
}