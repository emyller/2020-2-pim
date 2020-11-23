#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CANCELAMENTO_CONSULTA_ARQUIVO "cancelamento_consulta.txt"


int cancelamento_consulta() {
	char nome_paciente[100] = "";
	char data[100] = "";
	char hora[100] = "";
	int remarcar_consulta;

	puts("Cancelamento de Consulta");

	leia_resposta("Nome do paciente", nome_paciente);
	leia_decisao("Remarcar consulta", &remarcar_consulta);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CANCELAMENTO_CONSULTA_ARQUIVO, 3,
		nome_paciente, data, hora  // TODO: Usar data e hora da consulta cancelada
	);

	// Caso o paciente queira remarcar, é feito um processo de reagendamento
	if (remarcar_consulta) {
		// TODO: Chama função de agendamento
		leia_resposta_formato("Data da consulta", "yyyy-mm-dd", data);
		leia_resposta_formato("Hora da consulta", "hh:mm", hora);
		puts("Consulta reagendada com sucesso!");
	}

	// Caso o paciente não queira remarcar, sua consulta é apenas cancelada
	else {
		puts("Consulta cancelada");
	}

	return 0;
}
