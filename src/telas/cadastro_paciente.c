#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

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
	int dados_corretos;
	int metodo_consulta;

	puts("Cadastro de Pacientes");

	leia_resposta("Nome", nome);
	leia_resposta_formato("CPF", "xxx.xxx.xxx-xx", cpf);
	leia_resposta_formato("RG", "somente números", rg);

	do {
		leia_resposta_formato("Telefone", "xx xxxxx-xxxx", numero_contato);
		leia_resposta_formato("Data de nascimento", "yyyy-mm-dd", data_nascimento);
		leia_resposta_formato("CEP", "xxxxx-xxx", cep);
		leia_resposta("Endereço", endereco);
		leia_decisao("Plano de saúde", &metodo_consulta);

		if (metodo_consulta) {
			leia_resposta("Plano de saúde", plano_saude);
		}
		else {
			puts("Cliente em consulta particular");
		}

		leia_decisao("Dados corretos", &dados_corretos);
	}
	while (!dados_corretos);

	// Insere resultados no arquivo CSV
	escreve_linha_csv(
		CADASTRO_PACIENTE_ARQUIVO, 8,
		nome, rg, cpf, numero_contato, cep, endereco, data_nascimento, plano_saude
	);
}
