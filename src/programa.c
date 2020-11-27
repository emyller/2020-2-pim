#include <stdbool.h>
#include <stdio.h>
#include "lib/cores.h"
#include "lib/entrada.h"
#include "lib/utils.h"

#include "telas/login.h"
#include "telas/elogios_reclamacoes.h"
#include "telas/agendamento_consulta.h"
#include "telas/cancelamento_consulta.h"
#include "telas/cadastro_medico.h"
#include "telas/cadastro_funcionario.h"
#include "telas/cadastro_paciente.h"


int menu() {
	/*
	Exibe menu de opções
	*/
	int opcao;

	exibe_titulo("Menu principal");
	puts("2. Elogios e reclamações");
	puts("3. Agendamento de consulta");
	puts("4. Cancelamento de consulta");
	puts("5. Cadastro de médicos");
	puts("6. Cadastro de funcionário");
	puts("7. Cadastro de paciente");
	leia_digito("Insira opção: ", &opcao);

	return opcao;
}


int main() {
	puts(COR_VERDE "Bem vindo ao programa" COR_NORMAL);
	puts("Versão 0.0.1");

	// Obriga login antes de continuar
	bool logado = false;
	while (!logado) {
		logado = login();
	}

	// Menu do sistema
	int opcao = menu();
	switch (opcao) {
		case 2:
			elogios_reclamacoes();
			break;
		case 3:
			agendamento_consulta();
			break;
		case 4:
			cancelamento_consulta();
			break;
		case 5:
			cadastro_medico();
			break;
		case 6:
			cadastro_funcionario();
			break;
		case 7:
			cadastro_paciente();
			break;
		default:
			puts("Opção inválida. Tente novamente.");
	}
}
