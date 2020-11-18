#include <stdio.h>
#include "lib/cores.h"
#include "lib/entrada.h"

#include "telas/login.h"
#include "telas/elogios_reclamacoes.h"
#include "telas/agendamento_consulta.h"


int menu() {
	/*
	Exibe menu de opções
	*/
	int opcao;

	puts("1. Login");
	puts("2. Elogios e reclamações");
	puts("3. Agendamento de Consulta");
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
		case 2:
			elogios_reclamacoes();
			break;
		case 3:
			agendamento_consulta();
			break;
		default:
			puts("Opção inválida. Tente novamente.");
	}
}
