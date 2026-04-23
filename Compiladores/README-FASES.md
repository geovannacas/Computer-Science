# Compilador G-V1 — Linguagem Goianinha

Compilador didático para a linguagem G-V1 (Goianinha), desenvolvido na disciplina de Compiladores — UFG 2026-1.

---

## Visão geral das fases

```
arquivo.g  →  [Fase 1: Léxico]  →  [Fase 2: Sintático + AST]
           →  [Fase 3: Semântico]  →  [Fase 4: Gerador MIPS]  →  stdout
```

Cada fase consome a saída da anterior. Um erro em qualquer fase imprime a mensagem em `stderr` e encerra com código 1 — as fases seguintes não chegam a rodar.

---

## Fase 1 — Analisador Léxico (`g-v1.l`)

**O que faz:** Lê o arquivo-fonte caractere a caractere e agrupa sequências em *tokens* que o Bison vai consumir. Reconhece: palavras-chave da linguagem (`principal`, `se`, `enquanto`, `leia`, `escreva`, `novalinha`, `int`, `car`, `entao`, `senao`, `fimse`), identificadores, constantes inteiras, constantes de caractere (`'a'`, `'\n'`), strings entre aspas duplas, e operadores/delimitadores.

**Por que Flex:** O Flex gera um autômato finito determinístico a partir das expressões regulares definidas em `g-v1.l`. Isso é correto e eficiente para o reconhecimento de tokens — tarefa puramente regular, sem necessidade de pilha.

**Lógica dos estados exclusivos:**

| Estado | Propósito |
|--------|-----------|
| `INICIAL` (padrão) | Código normal |
| `%x COMENTARIO` | Dentro de `/* ... */` — ignora tudo até encontrar `*/`; erro se EOF chegar antes |
| `%x CADEIA` | Dentro de `"..."` — acumula caracteres; erro se `\n` aparecer antes de fechar |

Os estados exclusivos são necessários porque comentários e strings têm regras próprias que conflitam com o léxico normal (p. ex., `*/` dentro de um comentário não é operador).

**Tratamento de erros léxicos:** A função `erro_lexico()` imprime em `stderr` e chama `exit(1)`. Não tenta recuperação — um caractere inválido no meio do código tornaria os tokens seguintes ambíguos.

**Formato do lexema de `CARCONST`:** O lexema armazena o texto completo incluindo as aspas simples (p. ex., `'a'` ou `'\n'`). O gerador de código usa esse formato para extrair o valor ASCII via `carconst_valor()`.

**Por que `INTCONST` não aceita sinal (`+`/`-`):** O sinal faz parte da gramática, não do léxico. A regra `UnExpr → '-' PrimExpr` trata a negação aritmética. Se o léxico aceitasse `-5` como token único, o parser não conseguiria distinguir `a - 5` (subtração binária) de `a` seguido de `-5` (constante negativa).

---

## Fase 2 — Analisador Sintático e AST (`g-v1.y`, `tipos.h`, `ast.c`)

### `g-v1.y` — Gramática LALR(1) + ações semânticas + `main()`

**O que faz:** Define a gramática de G-V1 em formato Bison. Cada redução executa uma ação C que cria um nó da AST via `criaNo()` e conecta os filhos. Ao fim de `yyparse()`, a variável global `raiz` aponta para o nó raiz (o bloco `principal`). Em `main()` chama as fases seguintes:

```c
if (yyparse() == 0 && raiz != NULL) {
    analisaSemantico(raiz);   // Fase 3
    geraCodigoMIPS(raiz);     // Fase 4
}
```

**Por que LALR(1):** A gramática de G-V1 é simples o suficiente para LALR(1) — sem ambiguidades que exijam GLR ou precedência complexa. O Bison resolve as poucas precedências de operadores (`||`, `&`, `!`, relacionais, aritméticos) pelas diretivas `%left`/`%right`.

**Estrutura dos nós relevantes:**

