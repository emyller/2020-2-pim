#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define AGENDAMENTO_CONSULTA_ARQUIVO "agendamento_consulta.txt"


int agendamento_consulta() {
	char nome_paciente[100] = "";
	char especialidade_medica[100] = "";
	char nome_medico[100] = "";
	char data[100] = "";
	char hora[100] = "";
	int ja_possui_cadastro;

	puts("Agendamento de Consulta");

	leia_decisao("Possui cadastro", &ja_possui_cadastro);

	// Caso o paciente já tenha cadastro
	if (ja_possui_cadastro) {
		leia_resposta("Nome do paciente", nome_paciente);

		// TODO: Exibir disponibilidade de médicos e horários
		leia_resposta("Especialidade médica", especialidade_medica);
		leia_resposta("Nome do(a) médico(a)", nome_medico);
		leia_resposta_formato("Data da consulta", "YYYY-MM-DD", data);
		leia_resposta_formato("Hora da consulta", "HH:MM", hora);

		// Insere resultados no arquivo CSV
		escreve_linha_csv(
			AGENDAMENTO_CONSULTA_ARQUIVO, 5,
			nome_paciente, especialidade_medica, nome_medico, data, hora
		);

		puts("Consulta agendada com sucesso!");
	}

	// Caso ainda não tenha cadastro
	else {
		// TODO: Executa função de cadastro e volta
		puts("Faça o cadastro do paciente.");
	}
}
