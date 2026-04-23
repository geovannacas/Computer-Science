# Makefile para G-V1 - Compilador da Linguagem Goianinha
# Versão 1.0 - Projeto de Compiladores

CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lfl

# Executável final
TARGET = g-v1

# Arquivos objeto
OBJECTS = sint.o lex.o ast.o tabsim.o semantico.o gerador.o

# Arquivos gerados
GENERATED = sint.c sint.h lex.c

# Arquivos de entrada
FLEX_INPUT = lex.l
BISON_INPUT = sint.y
AST_INPUT = ast.c

# Header files
HEADERS = tipos.h tabsim.h semantico.h gerador.h

# Alvo principal
all: $(TARGET)

# Gerar executável
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "✓ Compilação concluída com sucesso!"
	@echo "  Executável: ./$(TARGET)"
	@echo "  Uso: ./$(TARGET) arquivo.g"

# Compilar arquivo objeto sint.o
sint.o: sint.c $(HEADERS)
	$(CC) $(CFLAGS) -c sint.c -o sint.o

# Gerar sint.c e sint.h a partir de sint.y
sint.c sint.h: $(BISON_INPUT)
	$(BISON) -d -o sint.c $(BISON_INPUT)
	@echo "✓ Arquivo sintático gerado: sint.c e sint.h"

# Compilar arquivo objeto lex.o
lex.o: lex.c sint.h
	$(CC) $(CFLAGS) -c lex.c -o lex.o

# Gerar lex.c a partir de lex.l
lex.c: $(FLEX_INPUT)
	$(FLEX) -o lex.c $(FLEX_INPUT)
	@echo "✓ Analisador léxico gerado: lex.c"

# Compilar arquivo objeto ast.o
ast.o: $(AST_INPUT) $(HEADERS)
	$(CC) $(CFLAGS) -c $(AST_INPUT) -o ast.o

# Compilar tabela de simbolos
tabsim.o: tabsim.c tabsim.h
	$(CC) $(CFLAGS) -c tabsim.c -o tabsim.o

# Compilar analisador semantico
semantico.o: semantico.c semantico.h tipos.h tabsim.h
	$(CC) $(CFLAGS) -c semantico.c -o semantico.o

# Compilar gerador de codigo MIPS
gerador.o: gerador.c gerador.h tipos.h tabsim.h
	$(CC) $(CFLAGS) -c gerador.c -o gerador.o

# Limpeza de arquivos gerados
clean:
	rm -f $(OBJECTS) $(TARGET) $(GENERATED)
	@echo "✓ Arquivos limpos"

# Limpeza completa (volta ao estado original)
distclean: clean
	@echo "✓ Limpeza completa realizada"

# Recompilação forçada
rebuild: clean all

# Phony targets (não são arquivos reais)
.PHONY: all clean distclean rebuild

# Informações de debug
info:
	@echo "=== Informações de Compilação G-V1 ==="
	@echo "Compilador: $(CC)"
	@echo "Flags C: $(CFLAGS)"
	@echo "Flex: $(FLEX)"
	@echo "Bison: $(BISON)"
	@echo "Executável: $(TARGET)"
	@echo "Objeto: $(OBJECTS)"
	@echo "Arquivos gerados: $(GENERATED)"