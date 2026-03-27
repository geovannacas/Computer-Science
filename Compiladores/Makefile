# O alvo principal gera o executável g-v1
g-v1: sint.o lex.o
	gcc sint.o lex.o -o g-v1 -lfl

# Compila o arquivo C do sintático para objeto
sint.o: sint.c
	gcc -c sint.c -o sint.o

# Gera o código C e o header sint.h a partir do Bison
sint.c: sint.y
	bison -d -osint.c sint.y

# Compila o arquivo C do léxico para objeto
lex.o: lex.c
	gcc -c lex.c -o lex.o

# Gera o código C do léxico a partir do Flex
lex.c: lex.l
	flex -olex.c lex.l

# Limpa todos os arquivos gerados
clean:
	rm -f *.o g-v1 sint.c sint.h lex.c