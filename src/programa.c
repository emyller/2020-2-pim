#include <stdio.h>
#include "lib/entrada.h"

#include "telas/login.h"


int main() {
	int opcao;

	// Exibe menu de opções
	puts("1. Login");
	leia_digito("Insira opção: ", &opcao);

	switch (opcao) {
		case 1:
			login();
			break;
		default:
			printf("Opção inválida. Tente novamente.");
	}
}
