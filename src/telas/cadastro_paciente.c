#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CADASTRO_PACIENTE_ARQUIVO "cadastro_paciente.txt"


int cadastro_paciente()  {

	char nome[200] = ""; // Nome do cliente.
	char rg[10] = ""; // RG do cliente.
	char cpf[12] = ""; // CPF do cliente.
	char numero_contato[12] = ""; // Número de contato do cliente.
	char cep[11] = ""; // CEP do cliente.
	char endereco[200] = ""; // Endereço do cliente com numero da casa.
	char data_nascimento[20] = ""; // Data de Nascimento do cliente.
	char plano_saude[50] = ""; // Plano de saude do cliente.
	int resposta; // RESPOSTA para o comando "do while" em confirmações se os dados estão corretos ou não.
	int metodo_consulta;

	puts("--  Cadastro de pacientes. --");

	leia_string("Insira o nome do paciente: ", nome);

	do {
		leia_string("Digite o RG do paciente: ", rg);
		leia_digito("CPF digitado corretamente? 1.Sim - 2.Não ", &resposta);
	}
	while (resposta == 0);

	do {
		leia_string("Digite o CPF do paciente: ", cpf);
		leia_digito("RG digitado corretamente? 1.Sim - 2.Não ", &resposta);
	}
	while (resposta == 0);

	do {
		leia_string("Insira um número de contato: ", numero_contato);
		leia_string("Insira a data de nascimento: ", data_nascimento);
		leia_string("Insira o CEP: ", cep);
		leia_string("Insira o endereço: ", endereco);
		leia_digito("Cliente possui plano de saude? 1.Sim - 2.Não ", &metodo_consulta);

		if (metodo_consulta == 1) {
			leia_string("Digite o plano de saude do paciente", plano_saude);
		}
		else {
			puts("Cliente em consulta particular");
		}

		leia_digito("Todos os dados foram preenchidos corretamente: 1.Sim - 2.Não", &resposta);
	}
	while (resposta == 0);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_PACIENTE_ARQUIVO, 8,
		nome, rg, cpf, numero_contato, cep, endereco, data_nascimento, plano_saude
	);
}