| Nó | filho1 | filho2 | filho3 |
|----|--------|--------|--------|
| `NO_BLOCO` | cadeia de `NO_DECL_VAR` (via `proximo`) | cadeia de comandos (via `proximo`) | — |
| `NO_SE` | condição | ramo `entao` | ramo `senao` (ou NULL) |
| `NO_ATRIBUICAO` | `NO_IDENTIFICADOR` (alvo) | expressão (valor) | — |
| `NO_ENQUANTO` | condição | corpo | — |

**Por que a cadeia `proximo`:** Declarações e comandos dentro de um bloco formam listas ligadas pelo campo `proximo` dos nós (em vez de criar um nó-lista artificial). Isso mantém a AST simples e facilita a iteração linear nas fases seguintes.

### `tipos.h` — Definição dos tipos de nó

**O que faz:** Define o enum `TipoNo` com todos os tipos de nó possíveis e a struct `NoAST`:

```c
typedef struct NoAST {
    TipoNo   tipo;
    char*    lexema;   // texto do token (identificador, constante, etc.)
    int      linha;    // linha no fonte — usada nas mensagens de erro
    NoAST*   filho1, *filho2, *filho3;
    NoAST*   proximo;  // próximo nó na mesma lista (bloco, decl, etc.)
} NoAST;
```

**Por que três filhos fixos:** A construção com mais filhos na linguagem G-V1 é `se/entao/senao` (3 filhos). Usar ponteiros nomeados (`filho1`, `filho2`, `filho3`) em vez de um vetor dinâmico é mais legível e suficiente para a linguagem.

### `ast.c` — Operações sobre a AST

**O que faz:** Implementa `criaNo()` (aloca e inicializa um nó), `adicionaIrmao()` (encadeia via `proximo`) e `imprimeArvore()` (debug). Compartilhado por todas as fases — nenhuma fase modifica a AST, só lê.

---

## Fase 3 — Analisador Semântico (`tabsim.h`, `tabsim.c`, `semantico.h`, `semantico.c`)

### `tabsim.h` / `tabsim.c` — Tabela de Símbolos (pilha de escopos)

**O que faz:** Implementa uma pilha de tabelas hash, onde cada nível corresponde a um escopo aberto (um bloco com declarações). As principais operações são:

| Função | Descrição |
|--------|-----------|
| `criaEscopo` | Empilha nova tabela; salva `offset_corrente` em `offset_base` |
| `insereTabela` | Insere símbolo no escopo do topo; decrementa `offset_corrente` em 4 |
| `pesquisaTabela` | Busca do topo para a raiz — implementa visibilidade léxica (shadowing) |
| `pesquisaEscopoAtual` | Busca só no topo — detecta redeclaração no mesmo escopo |
| `removeEscopo` | Desempilha; restaura `offset_corrente = offset_base`; retorna bytes liberados |

**Por que pilha de tabelas hash:** Cada escopo é independente — ao fechar um bloco, seus símbolos somem sem afetar os externos. A busca de fora para dentro (do topo até NULL) implementa naturalmente o shadowing: a variável mais interna com mesmo nome é encontrada primeiro.

**Invariante do `offset_corrente`:** Este campo acumula offsets negativos em relação a `$fp` ao longo de todos os escopos aninhados. Cada novo símbolo recebe o próximo múltiplo de −4. Quando um escopo é removido, `offset_corrente` volta ao valor que tinha antes (salvo em `offset_base`), de forma que o espaço daquele escopo é "liberado" sem bagunçar os escopos externos.

**Por que a mesma `PilhaTabelas` serve para as fases 3 e 4:** A tabela de símbolos é instanciada separadamente em cada fase (`pilha_sem` em `semantico.c` e `pilha_gen` em `gerador.c`). Na fase 3 os offsets são calculados mas não usados (só os tipos importam); na fase 4 os mesmos offsets guiam a emissão de `lw`/`sw`.

### `semantico.h` / `semantico.c` — Análise Semântica

**O que faz:** Percorre a AST em pré-ordem e verifica as regras semânticas de G-V1:

1. **Declaração antes do uso** — `pesquisaTabela` antes de qualquer uso de identificador.
2. **Sem redeclaração no mesmo escopo** — `insereTabela` retorna 0 se o nome já existe no topo.
3. **Compatibilidade de tipos** — `analisa_expr()` retorna `"int"`, `"car"` ou `"str"` e as operações verificam os tipos recebidos.

