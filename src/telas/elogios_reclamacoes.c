#include <stdio.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"

#define ELOGIOS_RECLAMACOES_ARQUIVO "elogios_reclamacoes.txt"


int elogios_reclamacoes() {
	char nome[100] = "";
	char unidade_atendimento[100] = "";
	char nome_medico[100] = "";
	char elogio_reclamacao[400] = "";
	int ja_passou_consulta;

	exibe_titulo("Elogios e Reclamações");

	// Lê o nome da pessoa
	leia_resposta("Nome", nome);

	// Lê se já passou por consulta
	leia_decisao("Passou por consulta", &ja_passou_consulta);

	// Pede dados adicionais se já é paciente
	if (ja_passou_consulta) {
		// Lê unidade de atendimento
		leia_resposta("Unidade de atendimento", unidade_atendimento);

		// Lê nome do médico
		leia_resposta("Nome do(a) médico(a)", nome_medico);
	}

	// Lê elogio ou reclamação
	leia_resposta_formato("Elogio ou reclamação", "390 caracteres", elogio_reclamacao);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		ELOGIOS_RECLAMACOES_ARQUIVO, 4,
		nome, unidade_atendimento, nome_medico, elogio_reclamacao
	);

	exibe_sucesso("Comentário registrado.");

	return 0;
}
