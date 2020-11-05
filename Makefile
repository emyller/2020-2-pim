all:
	# Compila todas as libs
	gcc -c src/lib/entrada.c -o build/lib_entrada.o

	# Compila menu
	gcc -c src/programa.c -o build/programa.o

	# Linka objetos em um exexcutável
	gcc build/*.o -o build/programa
