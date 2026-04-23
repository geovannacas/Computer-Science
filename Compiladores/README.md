# Compilador G-V1 — Linguagem Goianinha

Compilador didático para a linguagem G-V1 (Goianinha), desenvolvido na disciplina de Compiladores — UFG 2026-1.

---

## Estrutura dos arquivos e fases

```
lex.l           →  Analisador Léxico (gerado pelo Flex)
sint.y          →  Analisador Sintático (gerado pelo Bison) + main()
tipos.h / ast.c →  Estrutura da AST compartilhada por todas as fases
tabsim.h/.c     →  Tabela de Símbolos (pilha de escopos)
semantico.h/.c  →  Analisador Semântico
gerador.h/.c    →  Gerador de Código MIPS
```

### Como cada fase conversa com a próxima

```
arquivo.g
   │
   ▼  lex.l (Flex)
   │  Reconhece tokens: palavras-chave, identificadores, constantes,
   │  strings, comentários. Reporta erros léxicos e encerra.
   │  Retorna tokens via yylex() para o Bison.
   │
   ▼  sint.y (Bison — LALR)
   │  Consome tokens e aplica as regras da gramática G-V1.
   │  Cada redução executa uma ação semântica que cria nós NoAST
   │  com criaNo() e os encadeia. Ao final, `raiz` aponta para
   │  o bloco principal. Reporta erros sintáticos e encerra.
   │
   ▼  semantico.c
   │  Percurso em pré-ordem na AST.
   │  Abre/fecha escopos na PilhaTabelas conforme encontra blocos.
   │  Verifica: declaração antes do uso, sem redeclaração no mesmo
   │  escopo, compatibilidade de tipos em atribuições e operações.
   │  Reporta erros semânticos e encerra.
   │
   ▼  gerador.c
      Segundo percurso na AST (programa já verificado).
      Reconstrói a PilhaTabelas atribuindo offsets negativos de $fp
      a cada variável. Emite assembly MIPS para stdout:
        • .data  — strings literais
        • .text  — código com syscalls para I/O e instruções MIPS
```

---

## Compilar

```bash
make          # gera o executável ./g-v1
make clean    # remove objetos e executável
make rebuild  # limpeza + recompilação
```

Requer: **gcc ≥ 14**, **flex 2.6.4**, **bison 3.8.2**.

---

## Executar

```bash
./g-v1 programa.g           # imprime assembly MIPS em stdout
./g-v1 programa.g > out.asm # salva o assembly num arquivo
```

Em caso de erro léxico, sintático ou semântico o programa imprime
a mensagem em stderr e retorna código de saída 1.

---

## Rodar o assembly no MARS

1. Baixe o MARS: <http://courses.missouristate.edu/kenvollmar/mars/>
2. Gere o assembly: `./g-v1 fatorial.g > fatorial.asm`
3. Execute: `java -jar Mars.jar fatorial.asm`

O arquivo `fatorial.asm` já está gerado e pronto para rodar.

---

## Formato das mensagens de erro

| Fase | Exemplo |
|------|---------|
| Léxico | `ERRO: CARACTERE INVALIDO 5` |
| Léxico | `ERRO: CADEIA DE CARACTERES OCUPA MAIS DE UMA LINHA 3` |
| Léxico | `ERRO: COMENTARIO NAO TERMINA 10` |
| Sintático | `ERRO: syntax error na linha 4` |
| Semântico | `ERRO: VARIAVEL NAO DECLARADA: x na linha 7` |
| Semântico | `ERRO: VARIAVEL JA DECLARADA: x na linha 3` |
| Semântico | `ERRO: TIPOS INCOMPATIVEIS NA ATRIBUICAO DA VARIAVEL n na linha 6` |
| Semântico | `ERRO: OPERACAO ARITMETICA REQUER TIPO INT na linha 8` |
| Semântico | `ERRO: OPERACAO RELACIONAL COM TIPOS DIFERENTES na linha 9` |

---

## Arquivos de teste

### Erros léxicos (`testes/`)

| Arquivo | O que testa |
|---------|-------------|
| `erro_char_invalido.g` | Caractere `@` inválido na linguagem |
| `erro_cadeia_linha.g` | String que quebra de linha |
| `erro_comentario.g` | Comentário `/*` não fechado ao fim do arquivo |

### Erros semânticos (`testes/`)

| Arquivo | O que testa |
|---------|-------------|
| `erro_var_nao_declarada.g` | Uso de variável não declarada |
| `erro_var_ja_declarada.g` | Redeclaração no mesmo escopo |
| `erro_tipo_atribuicao.g` | Atribuição `int ← car` |
| `erro_tipo_aritmetico.g` | Aritmética (`+`) com operando `car` |
| `erro_tipo_relacional.g` | Comparação entre `int` e `car` |

### Programas corretos (`testes/`)

| Arquivo | O que demonstra |
|---------|-----------------|
| `teste_sombramento.g` | Variável interna sobrepõe a externa; ao sair do escopo, a externa volta (saída: 42, 99, 42) |
| `teste_logico_relacional.g` | `&`, `\|\|`, `!` combinados com `>`, `==`, `>=` (saída: 1, 1, 1, 1) |

### Programas completos (raiz do projeto)

| Arquivo | Descrição |
|---------|-----------|
| `fatorial.g` | Fatorial com loop e I/O |
| `NotaEmConceito.g` | Condicionais encadeados com tipo `car` |
| `SeqOrdenada.g` | Verificação de sequência com escopos aninhados |
| `PA.g` | N-ésimo termo de progressão aritmética |
| `Soma.g` | Soma de progressão aritmética |

---

## Convenções do gerador MIPS

- `$fp` — fixo no início do programa (`move $fp, $sp`); serve de âncora para todos os offsets de variáveis
- `$sp` — ajustado na entrada/saída de cada bloco com declarações
- Variáveis: offsets **negativos** de `$fp` (primeira: `-4($fp)`, segunda: `-8($fp)`, …)
- Expressões binárias: resultado esquerdo vai ao topo do stack → direito avaliado → pop → operação em `$t0`
- Pseudoinstruções SPIM/MARS: `seq`, `sne`, `sgt`, `sge`, `sle`, `mul`, `li`, `la`, `move`
