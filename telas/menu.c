#include<stdio.h>
#include<stdlib.h>


int main() {
	int opcao;

	// Exibe o menu inicial
	printf("Digite uma das opções:\n");
	printf("1. Login\n");
	printf("2. Cadastro de cliente\n");
	scanf("%1d", &opcao);

	// Executa programa correspondente
	switch (opcao) {
		case 1:
			printf("Executando login...");
			system("./login");
			break;

		case 2:
			printf("Executando cadastro de cliente...");
			break;

		default:
			printf("Opção inválida.\n");
	}
}