#include <stdio.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define ELOGIOS_RECLAMACOES_ARQUIVO "elogios_reclamacoes.txt"


int elogios_reclamacoes() {
	char nome[100] = "";
	char unidade_atendimento[100] = "";
	char nome_medico[100] = "";
	char elogio_reclamacao[400] = "";
	int ja_passou_consulta;

	// Lê o nome da pessoa
	leia_string("Insira seu nome: ", nome);

	// Lê se já passou por consulta
	leia_digito("Já passou por consulta? [0/1] ", &ja_passou_consulta);

	// Pede dados adicionais se já é paciente
	if (ja_passou_consulta == 1) {
		// Lê unidade de atendimento
		leia_string("Unidade de atendimento: ", unidade_atendimento);

		// Lê nome do médico
		leia_string("Nome do(a) médico(a): ", nome_medico);
	}

	// Lê elogio ou reclamação
	leia_string("Elogio ou reclamação: ", elogio_reclamacao);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		ELOGIOS_RECLAMACOES_ARQUIVO, 4,
		nome, unidade_atendimento, nome_medico, elogio_reclamacao
	);

	return 0;
}
