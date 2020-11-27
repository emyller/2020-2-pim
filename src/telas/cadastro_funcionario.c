#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"

#define CADASTRO_FUNCIONARIO_ARQUIVO "cadastro_funcionario.txt"


int cadastro_funcionario ()  {
	char nome[100] = "";
	char cargo[100] = "";
	char genero[100] = "";
	char data_nascimento[100] = "";
	char estado_civil[100] = "";
	char cpf[100] = "";
	char rg[100] = "";
	char inss[100] = "";
	char telefone[100] = "";
	char email[100] = "";
	char endereco[100] = "";
	char complemento[100] = "";
	char cep[100] = "";

	exibe_titulo("Cadastro de Funcionário");

	// Dados pessoais
	leia_resposta("Nome", nome);
	leia_resposta("Cargo", cargo);
	leia_resposta_formato("Gênero", "m/f/x", genero);
	leia_resposta_formato("Data de nascimento", "dd-mm-yyyy", data_nascimento);
	leia_resposta_formato("Estado civil", "s/c/v/d", estado_civil);
	leia_resposta_formato("CPF", "xxx.xxx.xxx-xx", cpf);
	leia_resposta_formato("RG", "somente números", rg);
	leia_resposta_formato("INSS", "somente números", inss);
	leia_resposta_formato("Telefone", "xx xxxxx-xxxx", telefone);
	leia_resposta("Email", email);

	// Endereço
	leia_resposta_formato("CEP", "xxxxx-xxx", cep);
	leia_resposta("Endereço", endereco);
	leia_resposta("Complemento", complemento);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_FUNCIONARIO_ARQUIVO, 13,
		nome, genero, data_nascimento, estado_civil, cpf, rg, inss, telefone, email,
		cargo, endereco, complemento, cep
	);

	exibe_sucesso("Funcionário cadastrado.");
}
