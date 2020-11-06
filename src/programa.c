#include <stdio.h>
#include "lib/cores.h"
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
	puts(COR_VERDE "\nBem vindo ao programa" COR_NORMAL);
	puts("Versão 0.0.1\n\n");

	int opcao = menu();
	switch (opcao) {
		case 1:
			login();
			break;
		default:
			puts("Opção inválida. Tente novamente.");
	}
}
