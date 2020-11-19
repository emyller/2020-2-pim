#include <stdio.h>
#include <stdlib.h>
#include "../lib/entrada.h"


int cadastro_medico() {

    char nome_medico[100]; //nome do médico
    char especialidade[100]; //especialidade médica
    char cep[8]; //número do CEP residencial
    char endereco[200]; //endereço da residência
    char email[100]; //email para contato do médico
    char rg[9]; //número do RG
    char cpf[11]; //número do CPF
    char crm[6]; //númedo do CRM
    char nascimento[8]; //data de nascimento
    char telefone[16]; //tefelone para contato
    


    puts("Cadastro Médico\n\n");

    leia_string("Digite o nome do médico: ", nome_medico);

    leia_string("Número do RG (somente números): ", rg); 

    leia_string("Número do CPF (somente números): ", cpf);

    leia_string("Insira o CRM: ", crm);

    leia_string("Data de nascimento (formato: XX/XX/XXXX): ", nascimento);

    leia_string("Qual a especialidade médica? ", especialidade);

    leia_string("Email para contato: ", email);

    leia_string("Número para contato (inserir (DDD)+XXXXX-XXXX): ", telefone);

    leia_string("Número do CEP: ", cep);

    leia_string("Endereço residencial: ", endereco);

    puts("Cadastro efetuado com sucesso!\n\n");
    

    return 0;
 }