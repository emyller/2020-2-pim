#include <stdio.h>
#include <stdlib.h>
#include "../lib/entrada.h"


int cadastro_funcionario ()  {

	char nome[100];
	char sexo[20];
	char data_nascimento[15];
	char estado_civil[15];
	char cpf[15];
	char rg[15];
	char inss[15];
	char telefone_celular[15];
	char telefone_residencial[15];
	char e_mail[100];
	char nome_cracha[20];
	char especialidade_cracha[50];
	char formacao[100];
	char faculdade[100];
	char curso[100];
	char ano_conclusao[50];
	char endereco[300];
	char complemento[50];
	char cep[20];
	int ensino_superior;
	int resposta;

	puts("---- Cadastro de Funcion�rios ----");

	// L� os dados basicos da pessoa.
	leia_string("Insira o nome: ", nome);
	leia_string("Insira o sexo: ", sexo);
	leia_string("insira a data de nascimento: ", data_nascimento);
	leia_string("Insira o Estado Civil: ", estado_civil);
	leia_string("Insira o CPF do funcion�rio: ", cpf);
	leia_string("Insira o RG do funcion�rio: ", rg);
	leia_string("Insira o INSS do funcion�rio: ", inss);
	leia_string("Insira o n�mero de celular: ", telefone_celular);
	leia_string("Insira o E-MAIL de contato: ", e_mail);
	leia_string("Insira o nome que ser� exibido no crach�: ", nome_cracha);
	leia_string("Insira a especialidade exibida no crach�: ", especialidade_cracha);
	leia_digito("Possui ensino T�cnico ou Superior? [0/1]", &ensino_superior);


	if (ensino_superior == 1) { //L� se o funcionario possui ensino superior
		do {
			puts("-- Dados do ensino t�cnico / superior. ");
			leia_string("Curso conclu�do: ", curso);
			leia_string("Faculdade de conclus�o: ", faculdade);
			leia_string("Ano de conclus�o: ", ano_conclusao);
			leia_digito("Dados preenchidos corretamente? [0/1]", &resposta);
		}
		while (resposta == 0);
	}


	do {
		puts("--- Endere�o e contato ---");
		leia_string("CEP: ", cep);
		leia_string("Entre com o endere�o: ", endereco);
		leia_string("Complemento: ", complemento);
		leia_string("Telefone Residencial: ", telefone_residencial);
		leia_digito("Dados preenchidos corretamente? [0/1] ", &resposta);
	}
	while (resposta == 0);
}
