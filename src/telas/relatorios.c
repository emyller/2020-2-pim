#include <stdio.h>
#include "../lib/arquivos.h"
#include "../lib/data_hora.h"
#include "../lib/utils.h"


void relatorio_pacientes_cadastrados() {
	/*
	Exibe lista de pacientes
	*/
	const size_t MAX_LINHAS = 100;

	exibe_titulo("Relatório: Pacientes Cadastrados");

	// Lê arquivo de pacientes
	char linhas[MAX_LINHAS][500];
	int numero_linhas = leia_arquivo(CADASTRO_PACIENTE_ARQUIVO, 500, linhas);

	// Exibe agendamentos
	char linha[8][100];
	puts("Nome\tCPF\tNascimento\tTelefone\tCEP\tEndereço\tPlano de Saúde");
	for (int i = 0; i < numero_linhas; i++) {
		leia_linha_csv(linhas[i], 100, linha);
		printf(
			"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
			linha[0],
			linha[2],
			linha[6],
			linha[3],
			linha[4],
			linha[5],
			linha[7]
		);
	}

	exibe_sucesso("Relatório exibido.");
}


void relatorio_agendamento_consulta() {
	const size_t MAX_LINHAS = 100;

	exibe_titulo("Relatório: Agendamentos de Consulta");

	// Lê arquivo de consultas
	char linhas[MAX_LINHAS][500];
	int numero_linhas = leia_arquivo(AGENDAMENTO_CONSULTA_ARQUIVO, 500, linhas);

	// Exibe agendamentos
	char linha[6][100];
	puts("Nome\tEspecialidade\tMédico\tData\tHorário\tValor (R$)");
	for (int i = 0; i < numero_linhas; i++) {
		leia_linha_csv(linhas[i], 100, linha);
		printf("%s\t%s\t%s\t%s\t%s\t%s\n", linha[0], linha[1], linha[2], linha[3], linha[4], linha[5]);
	}

	exibe_sucesso("Relatório exibido.");
}
