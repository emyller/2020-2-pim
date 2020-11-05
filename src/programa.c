#include <stdio.h>
#include "lib/entrada.h"

#include "telas/login.h"


int menu() {
	/*
	Exibe menu de opções
	*/
	int opcao;

	puts("1. Login");
	leia_digito("Insira opção: ", &opcao);

	return opcao;
}


int main() {
	int opcao = menu();
	switch (opcao) {
		case 1:
			login();
			break;
		default:
			printf("Opção inválida. Tente novamente.");
	}
}
