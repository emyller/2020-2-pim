#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"
#include "./agendamento_consulta.h"

#define CANCELAMENTO_CONSULTA_ARQUIVO "cancelamento_consulta.txt"


int cancelamento_consulta() {
	char nome_paciente[100] = "";
	char data[100] = "";
	char hora[100] = "";
	int remarcar_consulta;

	exibe_titulo("Cancelamento de Consulta");

	leia_resposta("Nome do paciente", nome_paciente);
	leia_decisao("Remarcar consulta", &remarcar_consulta);

	// Caso o paciente queira remarcar, executa tela de cadastro do paciente
	if (remarcar_consulta) {
		agendamento_consulta();
	}

	// Caso o paciente não queira remarcar, sua consulta é apenas cancelada
	else {
		// Insere resultados no arquivo CSV
		escreve_linha_csv(
			CANCELAMENTO_CONSULTA_ARQUIVO, 3,
			nome_paciente, data, hora  // TODO: Usar data e hora da consulta cancelada
		);
		exibe_sucesso("Consulta cancelada.");
	}

	return 0;
}
