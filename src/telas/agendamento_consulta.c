#include <stdio.h>
#include <stdlib.h>
#include "../lib/entrada.h"


int agendamento_consulta() {

    char nome_paciente[100]; //nome do paciente
    char especialidade_medica[100]; //qual a especialidade médica o paciente precisa
    char nome_medico[100]; //qual o nome do médico responsável pelo atendimento
    char data[10]; //data da consulta agendada
    char hora[6]; //hora da consulta agendada
    int opcoes; 


    printf("Agendamento de Consulta\n\n\n");

    leia_digito("O paciente possue cadastro? ", &opcoes);

    if (opcoes == 1) { //caso o paciente já tenha cadastro o usuário digitará o número 1 para realizar o agendamento da consulta

        leia_string("Digite o nome do paciente: ", nome_paciente);

        leia_string("Qual a especialidade méfica? ", especialidade_medica);

        leia_string("Qual o nome do médico?: ", nome_medico);


         /* tem como colocar para aparecer opções de medicos disponiveis e de datas e horas disponiveis?*/ 

        leia_string("Digite a data da consulta ", data); /*precisa colocar algum modelo para data e hora?*/

        leia_string("Digite a hora da consulta: ", hora); 

        printf("Consulta agendada com sucesso!\n\n");
    }
    
    else if (opcoes == 2) { //caso o paciente não tenha cadastro o usuário digitará o número 2 para que seja trasferido para realização do cadastro do paciente
        printf("Faça o cadastro do paciente\n");
    }
    else {
        return 1;
    }
    return 0;
 }
