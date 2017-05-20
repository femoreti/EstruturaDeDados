#include <stdio.h>
#include <stdlib.h>

enum Cor { preto = 0, vermelho };

typedef struct Tree {
	int dado	;
	struct Tree *esq, *dir, *pai;
	enum Cor cor;
} Node;

Node *NewNode(int v, enum Cor novaCor, Node *nulo)
{
	Node *novo = (Node*)malloc(sizeof(Node));
	novo->dado = v;
	novo->dir = nulo;
	novo->esq = nulo;
	novo->pai = NULL;
	novo->cor = novaCor;

	return novo;
}

Node *RotacaoEsq(Node *noh, Node *raiz, Node *nulo)
{
	Node *y = noh->dir;
	noh->dir = y->esq;
	if (y->esq != nulo)
		y->esq->pai = noh;
	y->pai = noh->pai;	if (noh->pai == nulo)
		raiz = y;
	else {
		if (noh == noh->pai->esq)
			noh->pai->esq = y;
		else
			noh->pai->dir = y;
	}
	y->esq = noh;
	noh->pai = y;

	return raiz;
}

Node *RotacaoDir(Node *noh, Node *raiz, Node *nulo)
{
	Node *y = noh->esq;
	noh->esq = y->dir;
	if (y->dir != nulo)
		y->dir->pai = noh;
	y->pai = noh->pai;	if (noh->pai == nulo)
	{
		raiz = y;
	}
	else {
		if (noh == noh->pai->dir)
			noh->pai->dir = y;
		else
			noh->pai->esq = y;
	}
	y->dir = noh;
	noh->pai = y;
	
	return raiz;
}

Node *InsRestaurarPropriedadesRN(Node *noh, Node *raiz, Node *nulo)
{
	Node *y;
	while (noh->pai->cor == vermelho) 
	{
		if (noh->pai == noh->pai->pai->esq) {
			y = noh->pai->pai->dir; // tio
			if (y->cor == vermelho) {
				noh->pai->cor = preto; // caso 1
				y->cor = preto;
				noh->pai->pai->cor = vermelho;
				noh = noh->pai->pai;
			}
			else {
				if (noh == noh->pai->dir) {
					noh = noh->pai; // caso 2
					raiz = RotacaoEsq(noh, raiz, nulo);
				}
				noh->pai->cor = preto; // caso 3
				noh->pai->pai->cor = vermelho;
				raiz = RotacaoDir(noh->pai->pai, raiz, nulo);
			}
		}
		else 
		{ // caso simetrico 
			y = noh->pai->pai->esq; // tio
			if (y->cor == vermelho) {
				noh->pai->cor = preto; // caso 1
				y->cor = preto;
				noh->pai->pai->cor = vermelho;
				noh = noh->pai->pai;
			}
			else {
				if (noh == noh->pai->esq) {
					noh = noh->pai; // caso 2
					raiz = RotacaoDir(noh, raiz, nulo);
				}
				noh->pai->cor = preto; // caso 3
				noh->pai->pai->cor = vermelho;
				raiz = RotacaoEsq(noh->pai->pai, raiz, nulo);
			}
		}
	}
	raiz->cor = preto;
	return raiz;
}

Node *insereRN(int v, Node *raiz, Node *nulo) {
	Node *ant, *p, *novo;
	ant = nulo;
	p = raiz;
	
	while (p != nulo) {
		ant = p;
		if (v < p->dado)
			p = p->esq;
		else
			p = p->dir;
	}

	novo = NewNode(v, vermelho, nulo);
	novo->pai = ant;
	
	if (ant == nulo)
	{
		raiz = novo;
	}
	else {
		if (v < ant->dado)
			ant->esq = novo;
		else ant->dir = novo;
	}
	raiz = InsRestaurarPropriedadesRN(novo, raiz, nulo);

	return raiz;
}

void InOrdem(Node *n)
{
	if (n != NULL && n->dado != -1)
	{
		InOrdem(n->esq);
		printf("%d ", n->dado);
		InOrdem(n->dir);
	}
}

void PreOrdem(Node *n)
{
	if (n != NULL && n->dado != -1)
	{
		printf("%d ", n->dado);
		PreOrdem(n->esq);
		PreOrdem(n->dir);
	}
}

void PosOrdem(Node *n)
{
	if (n != NULL && n->dado != -1)
	{
		PosOrdem(n->esq);
		PosOrdem(n->dir);
		printf("%d ", n->dado);
	}
}