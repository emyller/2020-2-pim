#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"

#define CADASTRO_PACIENTE_ARQUIVO "cadastro_paciente.txt"


int cadastro_paciente()  {
	char nome[100] = "";
	char rg[100] = "";
	char cpf[100] = "";
	char numero_contato[100] = "";
	char cep[100] = "";
	char endereco[100] = "";
	char data_nascimento[100] = "";
	char plano_saude[100] = "";

	exibe_titulo("Cadastro de Pacientes");

	// Dados pessoais
	leia_resposta("Nome", nome);
	leia_resposta_formato("CPF", "xxx.xxx.xxx-xx", cpf);
	leia_resposta_formato("RG", "somente números", rg);
	leia_resposta_formato("Data de nascimento", "dd-mm-yyyy", data_nascimento);

	// Endereço e contato
	leia_resposta_formato("Telefone", "xx xxxxx-xxxx", numero_contato);
	leia_resposta_formato("CEP", "xxxxx-xxx", cep);
	leia_resposta("Endereço", endereco);
	leia_resposta_formato("Plano de saúde", "ou \"particular\"", plano_saude);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_PACIENTE_ARQUIVO, 8,
		nome, rg, cpf, numero_contato, cep, endereco, data_nascimento, plano_saude
	);
}
