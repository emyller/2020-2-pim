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
#include "telas/relatorios.h"


void menu() {
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
	puts("8. Relatório: Agendamentos de Consulta");
	puts("9. Relatório: Pacientes Cadastrados");
	puts("10. Relatório: Elogios e Reclamações");
	puts("11. Relatório: Totais Diários");
	leia_digito("Insira opção: ", &opcao);

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
		case 8:
			relatorio_agendamento_consulta();
			break;
		case 9:
			relatorio_pacientes_cadastrados();
			break;
		case 10:
			relatorio_elogios_reclamacoes();
			break;
		case 11:
			relatorio_totais_diarios();
			break;
		default:
			puts("Opção inválida. Tente novamente.");
	}
}


int main() {
	puts(COR_VERDE "Bem vindo ao programa" COR_NORMAL);
	puts("Versão 0.0.1");

	// Obriga login antes de continuar
	bool logado = false;
	while (!logado) {
		logado = login();
	}

	// Executa o menu continuamente
	// Ao sair de uma tela, retorna ao menu principal
	while (true) {
		menu();
	}
}
