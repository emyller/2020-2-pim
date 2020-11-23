#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CADASTRO_PACIENTE_ARQUIVO "cadastro_paciente.txt"


int cadastro_paciente()  {

	char nome[200] = "";
	char rg[10] = "";
	char cpf[12] = "";
	char numero_contato[12] = "";
	char cep[11] = "";
	char endereco[200] = "";
	char data_nascimento[20] = "";
	char plano_saude[50] = "";
	int dados_corretos;
	int metodo_consulta;

	puts("Cadastro de Pacientes");

	leia_resposta("Nome", nome);
	leia_resposta_formato("CPF", "XXX.XXX.XXX-XX", cpf);
	leia_resposta_formato("RG", "somente números", rg);

	do {
		leia_resposta_formato("Telefone", "XX XXXXX-XXXX", numero_contato);
		leia_resposta_formato("Data de nascimento", "YYYY-MM-DD", data_nascimento);
		leia_resposta_formato("CEP", "XXXXX-XXX", cep);
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
