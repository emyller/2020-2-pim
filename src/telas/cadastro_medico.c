#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CADASTRO_MEDICO_ARQUIVO "cadastro_medico.txt"


int cadastro_medico() {
	char nome_medico[100] = "";
	char especialidade[100] = "";
	char cep[8] = "";
	char endereco[200] = "";
	char email[100] = "";
	char rg[9] = "";
	char cpf[11] = "";
	char crm[6] = "";
	char nascimento[8] = "";
	char telefone[16] = "";

	puts("Cadastro de Médico");

	// Dados do(a) profissional
	leia_resposta("Nome", nome_medico);
	leia_resposta_formato("CPF", "XXX.XXX.XXX-XX", cpf);
	leia_resposta_formato("RG", "somente números", rg);
	leia_resposta_formato("CRM", "somente números", crm);
	leia_resposta_formato("Data de nascimento", "YYYY-MM-DD", nascimento);
	leia_resposta("Especialidade médica", especialidade);
	leia_resposta("Email", email);
	leia_resposta_formato("Telefone", "XX XXXXX-XXXX", telefone);
	leia_resposta_formato("CEP", "XXXXX-XXX", cep);
	leia_resposta("Endereço", endereco);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_MEDICO_ARQUIVO, 10,
		nome_medico, especialidade, cep, endereco, email, rg, cpf, crm,
		nascimento, telefone
	);

	puts("Cadastro efetuado com sucesso!");

	return 0;
}
