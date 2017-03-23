// O arquivo Arvore.h implementa a funcionalidade de uma Arvore Bin�ria de Busca.
// Para inserir na arvore utilize: InsereArvoreRecursivo ou InsereArvoreIterativo.
// Para remover da arvore utilize: RemoveArvore.
// Para buscar na arvore utilize: BuscaArvoreRecursivo ou BuscaArvoreIterativo.
// Para imprimir a arvore utilize: PercursoPreOrdem, PercursoInOrdem ou PercursoPosOrdem.

#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

int main() {
	int wait = 0;

	Arvore *arvore = malloc(sizeof(Arvore));
	InitArvore(arvore);

	while (1) {
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Escolha uma opcao abaixo:\n");
		printf("1 - Insere Recursivamente na arvore\n");
		printf("2 - Insere Iterativamente na arvore\n");
		printf("3 - Remove dado da arvore\n");
		printf("4 - Busca Recursivamente na arvore\n");
		printf("5 - Busca Iterativamente na arvore\n");
		printf("6 - Imprime arvore em pre-ordem\n");
		printf("7 - Imprime arvore em in-ordem\n");
		printf("8 - Imprime arvore em pos-ordem\n");
		printf("9 - Limpa a tela\n");
		printf("0 - Encerra o programa\n");
		printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

		int escolha;
		scanf("%d", &escolha);

		switch (escolha)
		{
			int dado;
			case 1:
				printf("Digite um numero real para inserir na arvore:");
				scanf("%d", &dado);

				InsereArvoreRecursivo(arvore, dado);
				break;
			case 2:
				printf("Digite um numero real para inserir na arvore:");
				scanf("%d", &dado);

				InsereArvoreIterativo(arvore, dado);
				break;
			case 3:
				printf("Digite um valor da arvore para remover:");
				scanf("%d", &dado);
				arvore->raiz = RemoveArvore(arvore->raiz, dado);
				break;
			case 4:
				printf("Digite um valor para buscar na arvore:");
				scanf("%d", &dado);

				Node *resultadoRecursivo = BuscaArvoreRecursivo(arvore->raiz, dado);
				if (resultadoRecursivo == NULL)
				{
					printf("Nao foi possivel encontrar o dado");
				}
				else {
					printf("\nEncontramos o dado: %d que foi inserido %d vez(es)\n", resultadoRecursivo->dado, resultadoRecursivo->quantidade);
				}
				break;
			case 5:
				printf("Digite um valor para buscar na arvore:");
				scanf("%d", &dado);

				Node *resultadoIterativo = BuscaArvoreIterativo(arvore, dado);
				if (resultadoIterativo == NULL)
				{
					printf("Nao foi possivel encontrar o dado.");
				}
				else {
					printf("\nEncontramos o dado: %d que foi inserido %d vez(es)\n", resultadoIterativo->dado, resultadoIterativo->quantidade);
				}
				break;
			case 6:
				printf("\nImprimindo em pre-ordem\n");
				PercursoPreOrdem(arvore->raiz);
				printf("\n");
				break;
			case 7:
				printf("\nImprimindo em in-ordem\n");
				PercursoInOrdem(arvore->raiz);
				printf("\n");
				break;
			case 8:
				printf("\nImprimindo em pos-ordem\n");
				PercursoPosOrdem(arvore->raiz);
				printf("\n");
				break;
			case 9:
				system("@cls||clear");
				break;
			case 0:
				return 0;
			default:
				printf("Digite um op��o valida.\n");
				break;
		}
	}

	return 0;
}