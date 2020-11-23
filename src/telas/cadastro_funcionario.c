#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CADASTRO_FUNCIONARIO_ARQUIVO "cadastro_funcionario.txt"


int cadastro_funcionario ()  {
	char nome[100] = "";
	char cargo[50] = "";
	char genero[20] = "";
	char data_nascimento[15] = "";
	char estado_civil[15] = "";
	char cpf[15] = "";
	char rg[15] = "";
	char inss[15] = "";
	char telefone[15] = "";
	char email[100] = "";
	char endereco[300] = "";
	char complemento[50] = "";
	char cep[20] = "";
	int dados_corretos;

	puts("Cadastro de Funcionário");

	// Dados pessoais
	leia_resposta("Nome", nome);
	leia_resposta("Cargo", cargo);
	leia_resposta_formato("Gênero", "m/f/x", genero);
	leia_resposta_formato("Data de nascimento", "yyyy-mm-dd", data_nascimento);
	leia_resposta_formato("Estado civil", "s/c/v/d", estado_civil);
	leia_resposta_formato("CPF", "xxx.xxx.xxx-xx", cpf);
	leia_resposta_formato("RG", "somente números", rg);
	leia_resposta_formato("INSS", "somente números", inss);
	leia_resposta_formato("Telefone", "xx xxxxx-xxxx", telefone);
	leia_resposta("Email", email);

	// Endereço
	do {
		leia_resposta_formato("CEP", "xxxxx-xxx", cep);
		leia_resposta("Endereço", endereco);
		leia_resposta("Complemento", complemento);
		leia_decisao("Dados corretos", &dados_corretos);
	}
	while (!dados_corretos);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_FUNCIONARIO_ARQUIVO, 19,
		nome, genero, data_nascimento, estado_civil, cpf, rg, inss, telefone, email,
		cargo, endereco, complemento, cep
	);
}
