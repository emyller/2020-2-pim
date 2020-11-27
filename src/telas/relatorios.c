#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/data_hora.h"
#include "../lib/entrada.h"
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
	int valor_total = 0;

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

		// Soma o valor no total
		valor_total += atoi(linha[5]);
	}

	// Exibe soma de valores
	exibe_separador();
	printf("Valor total: R$ %d\n", valor_total);

	exibe_sucesso("Relatório exibido.");
}


void relatorio_elogios_reclamacoes() {
	/*
	Exibe elogios e reclamações
	*/
	const size_t MAX_LINHAS = 100;

	exibe_titulo("Relatório: Elogios e Reclamações");

	// Lê arquivo de elogios e reclamações
	char linhas[MAX_LINHAS][500];
	int numero_linhas = leia_arquivo(ELOGIOS_RECLAMACOES_ARQUIVO, 500, linhas);

	// Exibe elogios e reclamações
	char linha[4][100];
	puts("Nome\tUnidade Agendamento\tNome médico\tElogios e Reclamações");
	for (int i = 0; i < numero_linhas; i++) {
		leia_linha_csv(linhas[i], 100, linha);
		printf(
			"%s\t%s\t%s\t%s\n",
			linha[0],
			linha[1],
			linha[2],
			linha[3]
		);
	}

	exibe_sucesso("Relatório exibido.");
}


void relatorio_totais_diarios() {
	const size_t MAX_LINHAS = 100;

	exibe_titulo("Relatório: Totais Diários");

	// Lê datas para filtrar o relatório
	char data_inicio_str[100];
	char data_fim_str[100];
	leia_resposta_formato("Data de início", "dd-mm-yyyy", data_inicio_str);
	leia_resposta_formato("Data de fim", "dd-mm-yyyy", data_fim_str);

	// Converte entrada em texto para datas
	Data data_inicio;
	Data data_fim;
	string_para_data(data_inicio_str, &data_inicio);
	string_para_data(data_fim_str, &data_fim);

	// Cabeçalho da tabela
	puts("Data\tConsultas\tTotal (R$)");

	// Faz um loop em todas as possíveis (e impossíveis) datas entre os anos
	int quantidade_periodo = 0, valor_periodo = 0;
	for (int ano = data_inicio.ano; ano <= data_fim.ano; ano++)
	for (int mes = 1; mes <= 12; mes++)
	for (int dia = 1; dia <= 31; dia++) {
		// Pula data se a iteração está antes ou depois do limite
		if (
			ano == data_inicio.ano && mes < data_inicio.mes ||
			ano == data_inicio.ano && mes == data_inicio.mes && dia < data_inicio.dia ||
			ano == data_fim.ano && mes > data_fim.mes ||
			ano == data_fim.ano && mes == data_fim.mes && dia > data_fim.dia
		) continue;

		// Lê arquivo de consultas
		char linhas[MAX_LINHAS][500];
		int numero_linhas = leia_arquivo(AGENDAMENTO_CONSULTA_ARQUIVO, 500, linhas);

		// Busca por todas as consultas na data atual
		int quantidade_dia = 0, valor_dia = 0;
		for (int i = 0; i < numero_linhas; i++) {
			char linha[6][100];
			Data data_linha;
			leia_linha_csv(linhas[i], 100, linha);
			string_para_data(linha[3], &data_linha);

			// Pula linha se as datas não batem
			if (!(
				ano == data_linha.ano &&
				mes == data_linha.mes &&
				dia == data_linha.dia
			)) continue;

			// Soma valores do dia
			quantidade_dia++;
			valor_dia += atoi(linha[5]);
		}

		// Exibe totais para a data
		printf(
			"%02d-%02d-%04d\t%d\t%d\n",
			dia, mes, ano, quantidade_dia, valor_dia
		);

		// Soma valores do período
		quantidade_periodo += quantidade_dia;
		valor_periodo += valor_dia;
	}

	// Exibe totais acumulados do período
	exibe_separador();
	printf("Total\t%d\t%d", quantidade_periodo, valor_periodo);

	exibe_sucesso("Relatório exibido.");
}


void relatorio_cancelamento_consulta() {
	/*
	Exibe cancelamento de consultas
	*/
	const size_t MAX_LINHAS = 100;

	exibe_titulo("Relatório: Cancelamento de Consultas");

	// Lê arquivo de cancelamento de consulta
	char linhas[MAX_LINHAS][500];
	int numero_linhas = leia_arquivo(CANCELAMENTO_CONSULTA_ARQUIVO, 500, linhas);

	// Exibe os cancelamento de consulta
	char linha[3][100];
	puts("Nome\tData\tHora");
	for (int i = 0; i < numero_linhas; i++) {
		leia_linha_csv(linhas[i], 100, linha);
		printf(
			"%s\t%s\t%s\n",
			linha[0],
			linha[1],
			linha[2]
		);
	}

	exibe_sucesso("Relatório exibido.");
}
