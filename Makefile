all:
	# Cria diretório de build
	mkdir -p build

	# Compila todas as libs
	gcc -c src/lib/entrada.c -o build/lib_entrada.o

	# Compila todas as telas
	gcc -c src/telas/login.c -o build/tela_login.o
	gcc -c src/telas/elogios_reclamacoes.c -o build/elogios_reclamacoes.o

	# Compila menu
	gcc -c src/programa.c -o build/programa.o

	# Linka objetos em um exexcutável
	gcc build/*.o -o build/programa
