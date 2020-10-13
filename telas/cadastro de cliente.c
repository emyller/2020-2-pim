#include <stdio.h>
#include <stdlib.h>

 main() {
	

	char nome[200]; // Nome do cliente.
	char rg[10]; // RG do cliente.
	char cpf[12]; // CPF do cliente.
	char numero_contato[12]; // Número de contato do cliente.
	char cep[11]; // CEP do cliente.
	char resposta; // RESPOSTA para o comando "do while" em confirmações se os dados estão corretos ou não.
	char endereco[200]; // Endereço do cliente com numero da casa.
	char data_nascimento[20]; // Data de Nascimento do cliente.
	char plano_saude[50]; // Plano de saude do cliente.
	int casos;
	
	
	
	printf("--  Cadastro de clientes. --\n\n");
	
		
	printf("Nome: ");
	fgets(nome, 200, stdin);
	
	    do  {
	
     	printf("\nDigite o RG: ");
	    fflush(stdin);
	    fgets(rg, 10, stdin);
	    printf("\nO Numero de RG digitado esta correto?\n S/N :  ");
	    scanf(" %c", &resposta);
	    fflush(stdin);
	    } while (resposta == 'n');
		    
	    do {
		printf("\nDigite o CPF: ");
		fflush(stdin);
		fgets(cpf, 12, stdin);
		printf("\nO Numero de CPF digitado esta correto?\n S/N :  ");
		scanf(" %c", &resposta);
		fflush(stdin);
		} while (resposta == 'n');
	    
	    do {
	
	printf("\nInsira um numero para contato: ");
	fflush(stdin);
	fgets(numero_contato, 12, stdin);
	
	printf("Insira a data de nascimento com tracos: ");
	fflush(stdin);
	fgets(data_nascimento, 20,stdin);
	
	printf("Insira o CEP: ");
	fflush(stdin);
	fgets(cep, 11, stdin);
	
	printf("Insira o endereco (sem acentos): ");
	fflush(stdin);
	fgets(endereco, 200, stdin);
	
	printf("O Paciente possui plano de saude?\n[1] Para escrever o plano de saude\n[2] Para Consulta particular\n Opcao:  ");
	scanf("%d", &casos);
	
	     switch (casos) {
		      case 1: printf("\nQual Plano de Saude o cliente possui?\n");
	        	      fflush(stdin);
                      fgets(plano_saude, 50, stdin); break;
	          case 2: printf("\nCliente em consulta particular\n"); break;
	          default:("Opcao invalida !!\n");
	                    }
		 
	printf("Todos os dados foram preenchidos corretamente? S/N:  ");
    scanf(" %c", &resposta);
        } while (resposta == 'n');
        
    system("cls");
    printf("Nome do paciente: %s", nome);
    printf("RG: %s\n", rg);
    printf("CPF: %s\n", cpf);
    printf("Numero de contato: %s\n", numero_contato);
    printf("Data de Nascimento: %s", data_nascimento);
    printf("CEP: %s", cep);
    printf("Endereco: %s", endereco);
    printf("Plano de saude: %s\n", plano_saude);
    system("pause");
	
	
	return 0;
