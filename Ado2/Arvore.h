#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore {
	struct Node *raiz;
	int qtdNode;
} Arvore;

typedef struct Node {
	int dado;
	int quantidade;
	struct Node *esquerda;
	struct Node *direita;
} Node;

void InitArvore(Arvore *arvore) {
	arvore->qtdNode = 0;
	arvore->raiz = NULL;
}

void InitNode(Node *node, int dado) {
	node->dado = dado;
	node->quantidade = 1;
	node->esquerda = NULL;
	node->direita = NULL;
}

void InsereDadoRecursivo(Node *raiz, Node *newNode, int dado) {
	if (raiz->dado > dado) {
		if (raiz->esquerda != NULL) {
			InsereDadoRecursivo(raiz->esquerda, newNode, dado);
		}
		else {
			raiz->esquerda = newNode;
		}
	}
	else if (raiz->dado < dado) {
		if (raiz->direita != NULL) {
			InsereDadoRecursivo(raiz->direita, newNode, dado);
		}
		else {
			raiz->direita = newNode;
		}
	}
	else {
		raiz->quantidade++;
	}
}

void InsereArvoreRecursivo(Arvore *arvore, int dado) {
	Node *newNode = malloc(sizeof(Node));
	InitNode(newNode, dado);

	if (arvore->raiz == NULL) {
		arvore->raiz = newNode;
	}
	else {
		Node *raiz = arvore->raiz;
		InsereDadoRecursivo(arvore->raiz, newNode, dado);
	}

	arvore->qtdNode++;
}

void InsereArvoreIterativo(Arvore *arvore, int dado) {
	Node *temp = arvore->raiz;
	Node *prev = NULL;
	Node *newNode = malloc(sizeof(Node));
	InitNode(newNode, dado);

	if (arvore->raiz == NULL)
	{
		arvore->raiz = newNode;
	}

	while (temp != NULL) {
		prev = temp;
		if (temp->dado < dado)
		{
			temp = temp->direita;
		}
		else if (temp->dado > dado) {
			temp = temp->esquerda;
		}
		else {
			temp->quantidade++;
			return;
		}
	}

	if (prev->dado < dado)
	{
		prev->direita = newNode;
	}
	else {
		prev->esquerda = newNode;
	}
}

Node * nodeMenorValor(Node *raiz) {
	Node *temp = raiz;

	while (temp->esquerda != NULL)
	{
		temp = temp->esquerda;
	}

	return temp;
}

Node * RemoveArvore(Node *raiz, int dado) {
	if (raiz == NULL)
	{
		return raiz;
	}

	if (dado < raiz->dado)
	{
		raiz->esquerda = RemoveArvore(raiz->esquerda, dado);
	}
	else if (dado > raiz->dado) {
		raiz->direita = RemoveArvore(raiz->direita, dado);
	}
	else {
		if (raiz->esquerda == NULL)
		{
			Node *temp = raiz->direita;
			free(raiz);
			return temp;
		}
		else if (raiz->direita == NULL) {
			Node *temp = raiz->esquerda;
			free(raiz);
			return temp;
		}
		else {
			Node *temp = nodeMenorValor(raiz->direita);
			raiz->dado = temp->dado;
			raiz->direita = RemoveArvore(raiz->direita, temp->dado);
		}
	}

	return raiz;
}

Node * BuscaArvoreRecursivo(Node *raiz, int dado) {
	Node *temp = raiz;

	if (raiz == NULL || raiz->dado == dado)
	{
		return raiz;
	}

	if (temp->dado > dado) {
		return BuscaArvoreRecursivo(temp->esquerda, dado);
	}
	else {
		return BuscaArvoreRecursivo(temp->direita, dado);
	}
}

Node * BuscaArvoreIterativo(Arvore *arvore, int dado) {
	Node *temp = arvore->raiz;
	while (temp != NULL && temp->dado != dado)
	{
		if (temp->dado > dado)
		{
			temp = temp->esquerda;
		}
		else {
			temp = temp->direita;
		}
	}

	return temp;
}

void PercursoPreOrdem(Node *raiz) {
	Node *temp = raiz;
	if (temp != NULL)
	{
		printf("%d\n", temp->dado);
		PercursoPreOrdem(temp->esquerda);
		PercursoPreOrdem(temp->direita);
	}
}

void PercursoInOrdem(Node * raiz) {
	Node *temp = raiz;
	if (temp != NULL) {
		PercursoInOrdem(temp->esquerda);
		printf("%d\n", temp->dado);
		PercursoInOrdem(temp->direita);
	}
}

void PercursoPosOrdem(Node * raiz) {
	Node *temp = raiz;
	if (temp != NULL) {
		PercursoInOrdem(temp->esquerda);
		PercursoInOrdem(temp->direita);
		printf("%d\n", temp->dado);
	}
}