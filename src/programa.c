#include <stdio.h>
#include "lib/entrada.h"


int main() {
	int opcao;

	leia_digito("Insira opção: ", &opcao);

	switch (opcao) {
		case 1:
			printf("Yay");
			break;
		default:
			printf("Opção inválida. Tente novamente.");
	}
}
