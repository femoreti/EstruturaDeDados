enum Cor { preto = 0, vermelho };

typedef struct Tree {
	int dado	;
	struct Tree *esq, *dir, *pai;
	enum Cor cor;
} Node;

Node *NewNode(int v, enum Cor novaCor)
{
	Node *novo = (Node*)malloc(sizeof(Node));
	novo->dado = v;
	novo->dir = (v != -1) ? NewNode(-1, preto) : NULL;
	novo->esq = (v != -1) ? NewNode(-1, preto) : NULL;
	novo->pai = NULL;
	novo->cor = novaCor;

	return novo;
}

void RotacaoEsq(Node *noh, Node *raiz)
{
	Node *y = noh->dir;
	noh->dir = y->esq;
	if (y->esq != NULL)
		y->esq->pai = noh;
	y->pai = noh->pai;	if (noh->pai == NULL)
		raiz = y;
	else {
		if (noh == noh->pai->esq)
			noh->pai->esq = y;
		else
			noh->pai->dir = y;
	}
	y->esq = noh;
	noh->pai = y;
}

void RotacaoDir(Node *noh, Node *raiz)
{
	Node *y = noh->esq;
	noh->esq = y->dir;
	if (y->dir->dado != -1)
		y->dir->pai = noh;
	y->pai = noh->pai;	if (noh->pai == NULL)
	{
		raiz = y;
	}
	else 
	{
		if (noh == noh->pai->dir)
			noh->pai->dir = y;
		else
			noh->pai->esq = y;
	}
	y->dir = noh;
	noh->esq = y;
}

void InsRestaurarPropriedadesRN(Node *noh, Node *raiz)
{
	Node *y = NULL;
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
					RotacaoEsq(noh, raiz);
				}
				noh->pai->cor = preto; // caso 3
				noh->pai->pai->cor = vermelho;
				RotacaoDir(noh->pai->pai, raiz);
			}
		}
		else { // caso simetrico }
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
					RotacaoDir(noh, raiz);
				}
				noh->pai->cor = preto; // caso 3
				noh->pai->pai->cor = vermelho;
				RotacaoEsq(noh->pai->pai, raiz);
			}
		}
		raiz->cor = preto;
	} // fim
}

void insereRN(int v, Node *raiz) {
	Node *ant, *p, *novo;
	ant = NULL;
	p = raiz;
	
	while (p != NULL) {
		ant = p;
		if (v < p->dado)
		{
			if (p->esq->dado != -1)
				p = p->esq;
			else
				p = NULL;
		}
		else
		{
			if (p->dir->dado != -1)
				p = p->dir;
			else
				p = NULL;
		}
	}

	novo = NewNode(v, vermelho);
	novo->pai = ant;
	
	if (ant == NULL)
		raiz = novo;
	else {
		if (v < ant->dado)
			ant->esq = novo;
		else ant->dir = novo;
	}
	InsRestaurarPropriedadesRN(novo, raiz);
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