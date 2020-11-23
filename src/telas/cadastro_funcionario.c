#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CADASTRO_FUNCIONARIO_ARQUIVO "cadastro_funcionario.txt"


int cadastro_funcionario ()  {
	char nome[100] = "";
	char genero[20] = "";
	char data_nascimento[15] = "";
	char estado_civil[15] = "";
	char cpf[15] = "";
	char rg[15] = "";
	char inss[15] = "";
	char telefone_celular[15] = "";
	char telefone_residencial[15] = "";
	char email[100] = "";
	char nome_cracha[20] = "";
	char cargo[50] = "";
	char endereco[300] = "";
	char complemento[50] = "";
	char cep[20] = "";
	int dados_corretos;

	puts("Cadastro de Funcionários");

	// Dados pessoais
	leia_resposta("Nome", nome);
	leia_resposta("Cargo", cargo);
	leia_resposta("Gênero", genero);
	leia_resposta_formato("Data de nascimento", "YYYY-MM-DD", data_nascimento);
	leia_resposta_formato("Estado civil", "S/C/V/D", estado_civil);
	leia_resposta_formato("CPF", "XXX.XXX.XXX-XX", cpf);
	leia_resposta_formato("RG", "somente números", rg);
	leia_resposta_formato("INSS", "somente números", inss);
	leia_resposta_formato("Celular", "XX XXXXX-XXXX", telefone_celular);
	leia_resposta("Email", email);
	leia_resposta("Nome no crachá", nome_cracha);

	// Endereço
	do {
		leia_resposta_formato("CEP", "XXXXX-XXX", cep);
		leia_resposta("Endereço", endereco);
		leia_resposta("Complemento", complemento);
		leia_resposta_formato("Telefone", "XX XXXX-XXXX", telefone_residencial);
		leia_decisao("Dados corretos", &dados_corretos);
	}
	while (!dados_corretos);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_FUNCIONARIO_ARQUIVO, 19,
		nome, genero, data_nascimento, estado_civil, cpf, rg, inss, telefone_celular,
		telefone_residencial, email, nome_cracha, cargo, endereco, complemento, cep
	);
}
