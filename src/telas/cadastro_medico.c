#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CADASTRO_MEDICO_ARQUIVO "cadastro_medico.txt"


int cadastro_medico() {
	char nome_medico[100] = "";
	char especialidade[100] = "";
	char cep[100] = "";
	char endereco[100] = "";
	char email[100] = "";
	char rg[100] = "";
	char cpf[100] = "";
	char crm[100] = "";
	char nascimento[100] = "";
	char telefone[100] = "";

	puts("Cadastro de Médico");

	// Dados do(a) profissional
	leia_resposta("Nome", nome_medico);
	leia_resposta_formato("CPF", "xxx.xxx.xxx-xx", cpf);
	leia_resposta_formato("RG", "somente números", rg);
	leia_resposta_formato("CRM", "somente números", crm);
	leia_resposta_formato("Data de nascimento", "dd-mm-yyyy", nascimento);
	leia_resposta("Especialidade médica", especialidade);
	leia_resposta("Email", email);
	leia_resposta_formato("Telefone", "xx xxxxx-xxxx", telefone);
	leia_resposta_formato("CEP", "xxxxx-xxx", cep);
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
