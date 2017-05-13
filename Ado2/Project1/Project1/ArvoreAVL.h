#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int dado;
	int bal;

	struct Tree *esq, *dir;
} Node;

Node *NewNode(int v)
{
	Node *novo = (Node*)malloc(sizeof(Node));
	novo->dado = v;
	novo->bal = 0;
	novo->dir = NULL;
	novo->esq = NULL;

	return novo;
}

Node *caso1(Node *p) {
	Node *u, *v;
	u = p->esq;
	
	if (u->bal == -1) { // caso 1.1: rotacao direita
		p->esq = u->dir;
		u->dir = p;
		p->bal = 0; // ajustar o balanco de p
		p = u;
	}
	else { // caso 1.2 : rotacao dupla direita JOELHO
		v = u->dir;
		u->dir = v->esq;
		p->esq = v->dir;
		v->esq = u; v->dir = p;
		if (v->bal == -1) p->bal = 1;
		else p->bal = 0;
		if (v->bal == 1) u->bal = -1;
		else u->bal = 0;
		p = v;
	}

	p->bal = 0;
	return p;
}

Node *caso2(Node *p)
{
	Node *z, *y;
	z = p->dir;

	// caso 2.1: rotacao esquerda
	if (z->bal == 1)
	{
		p->dir = z->esq;
		z->esq = p;
		p->bal = 0;
		p = z;
	}	else { // Caso 2.2: rotacao dupla esquerda JOELHO
		y = z->esq;
		z->esq = y->dir;
		p->dir = y->esq;
		y->esq = p; 
		y->dir = z;
		
		if (y->bal == 1) 
			p->bal = -1;
		else 
			p->bal = 0;

		if (y->bal == -1) 
			z->bal = 1;
		else 
			z->bal = 0;
		
		p = y;
	}
	p->bal = 0;
	return p;
}

Node *InsereAVL(Node *n, int valor, int *verificaAltura)
{
	if (n == NULL)
	{
		n = NewNode(valor);
		*verificaAltura = 1;
	}
	else if (valor < n->dado) //Esquerda
	{
		n->esq = InsereAVL(n->esq, valor, verificaAltura);
		if (*verificaAltura == 1)//verifica o balanceamento
		{
			switch (n->bal)
			{
			case 1:
				n->bal = 0;
				*verificaAltura = 0;
				break;
			case 0:
				n->bal = -1;
				break;
			case -1:
				n = caso1(n);
				*verificaAltura = 0;	
				break;
			}
		}
	}
	else if (valor > n->dado) { // direita
		n->dir = InsereAVL(n->dir, valor, verificaAltura);
		if (*verificaAltura == 1) { // verificar o balanceamento
			switch (n->bal) 
			{
			case -1: 
				n->bal = 0; 
				*verificaAltura = 0; 
				break;
			case 0: 
				n->bal = 1; 
				break;
			case 1: 
				n = caso2(n); 
				*verificaAltura = 0; 
				break;
			}
		}
	}

	return n;
}

/*
Node * RemoveArvore(Node *r, int v) {
	if (r == NULL)
	{
		return r;
	}

	if (v < r->dado)
	{
		r->esq = RemoveArvore(r->esq, v);
	}
	else if (v > r->dado) {
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
			r->dado = temp->dado;
			r->dir = RemoveArvore(r->dir, temp->dado);
		}
	}

	return r;
}*/

Node *BuscaArvoreRecursiva(Node *raiz, int n)
{
	if (raiz == NULL || raiz->dado == n)
		return raiz;

	if (raiz->dado > n)
		return BuscaArvoreRecursiva(raiz->esq, n);
	else
		return BuscaArvoreRecursiva(raiz->dir, n);
}

void InOrdem(Node *n)
{
	if (n != NULL)
	{
		InOrdem(n->esq);
		printf("%d ", n->dado);
		InOrdem(n->dir);
	}
}

void PreOrdem(Node *n)
{
	if (n != NULL)
	{
		printf("%d ", n->dado);
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
		printf("%d ", n->dado);
	}
}

int VerificarSeAVL(Node *n)
{
	if (n != NULL)
	{
		if (n->bal < -1 || n->bal > 1)
			return 0;

		PosOrdem(n->esq);
		PosOrdem(n->dir);
		printf("%d ", n->dado);
	}

	return 1;
}