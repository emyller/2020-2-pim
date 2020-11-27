#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"
#include "./cadastro_paciente.h"

#define AGENDAMENTO_CONSULTA_ARQUIVO "agendamento_consulta.txt"


int agendamento_consulta() {
	char nome_paciente[100] = "";
	char especialidade_medica[100] = "";
	char nome_medico[100] = "";
	char data[100] = "";
	char hora[100] = "";
	int ja_possui_cadastro;
	int valor_consulta;

	exibe_titulo("Agendamento de Consulta");

	// Executa tela de cadastro do paciente, se necessário
	leia_decisao("Possui cadastro", &ja_possui_cadastro);
	if (!ja_possui_cadastro) {
		cadastro_paciente();
	}

	leia_resposta("Nome do paciente", nome_paciente);

	// TODO: Exibir disponibilidade de médicos e horários
	leia_resposta("Especialidade médica", especialidade_medica);
	leia_digito("Valor da consulta:", &valor_consulta);
	leia_resposta("Nome do(a) médico(a)", nome_medico);
	leia_resposta_formato("Data da consulta", "dd-mm-yyyy", data);
	leia_resposta_formato("Hora da consulta", "hh:mm", hora);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		AGENDAMENTO_CONSULTA_ARQUIVO, 5,
		nome_paciente, especialidade_medica, nome_medico, data, hora
	);

	exibe_sucesso("Consulta agendada.");
}
