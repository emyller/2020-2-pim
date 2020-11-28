all:
	# Cria diretório de build
	mkdir -p build

	# Compila todas as libs
	gcc -c src/lib/entrada.c -o build/lib_entrada.o
	gcc -c src/lib/arquivos.c -o build/lib_arquivos.o
	gcc -c src/lib/data_hora.c -o build/lib_data_hora.o
	gcc -c src/lib/utils.c -o build/lib_utils.o

	# Compila todas as telas
	gcc -c src/telas/login.c -o build/tela_login.o
	gcc -c src/telas/elogios_reclamacoes.c -o build/elogios_reclamacoes.o
	gcc -c src/telas/agendamento_consulta.c -o build/agendamento_consulta.o
	gcc -c src/telas/cancelamento_consulta.c -o build/cancelamento_consulta.o
	gcc -c src/telas/cadastro_medico.c -o build/cadastro_medico.o
	gcc -c src/telas/cadastro_funcionario.c -o build/cadastro_funcionario.o
	gcc -c src/telas/cadastro_paciente.c -o build/cadastro_paciente.o
	gcc -c src/telas/relatorios.c -o build/relatorios.o
	gcc -c src/telas/sincronizacao.c -o build/sincronizacao.o

	# Compila menu
	gcc -c src/programa.c -o build/programa.o

	# Linka objetos em um executável
	gcc build/*.o -o build/programa
