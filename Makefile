all:
	# Cria diretório de build
	mkdir -p build

	# Compila todas as libs
	gcc -c src/lib/entrada.c -o build/lib_entrada.o

	# Compila todas as telas
	gcc -c src/telas/login.c -o build/tela_login.o
	gcc -c src/telas/elogios_reclamacoes.c -o build/elogios_reclamacoes.o
	gcc -c src/telas/agendamento_consulta.c -o build/agendamento_consulta.o
	gcc -c src/telas/cancelamento_consulta.c -o build/cancelamento_consulta.o
	gcc -c src/telas/cadastro_medico.c -o build/cadastro_medico.o

	# Compila menu
	gcc -c src/programa.c -o build/programa.o

	# Linka objetos em um exexcutável
	gcc build/*.o -o build/programa
