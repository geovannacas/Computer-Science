# APRESENTACAO 

Este documento foi escrito para servir de roteiro de defesa oral do projeto. Ele é específico ao código deste repositório e cita arquivos, funções, estruturas e linhas reais.

## 1. Visão geral da arquitetura

O fluxo completo do compilador é:

1. O Flex em [g-v1.l](g-v1.l#L7) reconhece palavras-chave, identificadores, constantes, comentários e erros léxicos.
2. O Bison em [g-v1.y](g-v1.y#L39) reduz a entrada para uma AST, chamando [criaNo](ast.c#L3) e [adicionaIrmao](ast.c#L20) para montar a árvore.
3. A AST é definida em [tipos.h](tipos.h#L8) e [tipos.h](tipos.h#L23), com o nó [NoAST](tipos.h#L23) contendo tipo, lexema, linha e três filhos mais o ponteiro de irmão.
4. A análise semântica começa em [analisaSemantico](semantico.c#L190), que cria a pilha de tabelas com [iniciaTabela](tabsim.c#L9) e percorre a AST chamando [analisa_bloco](semantico.c#L35), [analisa_comando](semantico.c#L54) e [analisa_expr](semantico.c#L96).
5. A geração MIPS começa em [geraCodigoMIPS](gerador.c#L334), faz uma pré-varredura de strings com [coleta_strings](gerador.c#L37), cria a tabela de símbolos de geração com [iniciaTabela](tabsim.c#L9) e percorre a AST novamente com [gera_bloco](gerador.c#L293), [gera_comando](gerador.c#L202) e [gera_expr](gerador.c#L74).

No próprio parser, a raiz da AST é definida na produção [Programa : PRINCIPAL Bloco](g-v1.y#L39), que salva o bloco principal em [raiz](g-v1.y#L11) e depois o `main` chama a semântica e o gerador em sequência em [g-v1.y](g-v1.y#L240).

Em resumo, o código se conecta assim: lexer produz tokens -> parser monta AST -> semântica valida escopos e tipos -> gerador emite MIPS.

## 2. Tabela de Símbolos - justificativa de implementação

A tabela de símbolos foi implementada como uma pilha de escopos, onde cada escopo é uma tabela hash com encadeamento separado. A estrutura está em [tabsim.h](tabsim.h#L10), [tabsim.h](tabsim.h#L18) e [tabsim.h](tabsim.h#L25). Cada escopo usa `HASH_TABSIM = 31` [tabsim.h](tabsim.h#L8) e cada bucket aponta para uma lista encadeada de [Simbolo](tabsim.h#L10).

Essa escolha faz sentido para o projeto porque a linguagem tem blocos aninhados e o escopo corrente importa tanto para detectar redeclaração quanto para resolver uso de identificadores. Com hash, a busca/inserção esperada é O(1) por escopo; com listas encadeadas, colisões continuam simples de tratar. O pior caso teórico é O(n) em um bucket muito carregado, mas para este compilador o conjunto de símbolos é pequeno e o custo esperado é baixo.

A pilha de escopos é controlada por [iniciaTabela](tabsim.c#L9), [criaEscopo](tabsim.c#L17), [pesquisaEscopoAtual](tabsim.c#L45), [pesquisaTabela](tabsim.c#L56), [removeEscopo](tabsim.c#L70) e [liberaTabela](tabsim.c#L91).

As funções funcionam assim:

- [iniciaTabela](tabsim.c#L9) cria a pilha vazia e zera o offset corrente.
- [criaEscopo](tabsim.c#L17) empilha um novo [TabelaSimbolos](tabsim.h#L18) e grava o offset base do novo bloco.
- [insereTabela](tabsim.c#L26) insere variáveis apenas no escopo atual, rejeitando redeclaração no mesmo bloco com auxílio de [pesquisaEscopoAtual](tabsim.c#L45).
- [pesquisaTabela](tabsim.c#L56) sobe pela cadeia de escopos até encontrar o identificador.
- [removeEscopo](tabsim.c#L70) libera o escopo atual, restaura o offset anterior e devolve a quantidade de bytes do frame.

Em termos de layout de memória, cada variável consome 4 bytes e recebe um offset negativo em relação a `$fp`. Isso está explícito no comentário da estrutura [Simbolo](tabsim.h#L10) e na lógica de [insereTabela](tabsim.c#L26), que decrementa `offset_corrente` de 4 em 4.

## 3. AST - lógica de construção

A AST é definida pela enumeração [TipoNo](tipos.h#L8) e pela estrutura [NoAST](tipos.h#L23). Os campos relevantes são `tipo`, `lexema`, `linha`, `filho1`, `filho2`, `filho3` e `proximo`. Isso permite representar tanto árvores binárias quanto listas encadeadas de nós irmãos.

As funções centrais são [criaNo](ast.c#L3), [adicionaIrmao](ast.c#L20) e [imprimeArvore](ast.c#L62). A função [criaNo](ast.c#L3) aloca o nó, duplica o lexema quando existe e preenche os três filhos. [adicionaIrmao](ast.c#L20) percorre o encadeamento `proximo` até o final e liga o novo irmão ao fim da lista.

No parser, as ações semânticas constroem a árvore em cada redução. Exemplos importantes:

- [Bloco : '{' ListaComando '}'](g-v1.y#L52) cria [NO_BLOCO](tipos.h#L8) com `filho2` apontando para a lista de comandos.
- [Bloco : VarSection '{' ListaComando '}'](g-v1.y#L55) cria o mesmo tipo de nó, mas com `filho1` apontando para as declarações do bloco.
- [ListaDeclVar](g-v1.y#L69) cria nós [NO_DECL_VAR](tipos.h#L8) para cada identificador declarado e preenche o tipo com [NO_TIPO](tipos.h#L8).
- [Comando](g-v1.y#L132) cria nós para leitura, escrita, novalinha, if e while.
- [Expr](g-v1.y#L162) e as regras abaixo dela criam nós para atribuição, operações lógicas, relacionais, aritméticas e literais.

O percurso da AST acontece de forma recursiva em duas fases. Na semântica, [analisa_bloco](semantico.c#L35) percorre blocos, [analisa_comando](semantico.c#L54) percorre comandos e [analisa_expr](semantico.c#L96) percorre expressões. Na geração de código, [gera_bloco](gerador.c#L293), [gera_comando](gerador.c#L202) e [gera_expr](gerador.c#L74) repetem o mesmo padrão de travessia, mas emitindo MIPS.

## 4. Analisador Léxico (Flex)

O analisador léxico está em [g-v1.l](g-v1.l#L7). Ele usa [yylineno](g-v1.l#L13) para rastrear linha automaticamente e [erro_lexico](g-v1.l#L7) para padronizar mensagens e abortar a compilação no primeiro erro.

As regras mais relevantes são:

- [INTCONST](g-v1.l#L66) reconhece apenas dígitos sem sinal: o sinal menos não está no lexer, ele é tratado como operador unário na gramática. Isso faz o código lidar com números negativos pela regra [UnExpr : '-' PrimExpr](g-v1.y#L220).
- [CARCONST](g-v1.l#L68) aceita um caractere simples ou escapes específicos como `\n`, `\t`, `\\`, `\'` e `\0`.
- [CADEIACARACTERES](g-v1.l#L72), [g-v1.l#L75] e [g-v1.l#L82] usam o estado `CADEIA` para acumular o conteúdo entre aspas duplas.
- Comentários de múltiplas linhas começam em [g-v1.l](g-v1.l#L85) com `/*` e são consumidos pelo estado `COMENTARIO` em [g-v1.l](g-v1.l#L86) até [g-v1.l](g-v1.l#L89).
- Erros léxicos de caractere inválido são reportados em [g-v1.l](g-v1.l#L69) e [g-v1.l](g-v1.l#L91).
- Cadeias que atravessam linha geram erro específico em [g-v1.l](g-v1.l#L83).
- EOF dentro de cadeia ou comentário também é tratado em [g-v1.l](g-v1.l#L94).

O comportamento importante para falar é que o lexer já faz validação estrutural: string mal fechada, comentário mal fechado, caractere inválido e token fora da linguagem são interrompidos antes mesmo da semântica.

## 5. Analisador Sintático (Bison)

A gramática está em [g-v1.y](g-v1.y#L39). A raiz do programa é [Programa : PRINCIPAL Bloco](g-v1.y#L39), e o `main` faz o fluxo completo em [g-v1.y](g-v1.y#L240).

O arquivo não usa diretivas explícitas de precedência como `%left`, `%right` ou `%prec`. Em vez disso, a própria hierarquia dos não-terminais resolve a precedência de operadores: [OrExpr](g-v1.y#L172), [AndExpr](g-v1.y#L178), [EqExpr](g-v1.y#L184), [DesigExpr](g-v1.y#L192), [AddExpr](g-v1.y#L204), [MulExpr](g-v1.y#L212), [UnExpr](g-v1.y#L220) e [PrimExpr](g-v1.y#L228). Isso evita o acoplamento de precedência a regras globais e deixa a intenção do código clara.

O dangling-else é tratado pela própria forma da gramática: há duas regras separadas para [SE](g-v1.y#L153) sem `senao` e com `senao` em [g-v1.y](g-v1.y#L155). Como `FIMSE` é obrigatório, o fechamento fica explícito.

As ações semânticas montam a AST com [criaNo](ast.c#L3). Exemplos:

- [SE '(' Expr ')' ENTAO Comando FIMSE](g-v1.y#L153) cria [NO_SE](tipos.h#L8) sem ramo `senao`.
- [SE '(' Expr ')' ENTAO Comando SENAO Comando FIMSE](g-v1.y#L155) cria [NO_SE](tipos.h#L8) com ramo `senao`.
- [ENQUANTO '(' Expr ')' Comando](g-v1.y#L157) cria [NO_ENQUANTO](tipos.h#L8).

O tratamento de erro sintático fica em [yyerror](g-v1.y#L261), que imprime a mensagem com a linha corrente e aborta. Isso significa que o compilador para no primeiro erro sintático, sem tentar recuperação.

## 6. Análise Semântica

A entrada da semântica é [analisaSemantico](semantico.c#L190). Ela inicializa a pilha de tabelas, analisa o bloco raiz e libera tudo ao final.

As verificações realmente implementadas no código são estas:

### 6.1 Variável não declarada

Implementação em [analisa_comando](semantico.c#L54) para [NO_LEIA](tipos.h#L8) e em [analisa_expr](semantico.c#L96) para [NO_IDENTIFICADOR](tipos.h#L8) e [NO_ATRIBUICAO](tipos.h#L8). O erro emitido é `VARIAVEL NAO DECLARADA: <nome>`.

Exemplo G-V1:

```g
principal
{
    escreva x;
}
```

Teste relacionado: [testes/ErroSemantico/fatorial-VariavelNaoDeclaradaLin19.g](testes/ErroSemantico/fatorial-VariavelNaoDeclaradaLin19.g) e [testes/ErroSemantico/NotaEmConceito-VariavelNaoDeclaradaNoEsopoAtual.g](testes/ErroSemantico/NotaEmConceito-VariavelNaoDeclaradaNoEsopoAtual.g).

### 6.2 Redeclaração no mesmo escopo

Implementação em [processa_decl](semantico.c#L19), usando [insereTabela](tabsim.c#L26), que falha se o nome já existir no escopo atual. A mensagem é `VARIAVEL JA DECLARADA: <nome>`.

Exemplo G-V1:

```g
principal
{
    a: int;
    a: car;
    escreva a;
}
```

Teste relacionado: [testes/ErroSemantico/fatorial-VariavelRedeclaradaNoMesmoEscopoLin9.g](testes/ErroSemantico/fatorial-VariavelRedeclaradaNoMesmoEscopoLin9.g).

### 6.3 Tipo incompatível em atribuição

Implementação em [analisa_expr](semantico.c#L96), caso [NO_ATRIBUICAO](tipos.h#L8). O lado direito é analisado e comparado com o tipo da variável. O erro é `TIPOS INCOMPATIVEIS NA ATRIBUICAO DA VARIAVEL <nome>`.

Exemplo G-V1:

```g
principal
{
    c: car;
    c = 10;
}
```

Teste relacionado: [testes/ErroSemantico/NotaEmConceito-VariavelDeTipoIncopativelComExpressaoLin19.g](testes/ErroSemantico/NotaEmConceito-VariavelDeTipoIncopativelComExpressaoLin19.g).

### 6.4 Operação aritmética com tipo errado

Implementação em [analisa_expr](semantico.c#L96), casos [NO_SOMA](tipos.h#L8), [NO_SUBTRACAO](tipos.h#L8), [NO_MULTIPLICACAO](tipos.h#L8) e [NO_DIVISAO](tipos.h#L8). Ambos os operandos precisam ser `int`. A mensagem é `OPERACAO ARITMETICA REQUER TIPO INT`.

Exemplo G-V1:

```g
principal
{
    a: int;
    b: car;
    a = b + 1;
}
```

Teste relacionado: [testes/ErroSemantico/NotaEmConceito-Sub-expressoesDeTiposIncompativeisLin26.g](testes/ErroSemantico/NotaEmConceito-Sub-expressoesDeTiposIncompativeisLin26.g).

### 6.5 Negação aritmética com tipo errado

Implementação em [analisa_expr](semantico.c#L96), caso [NO_NEGACAO_ARITMETICA](tipos.h#L8). O operando deve ser `int`. A mensagem é `NEGACAO ARITMETICA REQUER TIPO INT`.

Exemplo G-V1:

```g
principal
{
    c: car;
    escreva -c;
}
```

### 6.6 Operação relacional com tipos diferentes

Implementação em [analisa_expr](semantico.c#L96), casos [NO_IGUAL](tipos.h#L8), [NO_DIFERENTE](tipos.h#L8), [NO_MAIOR](tipos.h#L8), [NO_MENOR](tipos.h#L8), [NO_MAIORIGUAL](tipos.h#L8) e [NO_MENORIGUAL](tipos.h#L8). Se os operandos não têm o mesmo tipo, o erro é `OPERACAO RELACIONAL COM TIPOS DIFERENTES`.

Exemplo G-V1:

```g
principal
{
    a: int;
    b: car;
    escreva a == b;
}
```

### 6.7 Operadores lógicos com tipo errado

Implementação em [analisa_expr](semantico.c#L96), casos [NO_OU](tipos.h#L8) e [NO_E](tipos.h#L8). Os dois operandos precisam ser `int`. A mensagem é `OPERADOR LOGICO REQUER TIPO INT`.

Exemplo G-V1:

```g
principal
{
    c: car;
    escreva c || 1;
}
```

### 6.8 O que a semântica analisa, mas não rejeita explicitamente

[NO_NEGACAO_LOGICA](tipos.h#L8) apenas chama [analisa_expr](semantico.c#L96) no filho e retorna `int`; não há validação explícita do tipo do operando. Isso é um ponto bom de defesa oral, porque mostra que nem toda operação lógica tem a mesma rigidez de checagem no código.

## 7. Geração de Código

A rotina principal é [geraCodigoMIPS](gerador.c#L334). Ela coleta strings, emite o segmento `.data`, gera o `.text`, define `main`, fixa `$fp` com `move $fp, $sp` e, ao final, encerra com syscall de saída.

### 7.1 Estratégia de alocação de variáveis

As regras de uso de registradores estão documentadas em [gerador.h](gerador.h#L1): `$fp` é fixo, `$sp` muda somente em blocos com declarações, `$t0` recebe resultados de expressões e `$t1` é auxiliar.

Em [gera_bloco](gerador.c#L293), quando existe seção de declarações, o código cria um escopo com [criaEscopo](tabsim.c#L17), insere os identificadores com [insereTabela](tabsim.c#L26), calcula `frame_bytes = num_vars * 4` e ajusta `$sp` com `addiu $sp, $sp, -frame_bytes`. Ao sair, [removeEscopo](tabsim.c#L70) devolve o tamanho do frame e o gerador restaura `$sp`.

### 7.2 Avaliação de expressões

[gera_expr](gerador.c#L74) avalia a árvore em pós-ordem. O resultado final sempre fica em `$t0`.

Casos importantes:

- [NO_INTCONST](tipos.h#L8): usa `li $t0, <valor>`.
- [NO_CARCONST](tipos.h#L8): converte o literal com [carconst_valor](gerador.c#L49).
- [NO_IDENTIFICADOR](tipos.h#L8): carrega a variável do offset com `lw $t0, offset($fp)`.
- [NO_ATRIBUICAO](tipos.h#L8): avalia o lado direito e grava em memória com `sw`.

Para operações binárias, o código usa a macro [AVALIA_BINARIO](gerador.c#L107), que empilha o resultado da subexpressão esquerda, avalia a direita e recupera o valor antigo em `$t1`. Isso simplifica a emissão de código sem precisar de registradores temporários extras.

### 7.3 Labels de controle de fluxo

As labels são geradas por [novo_label](gerador.c#L20), que retorna um contador incremental.

- If sem `senao`: usa `__fimse_<id>` em [gerador.c](gerador.c#L266).
- If com `senao`: usa `__senao_<id>` e `__fimse_<id>` em [gerador.c](gerador.c#L255).
- While: usa `__enquanto_cond_<id>` e `__enquanto_fim_<id>` em [gerador.c](gerador.c#L274).

### 7.4 Cadeias de caracteres

As strings literais são coletadas previamente por [coleta_strings](gerador.c#L37) e armazenadas em uma lista própria [StrConst](gerador.c#L11). Depois, [geraCodigoMIPS](gerador.c#L334) emite cada string no segmento `.data` com rótulo `__str_<id>`. Isso evita duplicação e permite imprimir com syscall 4.

## 8. Perguntas prováveis do professor com respostas completas

### 1. Por que o projeto usa AST e não gera código direto no parser?
Porque a AST separa as fases. O parser em [g-v1.y](g-v1.y#L39) só reconhece a estrutura e cria nós com [criaNo](ast.c#L3). A semântica e a geração usam a mesma árvore depois, o que torna o fluxo mais limpo e facilita validação e geração.

### 2. Onde a raiz do programa é definida?
Na produção [Programa : PRINCIPAL Bloco](g-v1.y#L39). A ação salva o bloco em [raiz](g-v1.y#L11), e o `main` chama [analisaSemantico](semantico.c#L190) e [geraCodigoMIPS](gerador.c#L334).

### 3. Como o código representa blocos com e sem declarações?
Em [Bloco](g-v1.y#L52), a versão sem declarações cria [NO_BLOCO](tipos.h#L8) com `filho1 = NULL`. A versão com [VarSection](g-v1.y#L59) coloca as declarações em `filho1` e os comandos em `filho2`.

### 4. Como o compilador detecta redeclaração?
[processa_decl](semantico.c#L19) chama [insereTabela](tabsim.c#L26), que verifica o escopo atual com [pesquisaEscopoAtual](tabsim.c#L45). Se o nome já existir, a inserção falha e a semântica emite erro.

### 5. A tabela de símbolos é uma árvore?
Não. Ela é uma pilha de tabelas hash. Cada escopo é um [TabelaSimbolos](tabsim.h#L18), e os escopos se encadeiam por `anterior`. O hash é usado dentro de cada escopo, com colisões tratadas por lista encadeada.

### 6. Qual é a complexidade da busca?
Em média, [pesquisaEscopoAtual](tabsim.c#L45) é O(1) por escopo. [pesquisaTabela](tabsim.c#L56) pode percorrer vários escopos, então o custo esperado cresce com a profundidade de aninhamento.

### 7. Por que o `-` não é parte do token INTCONST?
Porque o lexer em [g-v1.l](g-v1.l#L66) reconhece apenas dígitos. O sinal menos é tratado pela gramática em [UnExpr : '-' PrimExpr](g-v1.y#L220), o que torna a precedência de unary minus explícita.

### 8. Como o lexer trata comentários multi-linha?
Ele entra no estado `COMENTARIO` em [g-v1.l](g-v1.l#L85), consome conteúdo até encontrar `*/` em [g-v1.l](g-v1.l#L89) e reporta erro se o arquivo terminar antes do fechamento em [g-v1.l](g-v1.l#L97).

### 9. Como strings são tratadas no lexer?
Quando encontra aspas duplas, o lexer entra no estado `CADEIA` em [g-v1.l](g-v1.l#L72), acumula texto em [g-v1.l](g-v1.l#L75) e finaliza ao fechar aspas em [g-v1.l](g-v1.l#L82).

### 10. Como o erro léxico mostra a linha?
Por [yylineno](g-v1.l#L13). A função [erro_lexico](g-v1.l#L7) recebe a linha e imprime uma mensagem padronizada.

### 11. Existe resolução explícita de conflito shift/reduce?
Não há `%left`, `%right` ou `%prec` no arquivo [g-v1.y](g-v1.y#L39). A precedência está embutida na hierarquia dos não-terminais, então o arquivo não depende de declarações globais de precedência.

### 12. Como o dangling-else foi tratado?
A gramática tem duas regras separadas para `SE`: uma com [SENAO](g-v1.y#L155) e outra sem [SENAO](g-v1.y#L153). Como `FIMSE` é obrigatório, o fechamento fica explícito.

### 13. O que [yyerror](g-v1.y#L261) faz?
Imprime a mensagem de erro sintático junto com a linha corrente e encerra o programa com `exit(1)`.

### 14. A semântica permite uso de variável fora do escopo atual?
Não. [pesquisaTabela](tabsim.c#L56) sobe pelos escopos, mas o uso sem declaração ainda gera erro se o símbolo não for encontrado em nenhum deles.

### 15. Como o código decide se um `escreva` imprime int, char ou string?
Em [gera_comando](gerador.c#L202), se o nó é [NO_CADEIACARACTERES](tipos.h#L8), o gerador imprime string com syscall 4. Caso contrário, [gera_expr](gerador.c#L74) devolve o tipo e o gerador escolhe syscall 11 para char ou 1 para int.

### 16. Como as expressões binárias são avaliadas sem perder valores intermediários?
Com a macro [AVALIA_BINARIO](gerador.c#L107). Ela salva o resultado esquerdo na pilha, avalia o direito e recupera o esquerdo em `$t1`.

### 17. Como o código gera labels para if e while?
Usa [novo_label](gerador.c#L20) para garantir unicidade e monta nomes com prefixos como `__senao_`, `__fimse_`, `__enquanto_cond_` e `__enquanto_fim_` nas linhas [gerador.c](gerador.c#L255) e [gerador.c](gerador.c#L274).

### 18. Por que existe uma pré-varredura de strings?
Porque [coleta_strings](gerador.c#L37) evita duplicar literais iguais no segmento `.data` e permite emitir rótulos estáveis antes da geração de instruções.

### 19. Como o offset das variáveis é calculado?
Cada inserção em [insereTabela](tabsim.c#L26) decrementa `offset_corrente` em 4 e grava o valor em `Simbolo.offset` [tabsim.h](tabsim.h#L10). Isso cria um layout simples baseado em stack frame.

### 20. O compilador suporta funções?
Não. O código atual trabalha apenas com programa principal, blocos, comandos e expressões. Isso aparece na gramática de [g-v1.y](g-v1.y#L39) e na estratégia de geração de código em [gerador.c](gerador.c#L334).

### 21. O que acontece se houver erro semântico?
As funções [erro_semantico](semantico.c#L8), [erro_lexico](g-v1.l#L7) e [yyerror](g-v1.y#L261) abortam com `exit(1)`. O projeto para no primeiro erro encontrado.

### 22. Onde a AST é impressa para depuração?
Na função [imprimeArvore](ast.c#L62). Ela é útil para demonstrar a estrutura da árvore e conferir a construção feita pelo parser.

### 23. Por que a tabela de símbolos usa hash e lista encadeada?
Porque o projeto precisa de inserção e busca rápidas, mas também precisa tolerar colisões e escopos aninhados com implementação simples. A solução híbrida é direta e suficiente para a linguagem do trabalho.

### 24. Como o compilador lida com caracteres especiais em constantes de caractere?
O lexer reconhece escapes em [g-v1.l](g-v1.l#L68), e a geração converte o lexema em código ASCII com [carconst_valor](gerador.c#L49).

### 25. O que garante que a geração de código respeite o escopo?
Os mesmos identificadores são inseridos em [gera_bloco](gerador.c#L293) usando [insereTabela](tabsim.c#L26), então o gerador recupera offsets corretos com [pesquisaTabela](tabsim.c#L56).

## 9. Testes executados

Os testes existentes no diretório [testes](testes) estão organizados em três grupos: corretos, erro semântico e erro sintático.

### 9.1 Casos corretos

- [testes/Corretos/fatorial.g](testes/Corretos/fatorial.g): verifica leitura, escrita, laço e atribuição.
- [testes/Corretos/NotaEmConceito.g](testes/Corretos/NotaEmConceito.g): verifica blocos aninhados, decisões e escopos.
- [testes/Corretos/PA.g](testes/Corretos/PA.g): verifica sequência aritmética e expressões.
- [testes/Corretos/Soma.g](testes/Corretos/Soma.g): verifica operações aritméticas básicas.
- [testes/Corretos/SeqOrdenada.g](testes/Corretos/SeqOrdenada.g): verifica comparações e fluxo de controle.

### 9.2 Casos de erro semântico

- [testes/ErroSemantico/fatorial-VariavelNaoDeclaradaLin19.g](testes/ErroSemantico/fatorial-VariavelNaoDeclaradaLin19.g): uso de variável sem declaração.
- [testes/ErroSemantico/fatorial-VariavelRedeclaradaNoMesmoEscopoLin9.g](testes/ErroSemantico/fatorial-VariavelRedeclaradaNoMesmoEscopoLin9.g): redeclaração no mesmo escopo.
- [testes/ErroSemantico/NotaEmConceito-Sub-expressoesDeTiposIncompativeisLin26.g](testes/ErroSemantico/NotaEmConceito-Sub-expressoesDeTiposIncompativeisLin26.g): operação com tipos diferentes.
- [testes/ErroSemantico/NotaEmConceito-VariavelDeTipoIncopativelComExpressaoLin19.g](testes/ErroSemantico/NotaEmConceito-VariavelDeTipoIncopativelComExpressaoLin19.g): atribuição incompatível.
- [testes/ErroSemantico/NotaEmConceito-VariavelNaoDeclaradaNoEsopoAtual.g](testes/ErroSemantico/NotaEmConceito-VariavelNaoDeclaradaNoEsopoAtual.g): variável fora do escopo atual.

### 9.3 Casos de erro sintático

- [testes/ErroSintatico/NotaEmConceito-AbreChavesEspeardoLin18.g](testes/ErroSintatico/NotaEmConceito-AbreChavesEspeardoLin18.g): abre chaves faltando.
- [testes/ErroSintatico/NotaEmConceito-Declarac╠ºa╠âoNaoEnvolvidaEmChavesLin15-17.g](testes/ErroSintatico/NotaEmConceito-Declarac╠ºa╠âoNaoEnvolvidaEmChavesLin15-17.g): declaração fora de bloco esperado.
- [testes/ErroSintatico/NotaEmConceito-FechaChavesEspeardoLin49.g](testes/ErroSintatico/NotaEmConceito-FechaChavesEspeardoLin49.g): fecha chaves faltando.
- [testes/ErroSintatico/NotaEmConceito-FimseFaltanoLIn60.g](testes/ErroSintatico/NotaEmConceito-FimseFaltanoLIn60.g): fimse faltando.
- [testes/ErroSintatico/NotaEmConceitoPonto-e-vrigulaFaltandoLin20.g](testes/ErroSintatico/NotaEmConceitoPonto-e-vrigulaFaltandoLin20.g): ponto e vírgula faltando.

### 9.4 Como reproduzir os testes

O executável final é [g-v1](Makefile#L11), então os testes podem ser executados após `make`.

```bash
make
./g-v1 testes/Corretos/fatorial.g
./g-v1 testes/ErroSemantico/fatorial-VariavelNaoDeclaradaLin19.g
./g-v1 testes/ErroSintatico/NotaEmConceito-AbreChavesEspeardoLin18.g
```

O comportamento esperado é:

- Nos testes corretos, o compilador gera MIPS em stdout sem mensagens de erro.
- Nos testes semânticos, a execução para com uma mensagem de erro semântico e linha correspondente.
- Nos testes sintáticos, [yyerror](g-v1.y#L261) imprime a linha do problema e encerra.

## 10. Resumo

O ponto central da defesa é mostrar que o projeto está organizado em camadas bem separadas: o lexer só reconhece tokens, o parser monta a AST, a semântica usa a pilha de tabelas para validar e o gerador produz MIPS com escopos e frames simples. As decisões mais importantes para justificar são a tabela hash com pilha de escopos, a AST com `filho1/2/3` e `proximo`, e o uso de travessia recursiva tanto na validação quanto na geração.