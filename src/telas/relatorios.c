#include <stdio.h>
#include "../lib/arquivos.h"
#include "../lib/data_hora.h"
#include "../lib/utils.h"


void relatorio_agendamento_consulta() {
	const size_t MAX_LINHAS = 100;

	exibe_titulo("Relatório: Agendamentos de Consulta");

	// Lê arquivo de consultas
	char linhas[MAX_LINHAS][500];
	leia_arquivo(AGENDAMENTO_CONSULTA_ARQUIVO, 500, linhas);

	// Exibe agendamentos
	char linha[5][100];
	puts("Nome\tEspecialidade\tMédico\tData\tHorário");
	for (int i = 0; i < 20; i++) {
		leia_linha_csv(linhas[i], 100, linha);
		printf("%s\t%s\t%s\t%s\t%s\n", linha[0], linha[1], linha[2], linha[3], linha[4]);
	}

	exibe_sucesso("Relatório exibido.");
}