**Regras de tipo implementadas:**

| Operação | Regra |
|----------|-------|
| Aritmética (`+`, `-`, `*`, `/`) | Ambos os operandos devem ser `int` |
| Relacional (`>`, `<`, `==`, etc.) | Ambos devem ser do mesmo tipo (int–int ou car–car) |
| Lógico (`&`, `\|\|`) | Ambos devem ser `int` |
| Negação aritmética (`-unário`) | Operando deve ser `int` |
| Atribuição | Lado direito deve ter o mesmo tipo que a variável |

**Por que `analisa_bloco` abre escopo só quando `filho1 != NULL`:** A gramática permite blocos sem declarações (só comandos). Abrir um escopo vazio seria um desperdício e poderia gerar entradas incorretas na pilha; além disso, a regra de shadowing depende de haver uma declaração real para sobrepor.

**Encerramento imediato em erro:** `erro_semantico()` chama `exit(1)`. A linguagem G-V1 não tem mecanismo de recuperação de erros semânticos no spec, e continuar com um símbolo não-declarado geraria cascata de erros falsos.

---

## Fase 4 — Gerador de Código MIPS (`gerador.h`, `gerador.c`)

**O que faz:** Segundo percurso na AST (que já passou pela semântica). Recria a `PilhaTabelas` para obter os offsets das variáveis e emite assembly MIPS para `stdout`.

### Convenção de registradores

| Registrador | Uso |
|-------------|-----|
| `$fp` | Fixo: aponta para o topo do stack no início de `main`. Serve de âncora absoluta para todos os offsets de variáveis |
| `$sp` | Ajustado em cada bloco com declarações: decresce na entrada, cresce na saída |
| `$t0` | Resultado de qualquer expressão avaliada por `gera_expr()` |
| `$t1` | Operando esquerdo temporário nas operações binárias |
| `$v0`, `$a0` | Syscalls MIPS padrão |

**Por que `$fp` é fixo:** Se `$sp` fosse usado como âncora, o offset de cada variável mudaria a cada `addiu $sp` de um bloco aninhado. Com `$fp` fixo, o offset calculado na inserção na tabela (−4, −8, −12, …) é válido durante todo o tempo de vida da variável, independentemente de quantos blocos internos estejam ativos.

### Avaliação de expressões binárias

O macro `AVALIA_BINARIO` implementa o padrão:

```
avalia esquerda → $t0
push $t0 na pilha
avalia direita → $t0
pop em $t1
```

Após o macro: `$t1` = esquerda, `$t0` = direita. Isso garante que a avaliação do lado direito não sobrescreva o esquerdo, mesmo quando ambos usam `$t0` internamente.

### Strings literais

`coleta_strings()` pré-varre a AST antes de emitir qualquer código e registra todas as strings via `get_str_id()`, que deduplica por valor. O segmento `.data` é emitido primeiro com rótulos `__str_0`, `__str_1`, … — exigência do assembler MIPS que processa `.data` antes de `.text`.

### Rótulos de controle de fluxo

Cada `se` e `enquanto` recebe um índice único via `novo_label()` (contador global). Os rótulos gerados são `__senao_N`, `__fimse_N`, `__enquanto_cond_N`, `__enquanto_fim_N`. O prefixo `__` evita colisões com identificadores do programa.

### Syscalls utilizadas

| Código | Operação |
|--------|----------|
| 1 | `print_int` |
| 4 | `print_string` |
| 5 | `read_int` |
| 10 | `exit` |
| 11 | `print_char` |
| 12 | `read_char` |

---

## Como compilar e executar

```bash
make          # gera o executável ./g-v1
make clean    # remove objetos e executável
make rebuild  # limpeza + recompilação
```

Requer: **gcc ≥ 14**, **flex 2.6.4**, **bison 3.8.2**.

```bash
./g-v1 programa.g           # imprime assembly MIPS em stdout
./g-v1 programa.g > out.asm # salva o assembly num arquivo
```

---

## Rodar o assembly no MARS

```bash
java -jar Mars.jar fatorial.asm
```

O arquivo `fatorial.asm` já está gerado e pronto para rodar.

---