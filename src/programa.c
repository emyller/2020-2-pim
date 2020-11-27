#include <stdbool.h>
#include <stdio.h>
#include "lib/cores.h"
#include "lib/entrada.h"
#include "lib/utils.h"

#include "./programa.h"
#include "telas/login.h"
#include "telas/elogios_reclamacoes.h"
#include "telas/agendamento_consulta.h"
#include "telas/cancelamento_consulta.h"
#include "telas/cadastro_medico.h"
#include "telas/cadastro_funcionario.h"
#include "telas/cadastro_paciente.h"
#include "telas/relatorios.h"


bool menu_principal() {
	int opcao;

	// Exibe menu
	exibe_titulo("Menu principal");
	puts("0. Sair");
	puts("1. Consultas");
	puts("2. Recursos Humanos");
	puts("3. Relatórios");

	// Ativa opção
	leia_digito("Opção", &opcao);
	switch (opcao) {
		case 0:
			// Desativa menu
			return false;
		case 1:
			menu_consultas();
			break;
		case 2:
			menu_recursos_humanos();
			break;
		case 3:
			menu_relatorios();
			break;
		default:
			puts("Opção inválida.");
	}

	// Mantém o menu ativo
	return true;
}


void menu_consultas() {
	int opcao;

	// Exibe menu
	exibe_titulo("Consultas");
	puts("0. Voltar");
	puts("1. Agendamento");
	puts("2. Cancelamento");
	puts("3. Cadastro de Paciente");

	// Ativa opção
	leia_digito("Opção", &opcao);
	switch (opcao) {
		case 0:
			return;
		case 1:
			agendamento_consulta();
			break;
		case 2:
			cancelamento_consulta();
			break;
		case 3:
			cadastro_paciente();
			break;
		default:
			puts("Opção inválida.");
	}
}


void menu_recursos_humanos() {
	int opcao;

	// Exibe menu
	exibe_titulo("Recursos Humanos");
	puts("0. Voltar");
	puts("1. Elogios e reclamações");
	puts("2. Cadastro de médicos");
	puts("3. Cadastro de funcionário");

	// Ativa opção
	leia_digito("Opção", &opcao);
	switch (opcao) {
		case 0:
			return;
		case 1:
			elogios_reclamacoes();
			break;
		case 2:
			cadastro_medico();
			break;
		case 3:
			cadastro_funcionario();
			break;
		default:
			puts("Opção inválida.");
	}
}


void menu_relatorios() {
	int opcao;

	// Exibe menu
	exibe_titulo("Relatórios");
	puts("0. Voltar");
	puts("1. Relatório: Agendamentos de Consulta");
	puts("2. Relatório: Pacientes Cadastrados");
	puts("3. Relatório: Elogios e Reclamações");
	puts("4. Relatório: Totais Diários");
	puts("5. Relatório: Cancelamento de Consultas");

	// Ativa opção
	leia_digito("Opção", &opcao);
	switch (opcao) {
		case 0:
			return;
		case 1:
			relatorio_agendamento_consulta();
			break;
		case 2:
			relatorio_pacientes_cadastrados();
			break;
		case 3:
			relatorio_elogios_reclamacoes();
			break;
		case 4:
			relatorio_totais_diarios();
			break;
		case 5:
			relatorio_cancelamento_consulta();
			break;
		default:
			puts("Opção inválida.");
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
	bool menu_ativo = true;
	while (menu_ativo) {
		menu_ativo = menu_principal();
	}
}
